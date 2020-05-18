/*
 * Tiny Code Generator for QEMU
 *
 * Copyright (c) 2008 Fabrice Bellard
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * DEF(name, oargs, iargs, cargs, flags)
 */

/* predefined ops */
DEF(discard, 1, 0, 0, TCG_OPF_NOT_PRESENT) /*0*/
DEF(set_label, 0, 0, 1, TCG_OPF_BB_END | TCG_OPF_NOT_PRESENT) /*1*/

/* variable number of parameters */
DEF(call, 0, 0, 3, TCG_OPF_CALL_CLOBBER | TCG_OPF_NOT_PRESENT) /*2*/

DEF(br, 0, 0, 1, TCG_OPF_BB_END) /*3*/

#define IMPL(X) (__builtin_constant_p(X) && (X) <= 0 ? TCG_OPF_NOT_PRESENT : 0)
#if TCG_TARGET_REG_BITS == 32
# define IMPL64  TCG_OPF_64BIT | TCG_OPF_NOT_PRESENT
#else
# define IMPL64  TCG_OPF_64BIT
#endif

DEF(mb, 0, 0, 1, 0) /*4*/

DEF(mov_i32, 1, 1, 0, TCG_OPF_NOT_PRESENT) /*5*/
DEF(movi_i32, 1, 0, 1, TCG_OPF_NOT_PRESENT) /*6*/
DEF(setcond_i32, 1, 2, 1, 0) /*7*/
DEF(movcond_i32, 1, 4, 1, IMPL(TCG_TARGET_HAS_movcond_i32)) /*8*/
/* load/store */
DEF(ld8u_i32, 1, 1, 1, 0) /*9*/
DEF(ld8s_i32, 1, 1, 1, 0) /*10*/
DEF(ld16u_i32, 1, 1, 1, 0) /*11*/
DEF(ld16s_i32, 1, 1, 1, 0) /*12*/
DEF(ld_i32, 1, 1, 1, 0) /*13*/
DEF(st8_i32, 0, 2, 1, 0) /*14*/
DEF(st16_i32, 0, 2, 1, 0) /*15*/
DEF(st_i32, 0, 2, 1, 0) /*16*/
/* arith */
DEF(add_i32, 1, 2, 0, 0) /*17*/
DEF(sub_i32, 1, 2, 0, 0) /*18*/
DEF(mul_i32, 1, 2, 0, 0) /*19*/
DEF(div_i32, 1, 2, 0, IMPL(TCG_TARGET_HAS_div_i32)) /*20*/
DEF(divu_i32, 1, 2, 0, IMPL(TCG_TARGET_HAS_div_i32)) /*21*/
DEF(rem_i32, 1, 2, 0, IMPL(TCG_TARGET_HAS_rem_i32)) /*22*/
DEF(remu_i32, 1, 2, 0, IMPL(TCG_TARGET_HAS_rem_i32)) /*23*/
DEF(div2_i32, 2, 3, 0, IMPL(TCG_TARGET_HAS_div2_i32)) /*24*/
DEF(divu2_i32, 2, 3, 0, IMPL(TCG_TARGET_HAS_div2_i32)) /*25*/
DEF(and_i32, 1, 2, 0, 0) /*26*/
DEF(or_i32, 1, 2, 0, 0) /*27*/
DEF(xor_i32, 1, 2, 0, 0) /*28*/
/* shifts/rotates */
DEF(shl_i32, 1, 2, 0, 0) /*29*/
DEF(shr_i32, 1, 2, 0, 0) /*30*/
DEF(sar_i32, 1, 2, 0, 0) /*31*/
DEF(rotl_i32, 1, 2, 0, IMPL(TCG_TARGET_HAS_rot_i32)) /*32*/
DEF(rotr_i32, 1, 2, 0, IMPL(TCG_TARGET_HAS_rot_i32)) /*33*/
DEF(deposit_i32, 1, 2, 2, IMPL(TCG_TARGET_HAS_deposit_i32)) /*34*/
DEF(extract_i32, 1, 1, 2, IMPL(TCG_TARGET_HAS_extract_i32)) /*35*/
DEF(sextract_i32, 1, 1, 2, IMPL(TCG_TARGET_HAS_sextract_i32)) /*36*/
DEF(extract2_i32, 1, 2, 1, IMPL(TCG_TARGET_HAS_extract2_i32)) /*37*/

