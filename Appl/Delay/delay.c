
/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_ll_utils.h"

/**
  * @brief  FUNCTION: provides delay (in milliseconds) based on STM32 system function
  * @param  Delay: specifies the delay time length, in milliseconds.
  * @retval None
  */
void delayMS(uint32_t delay)
{
    /* call system provided function */
    LL_mDelay(delay);
}
