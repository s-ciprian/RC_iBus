/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "tsl_time_slots.h"

/* Application interface */
#include "digitalOutputs.h"
#include "delay.h"
#include "ehErrorHandler.h"
#include "cfgUART.h"
#include "iBusComm.h"

#include "tsl_Scheduler_McuTimer.h"

#include "applMain.h"



/* Private variables ---------------------------------------------------------*/
/* A test counter */
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

    /* Error Handler initialization */
    eh_Init();

    /* UART configuration - initialization function */
    cfgUART_Init();

    /* Timer for TSL Scheduler initialization function */
    tslstmr_Init();

    /* IBus communication module - initialization function */
    ibcomm_Init();
}

/**
  * @brief Main application entry point. 
  * @retval None
  */
//void mainAppl_MainRunnable(void)
//{
//    /* For test, toggle Green LED */
//    DO_Set(LED_GREEN);
//    delayMS(500u);
//    DO_Clear(LED_GREEN);
//    delayMS(200u);
//}

//******************************************************************************
// 5 ms time slot time. Call here all functions that need to run at this
// frequency.
// Atention!
// This function is on ISR context
//******************************************************************************
void tsl_5ms_time_slot(void)
{

}

//******************************************************************************
// 10 ms time slot time. Call here all functions that need to run at this
// frequency.
// Atention!
// This time slot calls added with functions called from 5 ms slot time should
// not exceed the base time of 5 ms.
//******************************************************************************
void tsl_10ms_time_slot(void)
{
    /* Increment a variable for test */
    mainCnt++;

    /* IBus Communication module - main function */
    ibcomm_MainRunnable();
}

//******************************************************************************
// 20 ms time slot time. Call here all functions that need to run at this
// frequency.
// Atention!
// This time slot calls added with functions called from 5 ms slot time should
// not exceed the base time of 5 ms.
//******************************************************************************
void tsl_20ms_time_slot(void)
{

}

//******************************************************************************
// 40 ms time slot time. Call here all functions that need to run at this
// frequency.
// Atention!
// This time slot calls added with functions called from 5 ms slot time should
// not exceed the base time of 5 ms.
//******************************************************************************
void tsl_40ms_time_slot(void)
{

}

//******************************************************************************
// 80 ms time slot time. Call here all functions that need to run at this
// frequency.
// Atention!
// This time slot calls added with functions called from 5 ms slot time should
// not exceed the base time of 5 ms.
//******************************************************************************
void tsl_80ms_time_slot(void)
{
    /* For test, toggle Green LED */
    DO_Toggle(LED_GREEN);

    /* Send a string on serial port */
    //Serial1.print("Hello ");
}