DEF(brcond_i32, 0, 2, 2, TCG_OPF_BB_END) /*38*/

DEF(add2_i32, 2, 4, 0, IMPL(TCG_TARGET_HAS_add2_i32)) /*39*/
DEF(sub2_i32, 2, 4, 0, IMPL(TCG_TARGET_HAS_sub2_i32)) /*40*/
DEF(mulu2_i32, 2, 2, 0, IMPL(TCG_TARGET_HAS_mulu2_i32)) /*41*/
DEF(muls2_i32, 2, 2, 0, IMPL(TCG_TARGET_HAS_muls2_i32)) /*42*/
DEF(muluh_i32, 1, 2, 0, IMPL(TCG_TARGET_HAS_muluh_i32)) /*43*/
DEF(mulsh_i32, 1, 2, 0, IMPL(TCG_TARGET_HAS_mulsh_i32)) /*44*/
DEF(brcond2_i32, 0, 4, 2, TCG_OPF_BB_END | IMPL(TCG_TARGET_REG_BITS == 32)) /*45*/
DEF(setcond2_i32, 1, 4, 1, IMPL(TCG_TARGET_REG_BITS == 32)) /*46*/

DEF(ext8s_i32, 1, 1, 0, IMPL(TCG_TARGET_HAS_ext8s_i32)) /*47*/
DEF(ext16s_i32, 1, 1, 0, IMPL(TCG_TARGET_HAS_ext16s_i32)) /*48*/
DEF(ext8u_i32, 1, 1, 0, IMPL(TCG_TARGET_HAS_ext8u_i32)) /*49*/
DEF(ext16u_i32, 1, 1, 0, IMPL(TCG_TARGET_HAS_ext16u_i32)) /*50*/
DEF(bswap16_i32, 1, 1, 0, IMPL(TCG_TARGET_HAS_bswap16_i32)) /*51*/
DEF(bswap32_i32, 1, 1, 0, IMPL(TCG_TARGET_HAS_bswap32_i32)) /*52*/
DEF(not_i32, 1, 1, 0, IMPL(TCG_TARGET_HAS_not_i32)) /*53*/
DEF(neg_i32, 1, 1, 0, IMPL(TCG_TARGET_HAS_neg_i32)) /*54*/
DEF(andc_i32, 1, 2, 0, IMPL(TCG_TARGET_HAS_andc_i32)) /*55*/
DEF(orc_i32, 1, 2, 0, IMPL(TCG_TARGET_HAS_orc_i32)) /*56*/
DEF(eqv_i32, 1, 2, 0, IMPL(TCG_TARGET_HAS_eqv_i32)) /*57*/
DEF(nand_i32, 1, 2, 0, IMPL(TCG_TARGET_HAS_nand_i32)) /*58*/
DEF(nor_i32, 1, 2, 0, IMPL(TCG_TARGET_HAS_nor_i32)) /*59*/
DEF(clz_i32, 1, 2, 0, IMPL(TCG_TARGET_HAS_clz_i32)) /*60*/
DEF(ctz_i32, 1, 2, 0, IMPL(TCG_TARGET_HAS_ctz_i32)) /*61*/
DEF(ctpop_i32, 1, 1, 0, IMPL(TCG_TARGET_HAS_ctpop_i32)) /*62*/

