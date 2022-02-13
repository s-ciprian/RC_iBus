/* Includes ------------------------------------------------------------------*/
/* stm32duino */
#include "HardwareSerial.h"
#include "IBusBM.h"

#include "iBusComm.h"


/* Private variables ---------------------------------------------------------*/
/* Create an object of type HardwareSerial - used by IBusSensor object */
static HardwareSerial IBusSensorSerial(PA_10, PA_9);
/* Create an object IBus for Sensors */
IBusBM IBusSensor;

/* Public Functions (implementation) -----------------------------------------*/

/**
  * @brief IBus Communication module - initialization function.
  * @retval None
  */
void ibcomm_Init(void)
{
    /* Initialize Serial1 object. Use needed baud rate */
    IBusSensorSerial.begin(115200);

    /* Initialize IBusServo object. The UART port to be used by
     * this object is provided. */
    IBusSensor.begin(IBusSensorSerial, TIM1);

    /* Add 2 sensors */
    IBusSensor.addSensor(IBUSS_RPM);
    IBusSensor.addSensor(IBUSS_TEMP);
}

/**
  * @brief IBus Communication module - cyclic function.
  *        Needs to be called by Scheduler
  * @retval None
  */
void ibcomm_MainRunnable(void)
{

}
