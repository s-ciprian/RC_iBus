
/* Includes ------------------------------------------------------------------*/
/* STM32F1 LL */
#include "stm32f1xx_hal.h"

/* User code */
#include "digitalOutputs.h"


/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/
/* Map digital outputs name on MCU pins */
#define LED_GREEN_PIN        GPIO_PIN_13
#define LED_GREEN_PORT       GPIOC

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static void do_DigitalOutputs_DefaultState(void);


/* Public Functions  ---------------------------------------------------------*/
/**
  * @brief  FUNCTION: Initialization function for digital outputs module
  * @retval none.
  */
void DO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0u, 0u, 0u, 0u};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();


    /*Configure GPIO pin : PC13 */
    GPIO_InitStruct.Pin = LED_GREEN_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_GREEN_PORT, &GPIO_InitStruct);

    /* Set default state for digital outputs */
    do_DigitalOutputs_DefaultState();
}

/**
  * @brief  FUNCTION: Set the MCU output pin
  * @retval none.
  */
void DO_Set(E_DO_PIN_LIST digitalOutput)
{
    /* Select digital output to be controlled */
    switch (digitalOutput)
    {
        /* Green LED */
        case LED_GREEN:
            HAL_GPIO_WritePin(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_PIN_SET);
            break;

        default:
            /* TODO: Set an error */
            break;
    }
}

/**
  * @brief  FUNCTION: Reset the MCU output pin
  * @retval none.
  */
void DO_Clear(E_DO_PIN_LIST digitalOutput)
{
    /* Select digital output to be controlled */
    switch (digitalOutput)
    {
        /* Green LED */
        case LED_GREEN:
            HAL_GPIO_WritePin(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_PIN_RESET);
            break;

        default:
            /* TODO: Set an error */
            break;
    }
}

/**
  * @brief  FUNCTION: Toggle the MCU output pin
  * @retval none.
  */
void DO_Toggle(E_DO_PIN_LIST digitalOutput)
{
    /* Select digital output to be controlled */
    switch (digitalOutput)
    {
        /* Green LED */
        case LED_GREEN:
            HAL_GPIO_TogglePin(LED_GREEN_PORT, LED_GREEN_PIN);
            break;

        default:
            /* TODO: Set an error */
            break;
    }
}

/* Private Functions  ---------------------------------------------------------*/
/**
  * @brief PRIVATE FUNCTION: Set default state for digital outputs
  * @retval none.
  */
static void do_DigitalOutputs_DefaultState(void)
{
    /* Green LED output */
    DO_Clear(LED_GREEN);
}
