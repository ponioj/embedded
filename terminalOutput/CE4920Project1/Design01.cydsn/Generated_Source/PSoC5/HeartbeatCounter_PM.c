/*******************************************************************************
* File Name: HeartbeatCounter_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "HeartbeatCounter.h"

static HeartbeatCounter_backupStruct HeartbeatCounter_backup;


/*******************************************************************************
* Function Name: HeartbeatCounter_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  HeartbeatCounter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void HeartbeatCounter_SaveConfig(void) 
{
    #if (!HeartbeatCounter_UsingFixedFunction)

        HeartbeatCounter_backup.CounterUdb = HeartbeatCounter_ReadCounter();

        #if(!HeartbeatCounter_ControlRegRemoved)
            HeartbeatCounter_backup.CounterControlRegister = HeartbeatCounter_ReadControlRegister();
        #endif /* (!HeartbeatCounter_ControlRegRemoved) */

    #endif /* (!HeartbeatCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: HeartbeatCounter_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  HeartbeatCounter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void HeartbeatCounter_RestoreConfig(void) 
{      
    #if (!HeartbeatCounter_UsingFixedFunction)

       HeartbeatCounter_WriteCounter(HeartbeatCounter_backup.CounterUdb);

        #if(!HeartbeatCounter_ControlRegRemoved)
            HeartbeatCounter_WriteControlRegister(HeartbeatCounter_backup.CounterControlRegister);
        #endif /* (!HeartbeatCounter_ControlRegRemoved) */

    #endif /* (!HeartbeatCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: HeartbeatCounter_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  HeartbeatCounter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void HeartbeatCounter_Sleep(void) 
{
    #if(!HeartbeatCounter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(HeartbeatCounter_CTRL_ENABLE == (HeartbeatCounter_CONTROL & HeartbeatCounter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            HeartbeatCounter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            HeartbeatCounter_backup.CounterEnableState = 0u;
        }
    #else
        HeartbeatCounter_backup.CounterEnableState = 1u;
        if(HeartbeatCounter_backup.CounterEnableState != 0u)
        {
            HeartbeatCounter_backup.CounterEnableState = 0u;
        }
    #endif /* (!HeartbeatCounter_ControlRegRemoved) */
    
    HeartbeatCounter_Stop();
    HeartbeatCounter_SaveConfig();
}


/*******************************************************************************
* Function Name: HeartbeatCounter_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  HeartbeatCounter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void HeartbeatCounter_Wakeup(void) 
{
    HeartbeatCounter_RestoreConfig();
    #if(!HeartbeatCounter_ControlRegRemoved)
        if(HeartbeatCounter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            HeartbeatCounter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!HeartbeatCounter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
