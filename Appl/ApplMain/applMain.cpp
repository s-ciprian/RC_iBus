/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "tsl_time_slots.h"

/* Application interface */
#include "digitalOutputs.h"
#include "delay.h"
#include "ehErrorHandler.h"
#include "cfgUART.h"


/* stm32duino */
#include "HardwareSerial.h"
#include "HardwareTimer.h"

#include "applMain.h"



/* Private variables ---------------------------------------------------------*/
/* A test counter */
static uint8_t mainCnt;

/* Create a global object of type HardwareSerial. */
HardwareSerial Serial1(PA_10, PA_9);

/* Create a global object of type Hardware Timer */
HardwareTimer TickTmr(TIM4);


/* TickTimer interrupt callback */
static void OnTickTmrExpired()
{
    /* For test, toggle Green LED */
    DO_Toggle(LED_GREEN);
}

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

    /* Set timer interrupt at required time */
    TickTmr.setOverflow(5000, MICROSEC_FORMAT);
    /* Call this function on timer interrupt */
    TickTmr.attachInterrupt(OnTickTmrExpired);
    /* Hardware Timer - Start */
    TickTmr.resume();
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
    Serial1.print("Hello ");
}