DEF(mov_i64, 1, 1, 0, TCG_OPF_64BIT | TCG_OPF_NOT_PRESENT) /*63*/
DEF(movi_i64, 1, 0, 1, TCG_OPF_64BIT | TCG_OPF_NOT_PRESENT) /*64*/
DEF(setcond_i64, 1, 2, 1, IMPL64) /*65*/
DEF(movcond_i64, 1, 4, 1, IMPL64 | IMPL(TCG_TARGET_HAS_movcond_i64)) /*66*/
/* load/store */
DEF(ld8u_i64, 1, 1, 1, IMPL64) /*67*/
DEF(ld8s_i64, 1, 1, 1, IMPL64) /*68*/
DEF(ld16u_i64, 1, 1, 1, IMPL64) /*69*/
DEF(ld16s_i64, 1, 1, 1, IMPL64) /*70*/
DEF(ld32u_i64, 1, 1, 1, IMPL64) /*71*/
DEF(ld32s_i64, 1, 1, 1, IMPL64) /*72*/
DEF(ld_i64, 1, 1, 1, IMPL64) /*73*/
DEF(st8_i64, 0, 2, 1, IMPL64) /*74*/
DEF(st16_i64, 0, 2, 1, IMPL64) /*75*/
DEF(st32_i64, 0, 2, 1, IMPL64) /*76*/
DEF(st_i64, 0, 2, 1, IMPL64) /*77*/
/* arith */
DEF(add_i64, 1, 2, 0, IMPL64) /*78*/
DEF(sub_i64, 1, 2, 0, IMPL64) /*79*/
DEF(mul_i64, 1, 2, 0, IMPL64) /*80*/
DEF(div_i64, 1, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_div_i64)) /*81*/
DEF(divu_i64, 1, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_div_i64)) /*82*/
DEF(rem_i64, 1, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_rem_i64)) /*83*/
DEF(remu_i64, 1, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_rem_i64)) /*84*/
DEF(div2_i64, 2, 3, 0, IMPL64 | IMPL(TCG_TARGET_HAS_div2_i64)) /*85*/
DEF(divu2_i64, 2, 3, 0, IMPL64 | IMPL(TCG_TARGET_HAS_div2_i64)) /*86*/
DEF(and_i64, 1, 2, 0, IMPL64) /*87*/
DEF(or_i64, 1, 2, 0, IMPL64) /*88*/
DEF(xor_i64, 1, 2, 0, IMPL64) /*89*/
/* shifts/rotates */
DEF(shl_i64, 1, 2, 0, IMPL64) /*90*/
DEF(shr_i64, 1, 2, 0, IMPL64) /*91*/
DEF(sar_i64, 1, 2, 0, IMPL64) /*92*/
DEF(rotl_i64, 1, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_rot_i64)) /*93*/
DEF(rotr_i64, 1, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_rot_i64)) /*94*/
DEF(deposit_i64, 1, 2, 2, IMPL64 | IMPL(TCG_TARGET_HAS_deposit_i64)) /*95*/
DEF(extract_i64, 1, 1, 2, IMPL64 | IMPL(TCG_TARGET_HAS_extract_i64)) /*96*/
DEF(sextract_i64, 1, 1, 2, IMPL64 | IMPL(TCG_TARGET_HAS_sextract_i64)) /*97*/
DEF(extract2_i64, 1, 2, 1, IMPL64 | IMPL(TCG_TARGET_HAS_extract2_i64)) /*98*/

/* size changing ops */
DEF(ext_i32_i64, 1, 1, 0, IMPL64) /*99*/
DEF(extu_i32_i64, 1, 1, 0, IMPL64) /*100*/
DEF(extrl_i64_i32, 1, 1, 0,
    IMPL(TCG_TARGET_HAS_extrl_i64_i32)
    | (TCG_TARGET_REG_BITS == 32 ? TCG_OPF_NOT_PRESENT : 0)) /*101*/
DEF(extrh_i64_i32, 1, 1, 0,
    IMPL(TCG_TARGET_HAS_extrh_i64_i32)
    | (TCG_TARGET_REG_BITS == 32 ? TCG_OPF_NOT_PRESENT : 0)) /*102*/

