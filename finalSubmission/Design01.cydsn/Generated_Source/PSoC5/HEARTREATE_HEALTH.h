/*******************************************************************************
* File Name: HEARTREATE_HEALTH.h  
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

#if !defined(CY_PINS_HEARTREATE_HEALTH_H) /* Pins HEARTREATE_HEALTH_H */
#define CY_PINS_HEARTREATE_HEALTH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HEARTREATE_HEALTH_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HEARTREATE_HEALTH__PORT == 15 && ((HEARTREATE_HEALTH__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    HEARTREATE_HEALTH_Write(uint8 value) ;
void    HEARTREATE_HEALTH_SetDriveMode(uint8 mode) ;
uint8   HEARTREATE_HEALTH_ReadDataReg(void) ;
uint8   HEARTREATE_HEALTH_Read(void) ;
uint8   HEARTREATE_HEALTH_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HEARTREATE_HEALTH_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define HEARTREATE_HEALTH_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define HEARTREATE_HEALTH_DM_RES_UP          PIN_DM_RES_UP
#define HEARTREATE_HEALTH_DM_RES_DWN         PIN_DM_RES_DWN
#define HEARTREATE_HEALTH_DM_OD_LO           PIN_DM_OD_LO
#define HEARTREATE_HEALTH_DM_OD_HI           PIN_DM_OD_HI
#define HEARTREATE_HEALTH_DM_STRONG          PIN_DM_STRONG
#define HEARTREATE_HEALTH_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define HEARTREATE_HEALTH_MASK               HEARTREATE_HEALTH__MASK
#define HEARTREATE_HEALTH_SHIFT              HEARTREATE_HEALTH__SHIFT
#define HEARTREATE_HEALTH_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HEARTREATE_HEALTH_PS                     (* (reg8 *) HEARTREATE_HEALTH__PS)
/* Data Register */
#define HEARTREATE_HEALTH_DR                     (* (reg8 *) HEARTREATE_HEALTH__DR)
/* Port Number */
#define HEARTREATE_HEALTH_PRT_NUM                (* (reg8 *) HEARTREATE_HEALTH__PRT) 
/* Connect to Analog Globals */                                                  
#define HEARTREATE_HEALTH_AG                     (* (reg8 *) HEARTREATE_HEALTH__AG)                       
/* Analog MUX bux enable */
#define HEARTREATE_HEALTH_AMUX                   (* (reg8 *) HEARTREATE_HEALTH__AMUX) 
/* Bidirectional Enable */                                                        
#define HEARTREATE_HEALTH_BIE                    (* (reg8 *) HEARTREATE_HEALTH__BIE)
/* Bit-mask for Aliased Register Access */
#define HEARTREATE_HEALTH_BIT_MASK               (* (reg8 *) HEARTREATE_HEALTH__BIT_MASK)
/* Bypass Enable */
#define HEARTREATE_HEALTH_BYP                    (* (reg8 *) HEARTREATE_HEALTH__BYP)
/* Port wide control signals */                                                   
#define HEARTREATE_HEALTH_CTL                    (* (reg8 *) HEARTREATE_HEALTH__CTL)
/* Drive Modes */
#define HEARTREATE_HEALTH_DM0                    (* (reg8 *) HEARTREATE_HEALTH__DM0) 
#define HEARTREATE_HEALTH_DM1                    (* (reg8 *) HEARTREATE_HEALTH__DM1)
#define HEARTREATE_HEALTH_DM2                    (* (reg8 *) HEARTREATE_HEALTH__DM2) 
/* Input Buffer Disable Override */
#define HEARTREATE_HEALTH_INP_DIS                (* (reg8 *) HEARTREATE_HEALTH__INP_DIS)
/* LCD Common or Segment Drive */
#define HEARTREATE_HEALTH_LCD_COM_SEG            (* (reg8 *) HEARTREATE_HEALTH__LCD_COM_SEG)
/* Enable Segment LCD */
#define HEARTREATE_HEALTH_LCD_EN                 (* (reg8 *) HEARTREATE_HEALTH__LCD_EN)
/* Slew Rate Control */
#define HEARTREATE_HEALTH_SLW                    (* (reg8 *) HEARTREATE_HEALTH__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HEARTREATE_HEALTH_PRTDSI__CAPS_SEL       (* (reg8 *) HEARTREATE_HEALTH__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HEARTREATE_HEALTH_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HEARTREATE_HEALTH__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HEARTREATE_HEALTH_PRTDSI__OE_SEL0        (* (reg8 *) HEARTREATE_HEALTH__PRTDSI__OE_SEL0) 
#define HEARTREATE_HEALTH_PRTDSI__OE_SEL1        (* (reg8 *) HEARTREATE_HEALTH__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HEARTREATE_HEALTH_PRTDSI__OUT_SEL0       (* (reg8 *) HEARTREATE_HEALTH__PRTDSI__OUT_SEL0) 
#define HEARTREATE_HEALTH_PRTDSI__OUT_SEL1       (* (reg8 *) HEARTREATE_HEALTH__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HEARTREATE_HEALTH_PRTDSI__SYNC_OUT       (* (reg8 *) HEARTREATE_HEALTH__PRTDSI__SYNC_OUT) 


#if defined(HEARTREATE_HEALTH__INTSTAT)  /* Interrupt Registers */

    #define HEARTREATE_HEALTH_INTSTAT                (* (reg8 *) HEARTREATE_HEALTH__INTSTAT)
    #define HEARTREATE_HEALTH_SNAP                   (* (reg8 *) HEARTREATE_HEALTH__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HEARTREATE_HEALTH_H */


/* [] END OF FILE */
