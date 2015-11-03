/*******************************************************************************
* File Name: ADC_HRT_PM.c
* Version 3.0
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_HRT.h"


/***************************************
* Local data allocation
***************************************/

static ADC_HRT_BACKUP_STRUCT  ADC_HRT_backup =
{
    ADC_HRT_DISABLED
};


/*******************************************************************************
* Function Name: ADC_HRT_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_HRT_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_HRT_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_HRT_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_HRT_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The ADC_HRT_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_HRT_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void ADC_HRT_Sleep(void)
{
    if((ADC_HRT_PWRMGR_SAR_REG  & ADC_HRT_ACT_PWR_SAR_EN) != 0u)
    {
        if((ADC_HRT_SAR_CSR0_REG & ADC_HRT_SAR_SOF_START_CONV) != 0u)
        {
            ADC_HRT_backup.enableState = ADC_HRT_ENABLED | ADC_HRT_STARTED;
        }
        else
        {
            ADC_HRT_backup.enableState = ADC_HRT_ENABLED;
        }
        ADC_HRT_Stop();
    }
    else
    {
        ADC_HRT_backup.enableState = ADC_HRT_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_HRT_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  ADC_HRT_Sleep() was called. If the component was enabled before the
*  ADC_HRT_Sleep() function was called, the
*  ADC_HRT_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_HRT_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void ADC_HRT_Wakeup(void)
{
    if(ADC_HRT_backup.enableState != ADC_HRT_DISABLED)
    {
        ADC_HRT_Enable();
        #if(ADC_HRT_DEFAULT_CONV_MODE != ADC_HRT__HARDWARE_TRIGGER)
            if((ADC_HRT_backup.enableState & ADC_HRT_STARTED) != 0u)
            {
                ADC_HRT_StartConvert();
            }
        #endif /* End ADC_HRT_DEFAULT_CONV_MODE != ADC_HRT__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
