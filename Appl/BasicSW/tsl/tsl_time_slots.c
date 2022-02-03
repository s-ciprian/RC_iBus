/**
  ******************************************************************************
  * file    tsl_time_slots.c
  * date    19-Jan-2018
  *
  * 30-01-2022 Updated. Try a more simple integration of this module
  *
  ******************************************************************************
  */

#include <stdio.h>
#include "tsl_time_slots.h"
#include <icc_time_slot_i.h>


///////////////////////////////////////////////////////////////////////////////
// Private types definitions
///////////////////////////////////////////////////////////////////////////////
enum TSL_CALL_SEQ
{
    INITIAL_CALL_SEQUENCE = 0,
    NORMAL_CALL_SEQUENCE = 1  
};

enum TSL_NR_OF_CALLS
{
    NR_CALLS_INI_SEQ = 9
};

///////////////////////////////////////////////////////////////////////////////
// Private define
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// Private functions protptype
///////////////////////////////////////////////////////////////////////////////
/* Slot time functions call sequeces.
 * First 9 calls are different from the normal call sequence.
 * See excel documentation for the call sequence. */
static void tsl_call_sequence_first(uint32_t cnt);
static void tsl_call_sequence_normal(uint32_t *cnt);
/* Manage call sequences functions */
static void tsl_Scheduler(void);


///////////////////////////////////////////////////////////////////////////////
// Private variables
///////////////////////////////////////////////////////////////////////////////
/* Time tick counter. Keep timer interrupts. */
volatile uint32_t tslTickCnt;


// ###################################################################################
// Add application functionality on below time slots
// ###################################################################################

//******************************************************************************
// 5 ms time slot time. Call here all functions that need to run at this
// frequency.
// Atention!
// This function is on ISR context 
//******************************************************************************
__attribute__ ((weak)) void tsl_5ms_time_slot(void)
{
   
}

//******************************************************************************
// 10 ms time slot time. Call here all functions that need to run at this
// frequency.
// Atention!
// This time slot calls added with functions called from 5 ms slot time should
// not exceed the base time of 5 ms.
//******************************************************************************
__attribute__ ((weak)) void tsl_10ms_time_slot(void)
{

}

//******************************************************************************
// 20 ms time slot time. Call here all functions that need to run at this
// frequency.
// Atention!
// This time slot calls added with functions called from 5 ms slot time should
// not exceed the base time of 5 ms.
//******************************************************************************
__attribute__ ((weak)) void tsl_20ms_time_slot(void)
{

}

//******************************************************************************
// 40 ms time slot time. Call here all functions that need to run at this
// frequency.
// Atention!
// This time slot calls added with functions called from 5 ms slot time should
// not exceed the base time of 5 ms.
//******************************************************************************
__attribute__ ((weak)) void tsl_40ms_time_slot(void)
{

}

//******************************************************************************
// 80 ms time slot time. Call here all functions that need to run at this
// frequency.
// Atention!
// This time slot calls added with functions called from 5 ms slot time should
// not exceed the base time of 5 ms.
//******************************************************************************
__attribute__ ((weak)) void tsl_80ms_time_slot(void)
{

}

// ###################################################################################
// End of time slots
// ###################################################################################




///////////////////////////////////////////////////////////////////////////////
// Public functions - implementation
///////////////////////////////////////////////////////////////////////////////

//******************************************************************************
// Init function
// Function to be called from main()
// Initialize component data
//******************************************************************************
void tsl_Init(void)
{
	tslTickCnt = 0u;

	/* Initialization function for Application */
	tsl_mainAppl_Init();
}

//******************************************************************************
// tsl_SchedulerRun function
// Function to be called from main()
// Main function of this component, the loop of the system
//******************************************************************************
void tsl_SchedulerRun(void)
{
    /* Scheduler loop */
    while(1)
    {
        /* Local copy of the call_flag */
        uint32_t l_tickCnt = 0;

        /* Local copy of the tick counter. Operation is protected. */
        TSL_GLOBAL_DISABLE_ISR();
        l_tickCnt = tslTickCnt;
        /* Clear counter */
        tslTickCnt = 0u;
        TSL_GLOBAL_ENABLE_ISR();

        if (l_tickCnt)
        {
            /* Run scheduling function */
            tsl_Scheduler();
        }
    }
}

