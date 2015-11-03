/*******************************************************************************
* File Name: amp.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_amp_H) /* Pins amp_H */
#define CY_PINS_amp_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "amp_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 amp__PORT == 15 && ((amp__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    amp_Write(uint8 value) ;
void    amp_SetDriveMode(uint8 mode) ;
uint8   amp_ReadDataReg(void) ;
uint8   amp_Read(void) ;
uint8   amp_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define amp_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define amp_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define amp_DM_RES_UP          PIN_DM_RES_UP
#define amp_DM_RES_DWN         PIN_DM_RES_DWN
#define amp_DM_OD_LO           PIN_DM_OD_LO
#define amp_DM_OD_HI           PIN_DM_OD_HI
#define amp_DM_STRONG          PIN_DM_STRONG
#define amp_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define amp_MASK               amp__MASK
#define amp_SHIFT              amp__SHIFT
#define amp_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define amp_PS                     (* (reg8 *) amp__PS)
/* Data Register */
#define amp_DR                     (* (reg8 *) amp__DR)
/* Port Number */
#define amp_PRT_NUM                (* (reg8 *) amp__PRT) 
/* Connect to Analog Globals */                                                  
#define amp_AG                     (* (reg8 *) amp__AG)                       
/* Analog MUX bux enable */
#define amp_AMUX                   (* (reg8 *) amp__AMUX) 
/* Bidirectional Enable */                                                        
#define amp_BIE                    (* (reg8 *) amp__BIE)
/* Bit-mask for Aliased Register Access */
#define amp_BIT_MASK               (* (reg8 *) amp__BIT_MASK)
/* Bypass Enable */
#define amp_BYP                    (* (reg8 *) amp__BYP)
/* Port wide control signals */                                                   
#define amp_CTL                    (* (reg8 *) amp__CTL)
/* Drive Modes */
#define amp_DM0                    (* (reg8 *) amp__DM0) 
#define amp_DM1                    (* (reg8 *) amp__DM1)
#define amp_DM2                    (* (reg8 *) amp__DM2) 
/* Input Buffer Disable Override */
#define amp_INP_DIS                (* (reg8 *) amp__INP_DIS)
/* LCD Common or Segment Drive */
#define amp_LCD_COM_SEG            (* (reg8 *) amp__LCD_COM_SEG)
/* Enable Segment LCD */
#define amp_LCD_EN                 (* (reg8 *) amp__LCD_EN)
/* Slew Rate Control */
#define amp_SLW                    (* (reg8 *) amp__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define amp_PRTDSI__CAPS_SEL       (* (reg8 *) amp__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define amp_PRTDSI__DBL_SYNC_IN    (* (reg8 *) amp__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define amp_PRTDSI__OE_SEL0        (* (reg8 *) amp__PRTDSI__OE_SEL0) 
#define amp_PRTDSI__OE_SEL1        (* (reg8 *) amp__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define amp_PRTDSI__OUT_SEL0       (* (reg8 *) amp__PRTDSI__OUT_SEL0) 
#define amp_PRTDSI__OUT_SEL1       (* (reg8 *) amp__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define amp_PRTDSI__SYNC_OUT       (* (reg8 *) amp__PRTDSI__SYNC_OUT) 


#if defined(amp__INTSTAT)  /* Interrupt Registers */

    #define amp_INTSTAT                (* (reg8 *) amp__INTSTAT)
    #define amp_SNAP                   (* (reg8 *) amp__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_amp_H */


/* [] END OF FILE */
