/*******************************************************************************
* File Name: STOP_REQUEST.h  
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

#if !defined(CY_PINS_STOP_REQUEST_H) /* Pins STOP_REQUEST_H */
#define CY_PINS_STOP_REQUEST_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "STOP_REQUEST_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 STOP_REQUEST__PORT == 15 && ((STOP_REQUEST__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    STOP_REQUEST_Write(uint8 value) ;
void    STOP_REQUEST_SetDriveMode(uint8 mode) ;
uint8   STOP_REQUEST_ReadDataReg(void) ;
uint8   STOP_REQUEST_Read(void) ;
uint8   STOP_REQUEST_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define STOP_REQUEST_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define STOP_REQUEST_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define STOP_REQUEST_DM_RES_UP          PIN_DM_RES_UP
#define STOP_REQUEST_DM_RES_DWN         PIN_DM_RES_DWN
#define STOP_REQUEST_DM_OD_LO           PIN_DM_OD_LO
#define STOP_REQUEST_DM_OD_HI           PIN_DM_OD_HI
#define STOP_REQUEST_DM_STRONG          PIN_DM_STRONG
#define STOP_REQUEST_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define STOP_REQUEST_MASK               STOP_REQUEST__MASK
#define STOP_REQUEST_SHIFT              STOP_REQUEST__SHIFT
#define STOP_REQUEST_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define STOP_REQUEST_PS                     (* (reg8 *) STOP_REQUEST__PS)
/* Data Register */
#define STOP_REQUEST_DR                     (* (reg8 *) STOP_REQUEST__DR)
/* Port Number */
#define STOP_REQUEST_PRT_NUM                (* (reg8 *) STOP_REQUEST__PRT) 
/* Connect to Analog Globals */                                                  
#define STOP_REQUEST_AG                     (* (reg8 *) STOP_REQUEST__AG)                       
/* Analog MUX bux enable */
#define STOP_REQUEST_AMUX                   (* (reg8 *) STOP_REQUEST__AMUX) 
/* Bidirectional Enable */                                                        
#define STOP_REQUEST_BIE                    (* (reg8 *) STOP_REQUEST__BIE)
/* Bit-mask for Aliased Register Access */
#define STOP_REQUEST_BIT_MASK               (* (reg8 *) STOP_REQUEST__BIT_MASK)
/* Bypass Enable */
#define STOP_REQUEST_BYP                    (* (reg8 *) STOP_REQUEST__BYP)
/* Port wide control signals */                                                   
#define STOP_REQUEST_CTL                    (* (reg8 *) STOP_REQUEST__CTL)
/* Drive Modes */
#define STOP_REQUEST_DM0                    (* (reg8 *) STOP_REQUEST__DM0) 
#define STOP_REQUEST_DM1                    (* (reg8 *) STOP_REQUEST__DM1)
#define STOP_REQUEST_DM2                    (* (reg8 *) STOP_REQUEST__DM2) 
/* Input Buffer Disable Override */
#define STOP_REQUEST_INP_DIS                (* (reg8 *) STOP_REQUEST__INP_DIS)
/* LCD Common or Segment Drive */
#define STOP_REQUEST_LCD_COM_SEG            (* (reg8 *) STOP_REQUEST__LCD_COM_SEG)
/* Enable Segment LCD */
#define STOP_REQUEST_LCD_EN                 (* (reg8 *) STOP_REQUEST__LCD_EN)
/* Slew Rate Control */
#define STOP_REQUEST_SLW                    (* (reg8 *) STOP_REQUEST__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define STOP_REQUEST_PRTDSI__CAPS_SEL       (* (reg8 *) STOP_REQUEST__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define STOP_REQUEST_PRTDSI__DBL_SYNC_IN    (* (reg8 *) STOP_REQUEST__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define STOP_REQUEST_PRTDSI__OE_SEL0        (* (reg8 *) STOP_REQUEST__PRTDSI__OE_SEL0) 
#define STOP_REQUEST_PRTDSI__OE_SEL1        (* (reg8 *) STOP_REQUEST__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define STOP_REQUEST_PRTDSI__OUT_SEL0       (* (reg8 *) STOP_REQUEST__PRTDSI__OUT_SEL0) 
#define STOP_REQUEST_PRTDSI__OUT_SEL1       (* (reg8 *) STOP_REQUEST__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define STOP_REQUEST_PRTDSI__SYNC_OUT       (* (reg8 *) STOP_REQUEST__PRTDSI__SYNC_OUT) 


#if defined(STOP_REQUEST__INTSTAT)  /* Interrupt Registers */

    #define STOP_REQUEST_INTSTAT                (* (reg8 *) STOP_REQUEST__INTSTAT)
    #define STOP_REQUEST_SNAP                   (* (reg8 *) STOP_REQUEST__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_STOP_REQUEST_H */


/* [] END OF FILE */
