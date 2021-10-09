# llvm-qemu
Using LLVM to optimize Qemu's binary translation mechanism. Currently only supports x86_64 program execution on aarch64. Performance has been significantly improved. Integer Index under nbench test increased from 0.5438 to 3.1150.

## 实现要点
* 使用LLVM IR(intermedaite representation) 代替TCG code作中间代码
* 在函数`llvm_gen_code`中， 实现了将解析机器码所得到的tcg ops逐条翻译为LLVM IR指令, 并用这些指令构建一个LLVM Function. [tcg/tcg.c](https://github.com/XiangfanLi/llvm-qemu/blob/52fb7d37530a2048d0a8dd110bd5c626b85a4217/tcg/tcg.c#L4022)
  ```c++
  // transfer TCG intermediate code to LLVM IR (intermediate representation)
  int llvm_gen_code(CPUArchState *env, TCGContext *s, TranslationBlock *tb)
  {
     ......
     ......
     QTAILQ_FOREACH(op, &s->ops, link)
     {
       ......
       ......
       switch(opc)
          {
              case INDEX_op_mov_i32:
              {
                  arg0 = temp_idx(arg_temp(op->args[0]));
                  arg1 = temp_idx(arg_temp(op->args[1]));
                  LLVMValueRef Load = LLVMBuildTrunc(IR, LLVMBuildLoad2(IR, temp_val_types[arg1], llvm_temps[arg1], ""), LLVMInt32TypeInContext(llvm_ctx), "");
                  LLVMValueRef Result = LLVMBuildZExt(IR, Load, temp_val_types[arg0], "");
                  LLVMBuildStore(IR, Result, llvm_temps[arg0]);
                  break;
              }
              case INDEX_op_mov_i64:
              {
                  arg0 = temp_idx(arg_temp(op->args[0]));
                  arg1 = temp_idx(arg_temp(op->args[1]));
                  LLVMValueRef Load = LLVMBuildLoad2(IR, temp_val_types[arg1], llvm_temps[arg1], "");
                  LLVMBuildStore(IR, LLVMBuildZExtOrBitCast(IR, Load, temp_val_types[arg0], ""), llvm_temps[arg0]);
                  break;
              }
  ```
* 往后将该地址作为普通函数调用, 即可直接执行其中的机器代码 [accel/tcg/cpu-exec.c](https://github.com/XiangfanLi/llvm-qemu/blob/52fb7d37530a2048d0a8dd110bd5c626b85a4217/accel/tcg/cpu-exec.c#L182)
```c++
for(;;) {
        LLVMValueRef func_ptr = curr_tb->func_ptr;
        curr_tb->exec_cnt++;
        if (curr_tb->exec_cnt > 5) { // use JITCompiler
            if (curr_tb->p == NULL) {
                curr_tb->p = LLVMGetPointerToGlobal(EE, func_ptr);
            }
            // execute machine code directly
            ret = curr_tb->p();
        } 
```
* 如果用函数`LLVMRunFunction`, 会对LLVM中间码逐条解释执行, 效率较低:
```c++
else {
            if (!last_tb_exec_safe_return) {
                // The last TB may not be returned by the return statement during the execution process. At this time, the Interpreter needs to be re-initialized.
                reset_interpreter(env);
            }
            last_tb_exec_safe_return = false;
            LLVMGenericValueRef RetValue = LLVMRunFunction(Interpreter, func_ptr, 0, Args);
            last_tb_exec_safe_return = true;
            ret = LLVMGenericValueToInt(RetValue, 0);
        }
```
* 后端有两种代码执行方式: 1) 使用LLVM JIT(Just-in-time)编译器对将IR进行优化并编译为本地机器码执行 2)使用LLVM IR解释器对IR解释执行。机器码的运行速度约为原版Qemu后端解释执行TCG code的五倍, 但在第一次生成机器码时需要较大的优化和编译开销; IR解释器的代码执行效率只有执行机器码的约千分之一。
## 环境准备
* 目前只实现了用户态下的优化工作, 只在64位ARM架构(AArch64)机器， Linux系统上测试运行过x86_64程序
* 先确保能正常运行Qemu5.0.0
* 本项目使用了llvm-c(9.0.0)的API，需要自行下载并配置llvm(9.0.0以后版本). 


## 编译命令
在项目的主路径下, 执行下面的命令
```
$ ./configure --target-list=x86_64-linux-user --enable-tcg-interpreter
$ make
```
执行上述命令后, 将在./x86_64-linux-user 下得到可执行程序qemu-x86_64
