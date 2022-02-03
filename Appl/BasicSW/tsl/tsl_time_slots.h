/**
  ******************************************************************************
  * file    tsl_time_slots.h
  * date    04-April-2017
  *
  * 30-01-2022 Updated. Try a more simple integration of this module
  *
  ******************************************************************************
  */

#ifndef __TSL_TIME_SLOTS_H
#define __TSL_TIME_SLOTS_H

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
// Types definitions
///////////////////////////////////////////////////////////////////////////////
typedef uint32_t base_type_t;

///////////////////////////////////////////////////////////////////////////////
// Public functions
///////////////////////////////////////////////////////////////////////////////
/* Interfaces needed by this module,  */
void tsl_Init(void);
void tsl_OnTickTimeEvent(void);
void tsl_SchedulerRun(void);

/* Recurrent functions - must be implemented by application */
void tsl_5ms_time_slot(void);
void tsl_10ms_time_slot(void);
void tsl_20ms_time_slot(void);
void tsl_40ms_time_slot(void);
void tsl_80ms_time_slot(void);

#ifdef __cplusplus
}
#endif

#endif /* __TSL_TIME_SLOTS_H */
