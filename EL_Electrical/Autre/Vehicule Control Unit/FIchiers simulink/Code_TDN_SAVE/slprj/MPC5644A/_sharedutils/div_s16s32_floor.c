/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: div_s16s32_floor.c
 *
 * Code generated for Simulink model 'VCU_TDN'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Mar  1 18:01:29 2022
 */

#include "rtwtypes.h"
#include "div_s16s32_floor.h"

int16_T div_s16s32_floor(int32_T numerator, int32_T denominator)
{
  int16_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = (int16_T)(numerator >= 0 ? 32767 : -32768);

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
      numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
      denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = (int16_T)(quotientNeedsNegation ? (int32_T)(int16_T)-(int32_T)
                         tempAbsQuotient : (int32_T)(int16_T)tempAbsQuotient);
  }

  return quotient;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
