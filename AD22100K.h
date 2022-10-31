// License       : License.txt
// Specifications: Spec-AD22100K.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : AD22100K.h
// Reason for change: 01.00.00 : 04/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __AD22100K_H__
#define __AD22100K_H__

#include "user_define.h"

// Components number
#define iAD22100K               107U                    // Analog devices AD22100K

// AD22100K System Parts definitions
#define iAD22100K_xoff          ( 1.375F*(iADC_vdd/5.0F) )      // X offset [V]
#define iAD22100K_yoff          0.0F                    // Y offset [degree celsius]
#define iAD22100K_gain          ( 0.0225F*(iADC_vdd/5.0F) )     // Gain [V/degree celsius]
#define iAD22100K_max           100.0F                  // Temperature Max [degree celsius]
#define iAD22100K_min           0.0F                    // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_AD22100K;

#endif /*__AD22100K_H__*/
