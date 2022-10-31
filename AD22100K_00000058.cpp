// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : AD22100K_00000058.cpp
// BSL              : 00000058
// Model number     : Analog devices AD22100K
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 04/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "AD22100K.h"

AnalogIn AD22100K_adc( iAD22100K_pin , iVref );         // AnalogIn object

// Main Function
pp2ap_adc_t AD22100K_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( AD22100K_adc , tbl_AD22100K );
        return( res );
}
