/*******************************************************************************
* File Name: lcd_test_PM.c
* Version 2.10
*
* Description:
*  This file provides the API source code for the Static Segment LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "lcd_test.h"


static lcd_test_BACKUP_STRUCT lcd_test_backup;


/*******************************************************************************
* Function Name: lcd_test_SaveConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void lcd_test_SaveConfig(void) 
{
}


/*******************************************************************************
* Function Name: lcd_test_RestoreConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void lcd_test_RestoreConfig(void) 
{
}


/*******************************************************************************
* Function Name: lcd_test_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void lcd_test_Sleep(void) 
{
    lcd_test_backup.enableState = lcd_test_enableState;
    lcd_test_SaveConfig();
    lcd_test_Stop();
}


/*******************************************************************************
* Function Name: lcd_test_Wakeup
********************************************************************************
*
* Summary:
*  Wakes the component from sleep mode. Configures DMA and enables the component
*  for normal operation.
*
* Parameters:
*  lcd_test_enableState - Global variable.
*
* Return:
*  Status one of standard status for PSoC3 Component
*       CYRET_SUCCESS - Function completed successfully.
*       CYRET_LOCKED - The object was locked, already in use. Some of TDs or
*                      a channel already in use.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void lcd_test_Wakeup(void) 
{
    lcd_test_RestoreConfig();

    if(lcd_test_backup.enableState == 1u)
    {
        lcd_test_Enable();
    }
}


/* [] END OF FILE */
