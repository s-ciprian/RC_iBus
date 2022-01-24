
/* Includes ------------------------------------------------------------------*/
/* STM32 includes */
#include "stm32f1xx_hal.h"

#include "ehErrorHandler.h"


/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
static E_EH_MCU_ERROR_CODE ehMcuErrorCode;

/* Private function prototypes -----------------------------------------------*/


/* Public Functions - IMPLEMENTATION -----------------------------------------*/
/**
  * @brief Initialization function of the Error Handler module
  * @param None
  * @retval None
  */
void eh_Init(void)
{
    ehMcuErrorCode = MCU_NO_ERROR;
}

/**
  * @brief Set MCU related errors, for example during initialization phase
  * @param None
  * @retval None
  */
void eh_SetMcuError(E_EH_MCU_ERROR_CODE errCode)
{
    /* Store error code */
    ehMcuErrorCode = errCode;

    /* Stop interrupts */
    __disable_irq();

    /* Stop code execution */
    while (1)
    {
    }
}

/* Private Functions - IMPLEMENTATION ----------------------------------------*/
