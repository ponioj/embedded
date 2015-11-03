/*******************************************************************************
* File Name: heartrate_timer_12mhz.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_heartrate_timer_12mhz_H)
#define CY_CLOCK_heartrate_timer_12mhz_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void heartrate_timer_12mhz_Start(void) ;
void heartrate_timer_12mhz_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void heartrate_timer_12mhz_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void heartrate_timer_12mhz_StandbyPower(uint8 state) ;
void heartrate_timer_12mhz_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 heartrate_timer_12mhz_GetDividerRegister(void) ;
void heartrate_timer_12mhz_SetModeRegister(uint8 modeBitMask) ;
void heartrate_timer_12mhz_ClearModeRegister(uint8 modeBitMask) ;
uint8 heartrate_timer_12mhz_GetModeRegister(void) ;
void heartrate_timer_12mhz_SetSourceRegister(uint8 clkSource) ;
uint8 heartrate_timer_12mhz_GetSourceRegister(void) ;
#if defined(heartrate_timer_12mhz__CFG3)
void heartrate_timer_12mhz_SetPhaseRegister(uint8 clkPhase) ;
uint8 heartrate_timer_12mhz_GetPhaseRegister(void) ;
#endif /* defined(heartrate_timer_12mhz__CFG3) */

#define heartrate_timer_12mhz_Enable()                       heartrate_timer_12mhz_Start()
#define heartrate_timer_12mhz_Disable()                      heartrate_timer_12mhz_Stop()
#define heartrate_timer_12mhz_SetDivider(clkDivider)         heartrate_timer_12mhz_SetDividerRegister(clkDivider, 1u)
#define heartrate_timer_12mhz_SetDividerValue(clkDivider)    heartrate_timer_12mhz_SetDividerRegister((clkDivider) - 1u, 1u)
#define heartrate_timer_12mhz_SetMode(clkMode)               heartrate_timer_12mhz_SetModeRegister(clkMode)
#define heartrate_timer_12mhz_SetSource(clkSource)           heartrate_timer_12mhz_SetSourceRegister(clkSource)
#if defined(heartrate_timer_12mhz__CFG3)
#define heartrate_timer_12mhz_SetPhase(clkPhase)             heartrate_timer_12mhz_SetPhaseRegister(clkPhase)
#define heartrate_timer_12mhz_SetPhaseValue(clkPhase)        heartrate_timer_12mhz_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(heartrate_timer_12mhz__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define heartrate_timer_12mhz_CLKEN              (* (reg8 *) heartrate_timer_12mhz__PM_ACT_CFG)
#define heartrate_timer_12mhz_CLKEN_PTR          ((reg8 *) heartrate_timer_12mhz__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define heartrate_timer_12mhz_CLKSTBY            (* (reg8 *) heartrate_timer_12mhz__PM_STBY_CFG)
#define heartrate_timer_12mhz_CLKSTBY_PTR        ((reg8 *) heartrate_timer_12mhz__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define heartrate_timer_12mhz_DIV_LSB            (* (reg8 *) heartrate_timer_12mhz__CFG0)
#define heartrate_timer_12mhz_DIV_LSB_PTR        ((reg8 *) heartrate_timer_12mhz__CFG0)
#define heartrate_timer_12mhz_DIV_PTR            ((reg16 *) heartrate_timer_12mhz__CFG0)

/* Clock MSB divider configuration register. */
#define heartrate_timer_12mhz_DIV_MSB            (* (reg8 *) heartrate_timer_12mhz__CFG1)
#define heartrate_timer_12mhz_DIV_MSB_PTR        ((reg8 *) heartrate_timer_12mhz__CFG1)

/* Mode and source configuration register */
#define heartrate_timer_12mhz_MOD_SRC            (* (reg8 *) heartrate_timer_12mhz__CFG2)
#define heartrate_timer_12mhz_MOD_SRC_PTR        ((reg8 *) heartrate_timer_12mhz__CFG2)

#if defined(heartrate_timer_12mhz__CFG3)
/* Analog clock phase configuration register */
#define heartrate_timer_12mhz_PHASE              (* (reg8 *) heartrate_timer_12mhz__CFG3)
#define heartrate_timer_12mhz_PHASE_PTR          ((reg8 *) heartrate_timer_12mhz__CFG3)
#endif /* defined(heartrate_timer_12mhz__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define heartrate_timer_12mhz_CLKEN_MASK         heartrate_timer_12mhz__PM_ACT_MSK
#define heartrate_timer_12mhz_CLKSTBY_MASK       heartrate_timer_12mhz__PM_STBY_MSK

/* CFG2 field masks */
#define heartrate_timer_12mhz_SRC_SEL_MSK        heartrate_timer_12mhz__CFG2_SRC_SEL_MASK
#define heartrate_timer_12mhz_MODE_MASK          (~(heartrate_timer_12mhz_SRC_SEL_MSK))

#if defined(heartrate_timer_12mhz__CFG3)
/* CFG3 phase mask */
#define heartrate_timer_12mhz_PHASE_MASK         heartrate_timer_12mhz__CFG3_PHASE_DLY_MASK
#endif /* defined(heartrate_timer_12mhz__CFG3) */

#endif /* CY_CLOCK_heartrate_timer_12mhz_H */


/* [] END OF FILE */
