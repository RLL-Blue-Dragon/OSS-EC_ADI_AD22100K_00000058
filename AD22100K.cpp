// License       : License.txt
// Specifications: Spec-AD22100K.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : AD22100K.cpp
// Reason for change: 01.00.00 : 04/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "AD22100K.h"

#if     iAD22100K_ma == iSMA                            // Simple moving average filter
static float32 AD22100K_sma_buf[iAD22100K_SMA_num];
static sma_f32_t AD22100K_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iAD22100K_SMA_num ,                             // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &AD22100K_sma_buf[0]                            // buffer
};

#elif   iAD22100K_ma == iEMA                            // Exponential moving average filter
static ema_f32_t AD22100K_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iAD22100K_EMA_K                                 // Exponential smoothing factor
};

#elif   iAD22100K_ma == iWMA                            // Weighted moving average filter
static float32 AD22100K_wma_buf[iAD22100K_WMA_num];
static wma_f32_t AD22100K_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iAD22100K_WMA_num ,                             // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iAD22100K_WMA_num * (iAD22100K_WMA_num + 1)/2 , // kn sum
        &AD22100K_wma_buf[0]                            // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_AD22100K =
{
        iAD22100K               ,
        iAD22100K_pin           ,
        iAD22100K_xoff          ,
        iAD22100K_yoff          ,
        iAD22100K_gain          ,
        iAD22100K_max           ,
        iAD22100K_min           ,
        iAD22100K_ma            ,
        
#if     iAD22100K_ma == iSMA                            // Simple moving average filter
        &AD22100K_Phy_SMA       ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iAD22100K_ma == iEMA                            // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &AD22100K_Phy_EMA       ,
        (wma_f32_t*)iDummy_adr
#elif   iAD22100K_ma == iWMA                            // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &AD22100K_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
