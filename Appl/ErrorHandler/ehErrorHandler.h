/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef EH_ERROR_HANDLER_H
#define EH_ERROR_HANDLER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Public typedef ------------------------------------------------------------*/
typedef enum
{
    MCU_NO_ERROR            = 0,
    MCU_ERR_CODE_100        = 100,
    MCU_ERR_CODE_101        = 101,
    MCU_END_OF_ERROR_CODES
} E_EH_MCU_ERROR_CODE;

/* Public interface */
/* Initialization function for Error Handler module  */
void eh_Init(void);
void eh_SetMcuError(E_EH_MCU_ERROR_CODE errCode);

#ifdef __cplusplus
}
#endif

#endif /* EH_ERROR_HANDLER_H */
