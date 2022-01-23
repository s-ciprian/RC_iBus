
/* Includes ------------------------------------------------------------------*/
/* STM32F1 LL */
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_bus.h"

/* User code */
#include "digitalOutputs.h"


/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/
/* Map digital outputs name on MCU pins */
#define LED_GEEN_PC13     LL_GPIO_PIN_13


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
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0u, 0u, 0u, 0u, 0u};


    /* GPIO Ports Clock Enable */
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOC);
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA);


    /* Pin PC13: Green LED */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_13;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

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
            LL_GPIO_SetOutputPin(GPIOC, LED_GEEN_PC13);
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
            LL_GPIO_ResetOutputPin(GPIOC, LED_GEEN_PC13);
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
            LL_GPIO_TogglePin(GPIOC, LED_GEEN_PC13);
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
