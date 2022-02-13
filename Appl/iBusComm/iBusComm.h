/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef I_BUS_COMM_H
#define I_BUS_COMM_H

#ifdef __cplusplus
extern "C" {
#endif


/* ===== Required interface ===== */

/* Initialization function */
void ibcomm_Init(void);
/* IBus Communication main function */
void ibcomm_MainRunnable(void);

#ifdef __cplusplus
}
#endif


#endif /* I_BUS_COMM_H */
