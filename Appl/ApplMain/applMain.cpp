/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/* Application interface */
#include "digitalOutputs.h"
#include "delay.h"
#include "ehErrorHandler.h"
#include "cfgUART.h"

/* stm32duino */
#include "HardwareSerial.h"

#include "applMain.h"



/* Private variables ---------------------------------------------------------*/
/* A test counter */
static uint8_t mainCnt;

/* Create a global object of type HardwareSerial. */
HardwareSerial Serial1(PA_10, PA_9);


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

    /* Error Handler initialization */
    eh_Init();

    /* UART configuration - initialization function */
    cfgUART_Init();

    /* Call begin() method of the serial object with needed baud rate */
    Serial1.begin(115200);
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

    /* Send a string on serial port */
    Serial1.print("Hello ");

	/* TODO: Add implementation here */
}
