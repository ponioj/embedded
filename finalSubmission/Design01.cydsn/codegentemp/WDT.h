/*******************************************************************************
* File Name: WDT.h
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
#if !defined(CY_ISR_WDT_H)
#define CY_ISR_WDT_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void WDT_Start(void);
void WDT_StartEx(cyisraddress address);
void WDT_Stop(void);

CY_ISR_PROTO(WDT_Interrupt);

void WDT_SetVector(cyisraddress address);
cyisraddress WDT_GetVector(void);

void WDT_SetPriority(uint8 priority);
uint8 WDT_GetPriority(void);

void WDT_Enable(void);
uint8 WDT_GetState(void);
void WDT_Disable(void);

void WDT_SetPending(void);
void WDT_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the WDT ISR. */
#define WDT_INTC_VECTOR            ((reg32 *) WDT__INTC_VECT)

/* Address of the WDT ISR priority. */
#define WDT_INTC_PRIOR             ((reg8 *) WDT__INTC_PRIOR_REG)

/* Priority of the WDT interrupt. */
#define WDT_INTC_PRIOR_NUMBER      WDT__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable WDT interrupt. */
#define WDT_INTC_SET_EN            ((reg32 *) WDT__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the WDT interrupt. */
#define WDT_INTC_CLR_EN            ((reg32 *) WDT__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the WDT interrupt state to pending. */
#define WDT_INTC_SET_PD            ((reg32 *) WDT__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the WDT interrupt. */
#define WDT_INTC_CLR_PD            ((reg32 *) WDT__INTC_CLR_PD_REG)


#endif /* CY_ISR_WDT_H */


/* [] END OF FILE */
