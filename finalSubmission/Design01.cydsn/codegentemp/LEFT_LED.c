/*******************************************************************************
* File Name: LEFT_LED.c  
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
#include "LEFT_LED.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 LEFT_LED__PORT == 15 && ((LEFT_LED__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: LEFT_LED_Write
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
void LEFT_LED_Write(uint8 value) 
{
    uint8 staticBits = (LEFT_LED_DR & (uint8)(~LEFT_LED_MASK));
    LEFT_LED_DR = staticBits | ((uint8)(value << LEFT_LED_SHIFT) & LEFT_LED_MASK);
}


/*******************************************************************************
* Function Name: LEFT_LED_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LEFT_LED_DM_STRONG     Strong Drive 
*  LEFT_LED_DM_OD_HI      Open Drain, Drives High 
*  LEFT_LED_DM_OD_LO      Open Drain, Drives Low 
*  LEFT_LED_DM_RES_UP     Resistive Pull Up 
*  LEFT_LED_DM_RES_DWN    Resistive Pull Down 
*  LEFT_LED_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LEFT_LED_DM_DIG_HIZ    High Impedance Digital 
*  LEFT_LED_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LEFT_LED_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LEFT_LED_0, mode);
}


/*******************************************************************************
* Function Name: LEFT_LED_Read
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
*  Macro LEFT_LED_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LEFT_LED_Read(void) 
{
    return (LEFT_LED_PS & LEFT_LED_MASK) >> LEFT_LED_SHIFT;
}


/*******************************************************************************
* Function Name: LEFT_LED_ReadDataReg
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
uint8 LEFT_LED_ReadDataReg(void) 
{
    return (LEFT_LED_DR & LEFT_LED_MASK) >> LEFT_LED_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LEFT_LED_INTSTAT) 

    /*******************************************************************************
    * Function Name: LEFT_LED_ClearInterrupt
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
    uint8 LEFT_LED_ClearInterrupt(void) 
    {
        return (LEFT_LED_INTSTAT & LEFT_LED_MASK) >> LEFT_LED_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
