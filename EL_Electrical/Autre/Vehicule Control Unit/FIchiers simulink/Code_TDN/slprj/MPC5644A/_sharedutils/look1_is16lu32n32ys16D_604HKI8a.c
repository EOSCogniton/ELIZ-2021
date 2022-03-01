/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: look1_is16lu32n32ys16D_604HKI8a.c
 *
 * Code generated for Simulink model 'VCU_TDN'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Mar  1 18:01:29 2022
 */

#include "rtwtypes.h"
#include "div_nzp_repeat_u32.h"
#include "mul_ssu32_loSR.h"
#include "look1_is16lu32n32ys16D_604HKI8a.h"

int16_T look1_is16lu32n32ys16D_604HKI8a(int16_T u0, const int16_T bp0[], const
  int16_T table[], uint32_T maxIndex)
{
  uint32_T frac;
  int32_T finalAccum;
  uint32_T iRght;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Canonical function name: look1_is16lu32n32ys16Ds32Is32n15_binlcass
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    frac = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[frac]) {
        iRght = frac;
      } else {
        iLeft = frac;
      }

      frac = (iRght + iLeft) >> 1U;
    }

    frac = div_nzp_repeat_u32((uint32_T)(uint16_T)(u0 - bp0[iLeft]) << 16,
      (uint16_T)(bp0[iLeft + 1U] - bp0[iLeft]), 16U);
  } else {
    iLeft = maxIndex;
    frac = 0U;
  }

  /* Column-major Interpolation 1-D
     Canonical function name: intrp1d_s16p15s32s32u32u32n32la_s
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (iLeft == maxIndex) {
    finalAccum = table[iLeft] << 15;
  } else {
    finalAccum = mul_ssu32_loSR(table[iLeft + 1U] - table[iLeft], frac, 17U) +
      (table[iLeft] << 15);
  }

  finalAccum >>= 15;
  if (finalAccum > 32767) {
    finalAccum = 32767;
  } else {
    if (finalAccum < -32768) {
      finalAccum = -32768;
    }
  }

  return (int16_T)finalAccum;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
