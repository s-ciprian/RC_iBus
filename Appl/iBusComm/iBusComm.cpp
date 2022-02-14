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

/* ===== Debug variables ===== */
/* Counter - number of polling for sensor existence. Copy of IBusBM Sensor couner */
volatile uint8_t IBusSensor_cnt_poll;
/* Counter - number of polling for sensor value */
volatile uint8_t IBusSensor_cnt_sensor;

/* Variables used to simulate values from sensors */
int16_t dbgSensorSpeedVal;
int16_t dbgSensorTempVal;


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

    /* Test values to simulate some sensors */
    dbgSensorSpeedVal = 1000;
    dbgSensorTempVal = 25;

    /* Initialize debug counters  */
    IBusSensor_cnt_poll = 0;
    IBusSensor_cnt_sensor = 0;
}

/**
  * @brief IBus Communication module - cyclic function.
  *        Needs to be called by Scheduler
  * @retval None
  */
void ibcomm_MainRunnable(void)
{
    /* ===== Test IBusSensor ===== */

    /* Send RPM value on IBus */
    IBusSensor.setSensorMeasurement(IBUSS_RPM, dbgSensorSpeedVal);

    /* Send temperature (in 0.1 degrees) on IBus */
    IBusSensor.setSensorMeasurement(IBUSS_TEMP, dbgSensorTempVal);

    /* = Copy polling counters from IBusSensor object = */
    /* Number of polling for sensor existence */
    IBusSensor_cnt_poll = IBusSensor.cnt_poll;
    /* Number of polling for sensor value */
    IBusSensor_cnt_sensor = IBusSensor.cnt_sensor;
}
