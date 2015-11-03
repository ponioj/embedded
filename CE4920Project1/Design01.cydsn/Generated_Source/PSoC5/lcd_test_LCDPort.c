/*******************************************************************************
* File Name: lcd_test_LCDPort.c  
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
#include "lcd_test_LCDPort.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 lcd_test_LCDPort__PORT == 15 && ((lcd_test_LCDPort__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: lcd_test_LCDPort_Write
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
void lcd_test_LCDPort_Write(uint8 value) 
{
    uint8 staticBits = (lcd_test_LCDPort_DR & (uint8)(~lcd_test_LCDPort_MASK));
    lcd_test_LCDPort_DR = staticBits | ((uint8)(value << lcd_test_LCDPort_SHIFT) & lcd_test_LCDPort_MASK);
}


/*******************************************************************************
* Function Name: lcd_test_LCDPort_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  lcd_test_LCDPort_DM_STRONG     Strong Drive 
*  lcd_test_LCDPort_DM_OD_HI      Open Drain, Drives High 
*  lcd_test_LCDPort_DM_OD_LO      Open Drain, Drives Low 
*  lcd_test_LCDPort_DM_RES_UP     Resistive Pull Up 
*  lcd_test_LCDPort_DM_RES_DWN    Resistive Pull Down 
*  lcd_test_LCDPort_DM_RES_UPDWN  Resistive Pull Up/Down 
*  lcd_test_LCDPort_DM_DIG_HIZ    High Impedance Digital 
*  lcd_test_LCDPort_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void lcd_test_LCDPort_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(lcd_test_LCDPort_0, mode);
	CyPins_SetPinDriveMode(lcd_test_LCDPort_1, mode);
	CyPins_SetPinDriveMode(lcd_test_LCDPort_2, mode);
	CyPins_SetPinDriveMode(lcd_test_LCDPort_3, mode);
	CyPins_SetPinDriveMode(lcd_test_LCDPort_4, mode);
	CyPins_SetPinDriveMode(lcd_test_LCDPort_5, mode);
	CyPins_SetPinDriveMode(lcd_test_LCDPort_6, mode);
}


/*******************************************************************************
* Function Name: lcd_test_LCDPort_Read
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
*  Macro lcd_test_LCDPort_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 lcd_test_LCDPort_Read(void) 
{
    return (lcd_test_LCDPort_PS & lcd_test_LCDPort_MASK) >> lcd_test_LCDPort_SHIFT;
}


/*******************************************************************************
* Function Name: lcd_test_LCDPort_ReadDataReg
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
uint8 lcd_test_LCDPort_ReadDataReg(void) 
{
    return (lcd_test_LCDPort_DR & lcd_test_LCDPort_MASK) >> lcd_test_LCDPort_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(lcd_test_LCDPort_INTSTAT) 

    /*******************************************************************************
    * Function Name: lcd_test_LCDPort_ClearInterrupt
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
    uint8 lcd_test_LCDPort_ClearInterrupt(void) 
    {
        return (lcd_test_LCDPort_INTSTAT & lcd_test_LCDPort_MASK) >> lcd_test_LCDPort_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