DEF(brcond_i64, 0, 2, 2, TCG_OPF_BB_END | IMPL64) /*103*/
DEF(ext8s_i64, 1, 1, 0, IMPL64 | IMPL(TCG_TARGET_HAS_ext8s_i64)) /*104*/
DEF(ext16s_i64, 1, 1, 0, IMPL64 | IMPL(TCG_TARGET_HAS_ext16s_i64)) /*105*/
DEF(ext32s_i64, 1, 1, 0, IMPL64 | IMPL(TCG_TARGET_HAS_ext32s_i64)) /*106*/
DEF(ext8u_i64, 1, 1, 0, IMPL64 | IMPL(TCG_TARGET_HAS_ext8u_i64)) /*107*/
DEF(ext16u_i64, 1, 1, 0, IMPL64 | IMPL(TCG_TARGET_HAS_ext16u_i64)) /*108*/
DEF(ext32u_i64, 1, 1, 0, IMPL64 | IMPL(TCG_TARGET_HAS_ext32u_i64)) /*109*/
DEF(bswap16_i64, 1, 1, 0, IMPL64 | IMPL(TCG_TARGET_HAS_bswap16_i64)) /*110*/
DEF(bswap32_i64, 1, 1, 0, IMPL64 | IMPL(TCG_TARGET_HAS_bswap32_i64)) /*111*/
DEF(bswap64_i64, 1, 1, 0, IMPL64 | IMPL(TCG_TARGET_HAS_bswap64_i64)) /*112*/
DEF(not_i64, 1, 1, 0, IMPL64 | IMPL(TCG_TARGET_HAS_not_i64)) /*113*/
DEF(neg_i64, 1, 1, 0, IMPL64 | IMPL(TCG_TARGET_HAS_neg_i64)) /*114*/
DEF(andc_i64, 1, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_andc_i64)) /*115*/
DEF(orc_i64, 1, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_orc_i64)) /*116*/
DEF(eqv_i64, 1, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_eqv_i64)) /*117*/
DEF(nand_i64, 1, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_nand_i64)) /*118*/
DEF(nor_i64, 1, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_nor_i64)) /*119*/
DEF(clz_i64, 1, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_clz_i64)) /*120*/
DEF(ctz_i64, 1, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_ctz_i64)) /*121*/
DEF(ctpop_i64, 1, 1, 0, IMPL64 | IMPL(TCG_TARGET_HAS_ctpop_i64)) /*122*/

DEF(add2_i64, 2, 4, 0, IMPL64 | IMPL(TCG_TARGET_HAS_add2_i64)) /*123*/
DEF(sub2_i64, 2, 4, 0, IMPL64 | IMPL(TCG_TARGET_HAS_sub2_i64)) /*124*/
DEF(mulu2_i64, 2, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_mulu2_i64)) /*125*/
DEF(muls2_i64, 2, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_muls2_i64)) /*126*/
DEF(muluh_i64, 1, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_muluh_i64)) /*127*/
DEF(mulsh_i64, 1, 2, 0, IMPL64 | IMPL(TCG_TARGET_HAS_mulsh_i64)) /*128*/

#define TLADDR_ARGS  (TARGET_LONG_BITS <= TCG_TARGET_REG_BITS ? 1 : 2)
#define DATA64_ARGS  (TCG_TARGET_REG_BITS == 64 ? 1 : 2)

/* QEMU specific */
DEF(insn_start, 0, 0, TLADDR_ARGS * TARGET_INSN_START_WORDS,
    TCG_OPF_NOT_PRESENT) /*129*/
DEF(exit_tb, 0, 0, 1, TCG_OPF_BB_EXIT | TCG_OPF_BB_END) /*130*/
DEF(goto_tb, 0, 0, 1, TCG_OPF_BB_EXIT | TCG_OPF_BB_END) /*131*/
DEF(goto_ptr, 0, 1, 0,
    TCG_OPF_BB_EXIT | TCG_OPF_BB_END | IMPL(TCG_TARGET_HAS_goto_ptr)) /*132*/

DEF(plugin_cb_start, 0, 0, 3, TCG_OPF_NOT_PRESENT) /*133*/
DEF(plugin_cb_end, 0, 0, 0, TCG_OPF_NOT_PRESENT) /*134*/

