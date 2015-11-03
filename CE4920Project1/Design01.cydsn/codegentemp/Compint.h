/*******************************************************************************
* File Name: Compint.h
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
#if !defined(CY_ISR_Compint_H)
#define CY_ISR_Compint_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Compint_Start(void);
void Compint_StartEx(cyisraddress address);
void Compint_Stop(void);

CY_ISR_PROTO(Compint_Interrupt);

void Compint_SetVector(cyisraddress address);
cyisraddress Compint_GetVector(void);

void Compint_SetPriority(uint8 priority);
uint8 Compint_GetPriority(void);

void Compint_Enable(void);
uint8 Compint_GetState(void);
void Compint_Disable(void);

void Compint_SetPending(void);
void Compint_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Compint ISR. */
#define Compint_INTC_VECTOR            ((reg32 *) Compint__INTC_VECT)

/* Address of the Compint ISR priority. */
#define Compint_INTC_PRIOR             ((reg8 *) Compint__INTC_PRIOR_REG)

/* Priority of the Compint interrupt. */
#define Compint_INTC_PRIOR_NUMBER      Compint__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Compint interrupt. */
#define Compint_INTC_SET_EN            ((reg32 *) Compint__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Compint interrupt. */
#define Compint_INTC_CLR_EN            ((reg32 *) Compint__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Compint interrupt state to pending. */
#define Compint_INTC_SET_PD            ((reg32 *) Compint__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Compint interrupt. */
#define Compint_INTC_CLR_PD            ((reg32 *) Compint__INTC_CLR_PD_REG)


#endif /* CY_ISR_Compint_H */


/* [] END OF FILE */
