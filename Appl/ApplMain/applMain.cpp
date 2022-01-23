/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/* Application interface */
#include "digitalOutputs.h"
#include "delay.h"

#include "applMain.h"




/* Private variables ---------------------------------------------------------*/
static uint8_t mainCnt;

/* Public Functions  ---------------------------------------------------------*/
/**
  * @brief Main application - initialization function.
  * @retval None
  */
void mainAppl_Init(void)
{
    mainCnt = 0u;

    /* Initialize Digital Outputs */
    DO_Init();
}

/**
  * @brief Main application entry point. 
  * @retval None
  */
void mainAppl_MainRunnable(void)
{
    /* Increment a variable for test */
    mainCnt++;

    /* For test, toggle Green LED */
    DO_Set(LED_GREEN);
    delayMS(500u);
    DO_Clear(LED_GREEN);
    delayMS(200u);

	/* TODO: Add implementation here */
}
