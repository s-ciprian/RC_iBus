
/* Includes ------------------------------------------------------------------*/
#include "HardwareTimer.h"

#include "tsl_Scheduler_McuTimer.h"

/* Private define ------------------------------------------------------------*/
/* Tick time period in microseconds */
#define TSL_SCHEDULER_TIME_TICK 5000u


/* Private variables ---------------------------------------------------------*/
/* Create a global object of type Hardware Timer */
static HardwareTimer TickTmr(TIM4);

/* Hold a pointer to the user callback (to be called when the timer expires) */
tmrExpiredCallback_t pFncTmrExp = NULL;


/* Private Functions DEFINITION ----------------------------------------------*/
static void OnTickTmrExpired();


/* Public Functions IMPLEMENTATION -------------------------------------------*/
/**
  * @brief  Initialization function for this module
  * @param  None
  * @retval None
  */
void tslstmr_Init(void)
{
    /* Initialize callback function pointer */
    pFncTmrExp = NULL;

    /* ----- Initialize TSL Scheduler timer ----- */
    /* Set timer interrupt at required time */
    TickTmr.setOverflow(TSL_SCHEDULER_TIME_TICK, MICROSEC_FORMAT);
    /* Call this function on timer interrupt */
    TickTmr.attachInterrupt(OnTickTmrExpired);
    /* Hardware Timer - Start */
    TickTmr.resume();
}

/**
  * @brief  Function used to register a user callback to be called when the timer expires
  * @param  pTmrExpiredCallback: function that will be called when timer expires
  * @retval None
  */
void tslstmr_RegisterTmrExpireCallback(tmrExpiredCallback_t pTmrExpiredCallback)
{
    /* Copy address of the user function into local variable */
    pFncTmrExp = pTmrExpiredCallback;
}


/* Private Functions IMPLEMENTATION ------------------------------------------*/
/**
  * @brief  TickTimer interrupt callback - this function is called by Hardware Timer module
  * @param  None
  * @retval None
  */
static void OnTickTmrExpired()
{
    /* Call user function */
    if (pFncTmrExp != NULL)
    {
        pFncTmrExp();
    }
}

