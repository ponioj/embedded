/*******************************************************************************
* File Name: STOP_REQUEST.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "STOP_REQUEST.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 STOP_REQUEST__PORT == 15 && ((STOP_REQUEST__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: STOP_REQUEST_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void STOP_REQUEST_Write(uint8 value) 
{
    uint8 staticBits = (STOP_REQUEST_DR & (uint8)(~STOP_REQUEST_MASK));
    STOP_REQUEST_DR = staticBits | ((uint8)(value << STOP_REQUEST_SHIFT) & STOP_REQUEST_MASK);
}


/*******************************************************************************
* Function Name: STOP_REQUEST_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  STOP_REQUEST_DM_STRONG     Strong Drive 
*  STOP_REQUEST_DM_OD_HI      Open Drain, Drives High 
*  STOP_REQUEST_DM_OD_LO      Open Drain, Drives Low 
*  STOP_REQUEST_DM_RES_UP     Resistive Pull Up 
*  STOP_REQUEST_DM_RES_DWN    Resistive Pull Down 
*  STOP_REQUEST_DM_RES_UPDWN  Resistive Pull Up/Down 
*  STOP_REQUEST_DM_DIG_HIZ    High Impedance Digital 
*  STOP_REQUEST_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void STOP_REQUEST_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(STOP_REQUEST_0, mode);
}


/*******************************************************************************
* Function Name: STOP_REQUEST_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro STOP_REQUEST_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 STOP_REQUEST_Read(void) 
{
    return (STOP_REQUEST_PS & STOP_REQUEST_MASK) >> STOP_REQUEST_SHIFT;
}


/*******************************************************************************
* Function Name: STOP_REQUEST_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 STOP_REQUEST_ReadDataReg(void) 
{
    return (STOP_REQUEST_DR & STOP_REQUEST_MASK) >> STOP_REQUEST_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(STOP_REQUEST_INTSTAT) 

    /*******************************************************************************
    * Function Name: STOP_REQUEST_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 STOP_REQUEST_ClearInterrupt(void) 
    {
        return (STOP_REQUEST_INTSTAT & STOP_REQUEST_MASK) >> STOP_REQUEST_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
