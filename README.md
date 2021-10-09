# llvm-qemu
Using LLVM to optimize Qemu's binary translation mechanism. Currently only supports x86_64 program execution on aarch64. Performance has been significantly improved. Integer Index under nbench test increased from 0.5438 to 3.1150.

## 实现要点
* 使用LLVM IR(intermedaite representation) 代替TCG code作中间代码
  在函数`llvm_gen_code`中， 实现了将解析机器码所得到的tcg op 翻译为LLVM IR, 翻译得到对应的LLVMIR指令, 构建LLVM Function:
  ```
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
