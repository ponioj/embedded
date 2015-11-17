/*******************************************************************************
* File Name: HEARTRATE_ANALOG.c  
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
#include "HEARTRATE_ANALOG.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 HEARTRATE_ANALOG__PORT == 15 && ((HEARTRATE_ANALOG__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: HEARTRATE_ANALOG_Write
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
void HEARTRATE_ANALOG_Write(uint8 value) 
{
    uint8 staticBits = (HEARTRATE_ANALOG_DR & (uint8)(~HEARTRATE_ANALOG_MASK));
    HEARTRATE_ANALOG_DR = staticBits | ((uint8)(value << HEARTRATE_ANALOG_SHIFT) & HEARTRATE_ANALOG_MASK);
}


/*******************************************************************************
* Function Name: HEARTRATE_ANALOG_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  HEARTRATE_ANALOG_DM_STRONG     Strong Drive 
*  HEARTRATE_ANALOG_DM_OD_HI      Open Drain, Drives High 
*  HEARTRATE_ANALOG_DM_OD_LO      Open Drain, Drives Low 
*  HEARTRATE_ANALOG_DM_RES_UP     Resistive Pull Up 
*  HEARTRATE_ANALOG_DM_RES_DWN    Resistive Pull Down 
*  HEARTRATE_ANALOG_DM_RES_UPDWN  Resistive Pull Up/Down 
*  HEARTRATE_ANALOG_DM_DIG_HIZ    High Impedance Digital 
*  HEARTRATE_ANALOG_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void HEARTRATE_ANALOG_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(HEARTRATE_ANALOG_0, mode);
}


/*******************************************************************************
* Function Name: HEARTRATE_ANALOG_Read
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
*  Macro HEARTRATE_ANALOG_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 HEARTRATE_ANALOG_Read(void) 
{
    return (HEARTRATE_ANALOG_PS & HEARTRATE_ANALOG_MASK) >> HEARTRATE_ANALOG_SHIFT;
}


/*******************************************************************************
* Function Name: HEARTRATE_ANALOG_ReadDataReg
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
uint8 HEARTRATE_ANALOG_ReadDataReg(void) 
{
    return (HEARTRATE_ANALOG_DR & HEARTRATE_ANALOG_MASK) >> HEARTRATE_ANALOG_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(HEARTRATE_ANALOG_INTSTAT) 

    /*******************************************************************************
    * Function Name: HEARTRATE_ANALOG_ClearInterrupt
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
    uint8 HEARTRATE_ANALOG_ClearInterrupt(void) 
    {
        return (HEARTRATE_ANALOG_INTSTAT & HEARTRATE_ANALOG_MASK) >> HEARTRATE_ANALOG_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
