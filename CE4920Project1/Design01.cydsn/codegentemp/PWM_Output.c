/*******************************************************************************
* File Name: PWM_Output.c  
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
#include "PWM_Output.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 PWM_Output__PORT == 15 && ((PWM_Output__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: PWM_Output_Write
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
void PWM_Output_Write(uint8 value) 
{
    uint8 staticBits = (PWM_Output_DR & (uint8)(~PWM_Output_MASK));
    PWM_Output_DR = staticBits | ((uint8)(value << PWM_Output_SHIFT) & PWM_Output_MASK);
}


/*******************************************************************************
* Function Name: PWM_Output_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PWM_Output_DM_STRONG     Strong Drive 
*  PWM_Output_DM_OD_HI      Open Drain, Drives High 
*  PWM_Output_DM_OD_LO      Open Drain, Drives Low 
*  PWM_Output_DM_RES_UP     Resistive Pull Up 
*  PWM_Output_DM_RES_DWN    Resistive Pull Down 
*  PWM_Output_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PWM_Output_DM_DIG_HIZ    High Impedance Digital 
*  PWM_Output_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PWM_Output_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PWM_Output_0, mode);
}


/*******************************************************************************
* Function Name: PWM_Output_Read
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
*  Macro PWM_Output_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PWM_Output_Read(void) 
{
    return (PWM_Output_PS & PWM_Output_MASK) >> PWM_Output_SHIFT;
}


/*******************************************************************************
* Function Name: PWM_Output_ReadDataReg
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
uint8 PWM_Output_ReadDataReg(void) 
{
    return (PWM_Output_DR & PWM_Output_MASK) >> PWM_Output_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PWM_Output_INTSTAT) 

    /*******************************************************************************
    * Function Name: PWM_Output_ClearInterrupt
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
    uint8 PWM_Output_ClearInterrupt(void) 
    {
        return (PWM_Output_INTSTAT & PWM_Output_MASK) >> PWM_Output_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
