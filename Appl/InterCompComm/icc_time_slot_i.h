/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef ICC_TIME_SLOT_I_H
#define ICC_TIME_SLOT_I_H

#ifdef __cplusplus
extern "C" {
#endif



/* Required interface */

extern void ms_disable_irq(void);
#define TSL_GLOBAL_DISABLE_ISR() ms_disable_irq()

extern void ms_enable_irq(void);
#define TSL_GLOBAL_ENABLE_ISR() ms_enable_irq()


extern void mainAppl_Init(void);
#define tsl_mainAppl_Init() mainAppl_Init()


#ifdef __cplusplus
}
#endif


#endif /* ICC_TIME_SLOT_I_H */
