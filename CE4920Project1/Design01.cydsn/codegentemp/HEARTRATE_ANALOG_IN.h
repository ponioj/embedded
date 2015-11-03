/*******************************************************************************
* File Name: HEARTRATE_ANALOG_IN.h  
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

#if !defined(CY_PINS_HEARTRATE_ANALOG_IN_H) /* Pins HEARTRATE_ANALOG_IN_H */
#define CY_PINS_HEARTRATE_ANALOG_IN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HEARTRATE_ANALOG_IN_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HEARTRATE_ANALOG_IN__PORT == 15 && ((HEARTRATE_ANALOG_IN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    HEARTRATE_ANALOG_IN_Write(uint8 value) ;
void    HEARTRATE_ANALOG_IN_SetDriveMode(uint8 mode) ;
uint8   HEARTRATE_ANALOG_IN_ReadDataReg(void) ;
uint8   HEARTRATE_ANALOG_IN_Read(void) ;
uint8   HEARTRATE_ANALOG_IN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HEARTRATE_ANALOG_IN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define HEARTRATE_ANALOG_IN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define HEARTRATE_ANALOG_IN_DM_RES_UP          PIN_DM_RES_UP
#define HEARTRATE_ANALOG_IN_DM_RES_DWN         PIN_DM_RES_DWN
#define HEARTRATE_ANALOG_IN_DM_OD_LO           PIN_DM_OD_LO
#define HEARTRATE_ANALOG_IN_DM_OD_HI           PIN_DM_OD_HI
#define HEARTRATE_ANALOG_IN_DM_STRONG          PIN_DM_STRONG
#define HEARTRATE_ANALOG_IN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define HEARTRATE_ANALOG_IN_MASK               HEARTRATE_ANALOG_IN__MASK
#define HEARTRATE_ANALOG_IN_SHIFT              HEARTRATE_ANALOG_IN__SHIFT
#define HEARTRATE_ANALOG_IN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HEARTRATE_ANALOG_IN_PS                     (* (reg8 *) HEARTRATE_ANALOG_IN__PS)
/* Data Register */
#define HEARTRATE_ANALOG_IN_DR                     (* (reg8 *) HEARTRATE_ANALOG_IN__DR)
/* Port Number */
#define HEARTRATE_ANALOG_IN_PRT_NUM                (* (reg8 *) HEARTRATE_ANALOG_IN__PRT) 
/* Connect to Analog Globals */                                                  
#define HEARTRATE_ANALOG_IN_AG                     (* (reg8 *) HEARTRATE_ANALOG_IN__AG)                       
/* Analog MUX bux enable */
#define HEARTRATE_ANALOG_IN_AMUX                   (* (reg8 *) HEARTRATE_ANALOG_IN__AMUX) 
/* Bidirectional Enable */                                                        
#define HEARTRATE_ANALOG_IN_BIE                    (* (reg8 *) HEARTRATE_ANALOG_IN__BIE)
/* Bit-mask for Aliased Register Access */
#define HEARTRATE_ANALOG_IN_BIT_MASK               (* (reg8 *) HEARTRATE_ANALOG_IN__BIT_MASK)
/* Bypass Enable */
#define HEARTRATE_ANALOG_IN_BYP                    (* (reg8 *) HEARTRATE_ANALOG_IN__BYP)
/* Port wide control signals */                                                   
#define HEARTRATE_ANALOG_IN_CTL                    (* (reg8 *) HEARTRATE_ANALOG_IN__CTL)
/* Drive Modes */
#define HEARTRATE_ANALOG_IN_DM0                    (* (reg8 *) HEARTRATE_ANALOG_IN__DM0) 
#define HEARTRATE_ANALOG_IN_DM1                    (* (reg8 *) HEARTRATE_ANALOG_IN__DM1)
#define HEARTRATE_ANALOG_IN_DM2                    (* (reg8 *) HEARTRATE_ANALOG_IN__DM2) 
/* Input Buffer Disable Override */
#define HEARTRATE_ANALOG_IN_INP_DIS                (* (reg8 *) HEARTRATE_ANALOG_IN__INP_DIS)
/* LCD Common or Segment Drive */
#define HEARTRATE_ANALOG_IN_LCD_COM_SEG            (* (reg8 *) HEARTRATE_ANALOG_IN__LCD_COM_SEG)
/* Enable Segment LCD */
#define HEARTRATE_ANALOG_IN_LCD_EN                 (* (reg8 *) HEARTRATE_ANALOG_IN__LCD_EN)
/* Slew Rate Control */
#define HEARTRATE_ANALOG_IN_SLW                    (* (reg8 *) HEARTRATE_ANALOG_IN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HEARTRATE_ANALOG_IN_PRTDSI__CAPS_SEL       (* (reg8 *) HEARTRATE_ANALOG_IN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HEARTRATE_ANALOG_IN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HEARTRATE_ANALOG_IN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HEARTRATE_ANALOG_IN_PRTDSI__OE_SEL0        (* (reg8 *) HEARTRATE_ANALOG_IN__PRTDSI__OE_SEL0) 
#define HEARTRATE_ANALOG_IN_PRTDSI__OE_SEL1        (* (reg8 *) HEARTRATE_ANALOG_IN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HEARTRATE_ANALOG_IN_PRTDSI__OUT_SEL0       (* (reg8 *) HEARTRATE_ANALOG_IN__PRTDSI__OUT_SEL0) 
#define HEARTRATE_ANALOG_IN_PRTDSI__OUT_SEL1       (* (reg8 *) HEARTRATE_ANALOG_IN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HEARTRATE_ANALOG_IN_PRTDSI__SYNC_OUT       (* (reg8 *) HEARTRATE_ANALOG_IN__PRTDSI__SYNC_OUT) 


#if defined(HEARTRATE_ANALOG_IN__INTSTAT)  /* Interrupt Registers */

    #define HEARTRATE_ANALOG_IN_INTSTAT                (* (reg8 *) HEARTRATE_ANALOG_IN__INTSTAT)
    #define HEARTRATE_ANALOG_IN_SNAP                   (* (reg8 *) HEARTRATE_ANALOG_IN__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HEARTRATE_ANALOG_IN_H */


/* [] END OF FILE */
