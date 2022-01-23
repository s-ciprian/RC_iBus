/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DIGITAL_OUTPUTS_H
#define DIGITAL_OUTPUTS_H

#ifdef __cplusplus
extern "C" {
#endif

/* This configuration is for Blue Pill board */

/* Define digital outputs list for this project.
 * NOTE: It is advisable to extend this list instead of use more direct control of the
 * MCU pins in the application (higher levels) */
typedef enum
{
    LED_GREEN = 0,                   /* Green LED on  */
    DO_PIN_LIST_END              /* END of DO pins - keep it at the end */
} E_DO_PIN_LIST;


/* Interface used to control Digital Outputs defined for this project
 * NOTE: It is advisable to extend the set of below interfaces, if needed, instead of using
 * MCU vendor provided interface in the higher levels (Application) */

/* Initialization function for this module  */
void DO_Init(void);
/* Set a digital Output */
void DO_Set(E_DO_PIN_LIST digitalOutput);
/* Reset a digital Output*/
void DO_Clear(E_DO_PIN_LIST digitalOutput);
/* Toggle a digital Output */
void DO_Toggle(E_DO_PIN_LIST digitalOutput);


#ifdef __cplusplus
}
#endif

#endif /* DIGITAL_OUTPUTS_H */
