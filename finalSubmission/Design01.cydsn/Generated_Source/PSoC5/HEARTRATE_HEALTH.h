/*******************************************************************************
* File Name: HEARTRATE_HEALTH.h  
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

#if !defined(CY_PINS_HEARTRATE_HEALTH_H) /* Pins HEARTRATE_HEALTH_H */
#define CY_PINS_HEARTRATE_HEALTH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HEARTRATE_HEALTH_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HEARTRATE_HEALTH__PORT == 15 && ((HEARTRATE_HEALTH__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    HEARTRATE_HEALTH_Write(uint8 value) ;
void    HEARTRATE_HEALTH_SetDriveMode(uint8 mode) ;
uint8   HEARTRATE_HEALTH_ReadDataReg(void) ;
uint8   HEARTRATE_HEALTH_Read(void) ;
uint8   HEARTRATE_HEALTH_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HEARTRATE_HEALTH_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define HEARTRATE_HEALTH_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define HEARTRATE_HEALTH_DM_RES_UP          PIN_DM_RES_UP
#define HEARTRATE_HEALTH_DM_RES_DWN         PIN_DM_RES_DWN
#define HEARTRATE_HEALTH_DM_OD_LO           PIN_DM_OD_LO
#define HEARTRATE_HEALTH_DM_OD_HI           PIN_DM_OD_HI
#define HEARTRATE_HEALTH_DM_STRONG          PIN_DM_STRONG
#define HEARTRATE_HEALTH_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define HEARTRATE_HEALTH_MASK               HEARTRATE_HEALTH__MASK
#define HEARTRATE_HEALTH_SHIFT              HEARTRATE_HEALTH__SHIFT
#define HEARTRATE_HEALTH_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HEARTRATE_HEALTH_PS                     (* (reg8 *) HEARTRATE_HEALTH__PS)
/* Data Register */
#define HEARTRATE_HEALTH_DR                     (* (reg8 *) HEARTRATE_HEALTH__DR)
/* Port Number */
#define HEARTRATE_HEALTH_PRT_NUM                (* (reg8 *) HEARTRATE_HEALTH__PRT) 
/* Connect to Analog Globals */                                                  
#define HEARTRATE_HEALTH_AG                     (* (reg8 *) HEARTRATE_HEALTH__AG)                       
/* Analog MUX bux enable */
#define HEARTRATE_HEALTH_AMUX                   (* (reg8 *) HEARTRATE_HEALTH__AMUX) 
/* Bidirectional Enable */                                                        
#define HEARTRATE_HEALTH_BIE                    (* (reg8 *) HEARTRATE_HEALTH__BIE)
/* Bit-mask for Aliased Register Access */
#define HEARTRATE_HEALTH_BIT_MASK               (* (reg8 *) HEARTRATE_HEALTH__BIT_MASK)
/* Bypass Enable */
#define HEARTRATE_HEALTH_BYP                    (* (reg8 *) HEARTRATE_HEALTH__BYP)
/* Port wide control signals */                                                   
#define HEARTRATE_HEALTH_CTL                    (* (reg8 *) HEARTRATE_HEALTH__CTL)
/* Drive Modes */
#define HEARTRATE_HEALTH_DM0                    (* (reg8 *) HEARTRATE_HEALTH__DM0) 
#define HEARTRATE_HEALTH_DM1                    (* (reg8 *) HEARTRATE_HEALTH__DM1)
#define HEARTRATE_HEALTH_DM2                    (* (reg8 *) HEARTRATE_HEALTH__DM2) 
/* Input Buffer Disable Override */
#define HEARTRATE_HEALTH_INP_DIS                (* (reg8 *) HEARTRATE_HEALTH__INP_DIS)
/* LCD Common or Segment Drive */
#define HEARTRATE_HEALTH_LCD_COM_SEG            (* (reg8 *) HEARTRATE_HEALTH__LCD_COM_SEG)
/* Enable Segment LCD */
#define HEARTRATE_HEALTH_LCD_EN                 (* (reg8 *) HEARTRATE_HEALTH__LCD_EN)
/* Slew Rate Control */
#define HEARTRATE_HEALTH_SLW                    (* (reg8 *) HEARTRATE_HEALTH__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HEARTRATE_HEALTH_PRTDSI__CAPS_SEL       (* (reg8 *) HEARTRATE_HEALTH__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HEARTRATE_HEALTH_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HEARTRATE_HEALTH__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HEARTRATE_HEALTH_PRTDSI__OE_SEL0        (* (reg8 *) HEARTRATE_HEALTH__PRTDSI__OE_SEL0) 
#define HEARTRATE_HEALTH_PRTDSI__OE_SEL1        (* (reg8 *) HEARTRATE_HEALTH__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HEARTRATE_HEALTH_PRTDSI__OUT_SEL0       (* (reg8 *) HEARTRATE_HEALTH__PRTDSI__OUT_SEL0) 
#define HEARTRATE_HEALTH_PRTDSI__OUT_SEL1       (* (reg8 *) HEARTRATE_HEALTH__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HEARTRATE_HEALTH_PRTDSI__SYNC_OUT       (* (reg8 *) HEARTRATE_HEALTH__PRTDSI__SYNC_OUT) 


#if defined(HEARTRATE_HEALTH__INTSTAT)  /* Interrupt Registers */

    #define HEARTRATE_HEALTH_INTSTAT                (* (reg8 *) HEARTRATE_HEALTH__INTSTAT)
    #define HEARTRATE_HEALTH_SNAP                   (* (reg8 *) HEARTRATE_HEALTH__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HEARTRATE_HEALTH_H */


/* [] END OF FILE */
