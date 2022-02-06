/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _TSL_SCHEDULER_MCU_TIMER_H
#define _TSL_SCHEDULER_MCU_TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Exported typedef ----------------------------------------------------------*/
typedef void (*tmrExpiredCallback_t)(void);

/* Exported functions --------------------------------------------------------*/
void tslstmr_Init(void);
void tslstmr_RegisterTmrExpireCallback(tmrExpiredCallback_t pTmrExpiredCallback);


#ifdef __cplusplus
}
#endif



#endif /* _TSL_SCHEDULER_MCU_TIMER_H */
