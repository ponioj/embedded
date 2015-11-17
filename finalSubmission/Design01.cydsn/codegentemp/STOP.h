/*******************************************************************************
* File Name: STOP.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_STOP_H)
#define CY_ISR_STOP_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void STOP_Start(void);
void STOP_StartEx(cyisraddress address);
void STOP_Stop(void);

CY_ISR_PROTO(STOP_Interrupt);

void STOP_SetVector(cyisraddress address);
cyisraddress STOP_GetVector(void);

void STOP_SetPriority(uint8 priority);
uint8 STOP_GetPriority(void);

void STOP_Enable(void);
uint8 STOP_GetState(void);
void STOP_Disable(void);

void STOP_SetPending(void);
void STOP_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the STOP ISR. */
#define STOP_INTC_VECTOR            ((reg32 *) STOP__INTC_VECT)

/* Address of the STOP ISR priority. */
#define STOP_INTC_PRIOR             ((reg8 *) STOP__INTC_PRIOR_REG)

/* Priority of the STOP interrupt. */
#define STOP_INTC_PRIOR_NUMBER      STOP__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable STOP interrupt. */
#define STOP_INTC_SET_EN            ((reg32 *) STOP__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the STOP interrupt. */
#define STOP_INTC_CLR_EN            ((reg32 *) STOP__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the STOP interrupt state to pending. */
#define STOP_INTC_SET_PD            ((reg32 *) STOP__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the STOP interrupt. */
#define STOP_INTC_CLR_PD            ((reg32 *) STOP__INTC_CLR_PD_REG)


#endif /* CY_ISR_STOP_H */


/* [] END OF FILE */