DEF(qemu_ld_i32, 1, TLADDR_ARGS, 1,
    TCG_OPF_CALL_CLOBBER | TCG_OPF_SIDE_EFFECTS) /*135*/
DEF(qemu_st_i32, 0, TLADDR_ARGS + 1, 1,
    TCG_OPF_CALL_CLOBBER | TCG_OPF_SIDE_EFFECTS) /*136*/
DEF(qemu_ld_i64, DATA64_ARGS, TLADDR_ARGS, 1,
    TCG_OPF_CALL_CLOBBER | TCG_OPF_SIDE_EFFECTS | TCG_OPF_64BIT) /*137*/
DEF(qemu_st_i64, 0, TLADDR_ARGS + DATA64_ARGS, 1,
    TCG_OPF_CALL_CLOBBER | TCG_OPF_SIDE_EFFECTS | TCG_OPF_64BIT)

/* Host vector support.  */

#define IMPLVEC  TCG_OPF_VECTOR | IMPL(TCG_TARGET_MAYBE_vec)

DEF(mov_vec, 1, 1, 0, TCG_OPF_VECTOR | TCG_OPF_NOT_PRESENT)
DEF(dupi_vec, 1, 0, 1, TCG_OPF_VECTOR | TCG_OPF_NOT_PRESENT)

DEF(dup_vec, 1, 1, 0, IMPLVEC)
DEF(dup2_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_REG_BITS == 32))

DEF(ld_vec, 1, 1, 1, IMPLVEC)
DEF(st_vec, 0, 2, 1, IMPLVEC)
DEF(dupm_vec, 1, 1, 1, IMPLVEC)

DEF(add_vec, 1, 2, 0, IMPLVEC)
DEF(sub_vec, 1, 2, 0, IMPLVEC)
DEF(mul_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_mul_vec))
DEF(neg_vec, 1, 1, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_neg_vec))
DEF(abs_vec, 1, 1, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_abs_vec))
DEF(ssadd_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_sat_vec))
DEF(usadd_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_sat_vec))
DEF(sssub_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_sat_vec))
DEF(ussub_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_sat_vec))
DEF(smin_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_minmax_vec))
DEF(umin_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_minmax_vec))
DEF(smax_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_minmax_vec))
DEF(umax_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_minmax_vec))

DEF(and_vec, 1, 2, 0, IMPLVEC)
DEF(or_vec, 1, 2, 0, IMPLVEC)
DEF(xor_vec, 1, 2, 0, IMPLVEC)
DEF(andc_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_andc_vec))
DEF(orc_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_orc_vec))
DEF(not_vec, 1, 1, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_not_vec))

DEF(shli_vec, 1, 1, 1, IMPLVEC | IMPL(TCG_TARGET_HAS_shi_vec))
DEF(shri_vec, 1, 1, 1, IMPLVEC | IMPL(TCG_TARGET_HAS_shi_vec))
DEF(sari_vec, 1, 1, 1, IMPLVEC | IMPL(TCG_TARGET_HAS_shi_vec))

DEF(shls_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_shs_vec))
DEF(shrs_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_shs_vec))
DEF(sars_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_shs_vec))

DEF(shlv_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_shv_vec))
DEF(shrv_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_shv_vec))
DEF(sarv_vec, 1, 2, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_shv_vec))

DEF(cmp_vec, 1, 2, 1, IMPLVEC)

DEF(bitsel_vec, 1, 3, 0, IMPLVEC | IMPL(TCG_TARGET_HAS_bitsel_vec))
DEF(cmpsel_vec, 1, 4, 1, IMPLVEC | IMPL(TCG_TARGET_HAS_cmpsel_vec))

DEF(last_generic, 0, 0, 0, TCG_OPF_NOT_PRESENT)

#if TCG_TARGET_MAYBE_vec
#include "tcg-target.opc.h"
#endif

#undef TLADDR_ARGS
#undef DATA64_ARGS
#undef IMPL
#undef IMPL64
#undef IMPLVEC
#undef DEF
