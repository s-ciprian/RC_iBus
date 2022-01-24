
/* Includes ------------------------------------------------------------------*/
/* STM32 includes */
#include "stm32f1xx_hal.h"

/* Application interface  */
#include "ehErrorHandler.h"

#include "cfgUART.h"


/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;


/* Private function prototypes -----------------------------------------------*/
static void cfgUART1_Init(void);
static void cfgUART2_Init(void);

/* Public Functions - IMPLEMENTATION -----------------------------------------*/
/**
  * @brief Initialize and configure the UART modules used by the application
  * @param None
  * @retval None
  */
void cfgUART_Init(void)
{
    /* Call initialization functions for UARTs */
    cfgUART1_Init();
    cfgUART2_Init();
}

/* Private Functions - IMPLEMENTATION ----------------------------------------*/
/**
  * @brief UART1 Initialization Function
  * @param None
  * @retval None
  */
static void cfgUART1_Init(void)
{
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&huart1) != HAL_OK)
    {
        eh_SetMcuError(MCU_ERR_CODE_100);
    }
}

/**
  * @brief UART2 Initialization Function
  * @param None
  * @retval None
  */
static void cfgUART2_Init(void)
{
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
        eh_SetMcuError(MCU_ERR_CODE_101);
    }
}
