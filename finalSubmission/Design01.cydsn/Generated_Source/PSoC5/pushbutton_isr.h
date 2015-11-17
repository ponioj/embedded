/*******************************************************************************
* File Name: pushbutton_isr.h
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
#if !defined(CY_ISR_pushbutton_isr_H)
#define CY_ISR_pushbutton_isr_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void pushbutton_isr_Start(void);
void pushbutton_isr_StartEx(cyisraddress address);
void pushbutton_isr_Stop(void);

CY_ISR_PROTO(pushbutton_isr_Interrupt);

void pushbutton_isr_SetVector(cyisraddress address);
cyisraddress pushbutton_isr_GetVector(void);

void pushbutton_isr_SetPriority(uint8 priority);
uint8 pushbutton_isr_GetPriority(void);

void pushbutton_isr_Enable(void);
uint8 pushbutton_isr_GetState(void);
void pushbutton_isr_Disable(void);

void pushbutton_isr_SetPending(void);
void pushbutton_isr_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the pushbutton_isr ISR. */
#define pushbutton_isr_INTC_VECTOR            ((reg32 *) pushbutton_isr__INTC_VECT)

/* Address of the pushbutton_isr ISR priority. */
#define pushbutton_isr_INTC_PRIOR             ((reg8 *) pushbutton_isr__INTC_PRIOR_REG)

/* Priority of the pushbutton_isr interrupt. */
#define pushbutton_isr_INTC_PRIOR_NUMBER      pushbutton_isr__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable pushbutton_isr interrupt. */
#define pushbutton_isr_INTC_SET_EN            ((reg32 *) pushbutton_isr__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the pushbutton_isr interrupt. */
#define pushbutton_isr_INTC_CLR_EN            ((reg32 *) pushbutton_isr__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the pushbutton_isr interrupt state to pending. */
#define pushbutton_isr_INTC_SET_PD            ((reg32 *) pushbutton_isr__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the pushbutton_isr interrupt. */
#define pushbutton_isr_INTC_CLR_PD            ((reg32 *) pushbutton_isr__INTC_CLR_PD_REG)


#endif /* CY_ISR_pushbutton_isr_H */


/* [] END OF FILE */
