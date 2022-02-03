
#include "stdint.h"
#include "stm32f1xx_hal.h"

#include "ms_mcu_specific.h"


///////////////////////////////////////////////////////////////////////////////
// Types definitions
///////////////////////////////////////////////////////////////////////////////
typedef uint32_t base_type_t;


///////////////////////////////////////////////////////////////////////////////
// Global variables
///////////////////////////////////////////////////////////////////////////////
/* Count how many times interrupts has been disabled. */
static volatile base_type_t i_cnt;


//******************************************************************************
// Disable all interrupts
//******************************************************************************
void ms_disable_irq(void)
{
    __disable_irq();
    /* Increment interrupts disabled counter */
    i_cnt++;
}

//******************************************************************************
// Enable all interrupts
//******************************************************************************
void ms_enable_irq(void)
{
    /* Decrement interrupts disable counter */
    if (i_cnt)
    {
        i_cnt--;
    }

    if (i_cnt == 0)
    {
        __enable_irq();
    }
}
