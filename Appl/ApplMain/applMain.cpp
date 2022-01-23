/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

#include "applMain.h"

/* TODO: Move this in BoardConfig */
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_utils.h"


/* Private variables ---------------------------------------------------------*/
static uint8_t mainCnt;

/**
  * @brief Main application - initialization function.
  * @retval None
  */
void mainAppl_Init(void)
{
    mainCnt = 0u;

    /* TODO: Add implementation here */
}

/**
  * @brief Main application entry point. 
  * @retval None
  */
void mainAppl_MainRunnable(void)
{
    /* Increment a variable for test */
    mainCnt++;

    /* For test, toggle LED connected on PC13 pin.
     * LL functions are used for this. */
    LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_13);
    LL_mDelay(500u);
    LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_13);
    LL_mDelay(500u);

	/* TODO: Add implementation here */
}
