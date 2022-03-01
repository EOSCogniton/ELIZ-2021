/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mul_wide_su32.c
 *
 * Code generated for Simulink model 'VCU_TDN'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Mar  1 18:01:29 2022
 */

#include "rtwtypes.h"
#include "mul_wide_su32.h"

void mul_wide_su32(int32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                   *ptrOutBitsLo)
{
  uint32_T outBitsLo;
  uint32_T absIn0;
  uint32_T in0Hi;
  uint32_T in1Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~(uint32_T)in0 + 1U : (uint32_T)in0;
  in0Hi = absIn0 >> 16U;
  absIn0 &= 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = absIn0 * in1Hi;
  absIn0 *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ absIn0;
  if (outBitsLo < absIn0) {
    in1Lo = 1U;
  }

  absIn0 = outBitsLo;
  outBitsLo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (outBitsLo < absIn0) {
    in1Lo++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    in1Lo;
  if ((in1 != 0U) && (in0 < 0)) {
    absIn0 = ~absIn0;
    outBitsLo = ~outBitsLo;
    outBitsLo++;
    if (outBitsLo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = outBitsLo;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