//******************************************************************************
// tsl_TickTime function
// Function to be called from Timer ISR
// Just increment the tick counter in this function
//******************************************************************************
void tsl_OnTickTimeEvent(void)
{
	tslTickCnt++;
}


///////////////////////////////////////////////////////////////////////////////
// Private functions - implementation
///////////////////////////////////////////////////////////////////////////////

//******************************************************************************
// TSL scheduler function
// This function calls time slots function at necessary time.
//******************************************************************************
static void tsl_Scheduler(void)
{
    static enum TSL_CALL_SEQ call_seq = INITIAL_CALL_SEQUENCE;
    static uint32_t call_cnt_seq_1 = 0;
    static uint32_t call_cnt_seq_n = 0;


    /* Call time slot functions */
    if (call_seq == INITIAL_CALL_SEQUENCE) // At the system initialization need to run this call sequence
    {
        call_cnt_seq_1++;
        tsl_call_sequence_first(call_cnt_seq_1);

        if(call_cnt_seq_1 >= NR_CALLS_INI_SEQ)
        {
            call_seq = NORMAL_CALL_SEQUENCE;
        }
    }
    else if (call_seq == NORMAL_CALL_SEQUENCE) // Normal call sequence
    {
        call_cnt_seq_n++;
        tsl_call_sequence_normal(&call_cnt_seq_n);
    }
    else
    {
        //TODO: err_no = ERR_TSL_CALL_SEQUENCE_UNKNOWN;
    }
}

//******************************************************************************
// Initial call sequence for time slot functions.
// This sequence is used only for fist calls. After initial sequece is passed,
// normal sequence is used. 
//******************************************************************************
static void tsl_call_sequence_first(uint32_t cnt)
{
    switch (cnt)
    {
        case 1:
            // no call here
        break;

        case 2:
            tsl_10ms_time_slot();
        break;

        case 3:
            tsl_20ms_time_slot();
        break;

        case 4:
            tsl_10ms_time_slot();
        break;

        case 5:
            tsl_40ms_time_slot();
        break;

        case 6:
            tsl_10ms_time_slot();
        break;

        case 7:
            tsl_20ms_time_slot();
        break;

        case 8:
            tsl_10ms_time_slot();
        break;

        case 9:
            tsl_80ms_time_slot();
        break;

        default:
            //TODO: eh_Err_Set(ERR_TSL_CSF_OUT_OF_RANGE);
        break;
    }
}

//******************************************************************************
// Normal call sequence for time slot functions.
// After initial sequece is passed, normal sequence is used.
//******************************************************************************
static void tsl_call_sequence_normal(uint32_t *cnt)
{
    switch (*cnt)
    {
        case 1:
            tsl_10ms_time_slot();
        break;

        case 2:
            tsl_20ms_time_slot();
        break;

        case 3:
            tsl_10ms_time_slot();
        break;

        case 4:
            tsl_40ms_time_slot();
        break;

        case 5:
            tsl_10ms_time_slot();
        break;

        case 6:
            tsl_20ms_time_slot();
        break;

        case 7:
            tsl_10ms_time_slot();
        break;

        case 8:
            // none
        break;

        case 9:
            tsl_10ms_time_slot();
        break;

        case 10:
            tsl_20ms_time_slot();
        break;

        case 11:
            tsl_10ms_time_slot();
        break;

        case 12:
            tsl_40ms_time_slot();
        break;

        case 13:
            tsl_10ms_time_slot();
        break;

        case 14:
            tsl_20ms_time_slot();
        break;

        case 15:
            tsl_10ms_time_slot();
        break;

        case 16:
            tsl_80ms_time_slot();
            *cnt = 0;
        break;

        default:
            //TODO: eh_Err_Set(ERR_TSL_CSN_OUT_OF_RANGE);
            *cnt = 0;
        break;
    }
}
