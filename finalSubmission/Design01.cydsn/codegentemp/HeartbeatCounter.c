/*******************************************************************************
* File Name: HeartbeatCounter.c  
* Version 3.0
*
*  Description:
*     The Counter component consists of a 8, 16, 24 or 32-bit counter with
*     a selectable period between 2 and 2^Width - 1.  
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

uint8 HeartbeatCounter_initVar = 0u;


/*******************************************************************************
* Function Name: HeartbeatCounter_Init
********************************************************************************
* Summary:
*     Initialize to the schematic state
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void HeartbeatCounter_Init(void) 
{
        #if (!HeartbeatCounter_UsingFixedFunction && !HeartbeatCounter_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!HeartbeatCounter_UsingFixedFunction && !HeartbeatCounter_ControlRegRemoved) */
        
        #if(!HeartbeatCounter_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 HeartbeatCounter_interruptState;
        #endif /* (!HeartbeatCounter_UsingFixedFunction) */
        
        #if (HeartbeatCounter_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            HeartbeatCounter_CONTROL &= HeartbeatCounter_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                HeartbeatCounter_CONTROL2 &= ((uint8)(~HeartbeatCounter_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                HeartbeatCounter_CONTROL3 &= ((uint8)(~HeartbeatCounter_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (HeartbeatCounter_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                HeartbeatCounter_CONTROL |= HeartbeatCounter_ONESHOT;
            #endif /* (HeartbeatCounter_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            HeartbeatCounter_CONTROL2 |= HeartbeatCounter_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            HeartbeatCounter_RT1 &= ((uint8)(~HeartbeatCounter_RT1_MASK));
            HeartbeatCounter_RT1 |= HeartbeatCounter_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            HeartbeatCounter_RT1 &= ((uint8)(~HeartbeatCounter_SYNCDSI_MASK));
            HeartbeatCounter_RT1 |= HeartbeatCounter_SYNCDSI_EN;

        #else
            #if(!HeartbeatCounter_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = HeartbeatCounter_CONTROL & ((uint8)(~HeartbeatCounter_CTRL_CMPMODE_MASK));
            HeartbeatCounter_CONTROL = ctrl | HeartbeatCounter_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = HeartbeatCounter_CONTROL & ((uint8)(~HeartbeatCounter_CTRL_CAPMODE_MASK));
            
            #if( 0 != HeartbeatCounter_CAPTURE_MODE_CONF)
                HeartbeatCounter_CONTROL = ctrl | HeartbeatCounter_DEFAULT_CAPTURE_MODE;
            #else
                HeartbeatCounter_CONTROL = ctrl;
            #endif /* 0 != HeartbeatCounter_CAPTURE_MODE */ 
            
            #endif /* (!HeartbeatCounter_ControlRegRemoved) */
        #endif /* (HeartbeatCounter_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!HeartbeatCounter_UsingFixedFunction)
            HeartbeatCounter_ClearFIFO();
        #endif /* (!HeartbeatCounter_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        HeartbeatCounter_WritePeriod(HeartbeatCounter_INIT_PERIOD_VALUE);
        #if (!(HeartbeatCounter_UsingFixedFunction && (CY_PSOC5A)))
            HeartbeatCounter_WriteCounter(HeartbeatCounter_INIT_COUNTER_VALUE);
        #endif /* (!(HeartbeatCounter_UsingFixedFunction && (CY_PSOC5A))) */
        HeartbeatCounter_SetInterruptMode(HeartbeatCounter_INIT_INTERRUPTS_MASK);
        
        #if (!HeartbeatCounter_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)HeartbeatCounter_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            HeartbeatCounter_WriteCompare(HeartbeatCounter_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            HeartbeatCounter_interruptState = CyEnterCriticalSection();
            
            HeartbeatCounter_STATUS_AUX_CTRL |= HeartbeatCounter_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(HeartbeatCounter_interruptState);
            
        #endif /* (!HeartbeatCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: HeartbeatCounter_Enable
********************************************************************************
* Summary:
*     Enable the Counter
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: 
*   If the Enable mode is set to Hardware only then this function has no effect 
*   on the operation of the counter.
*
*******************************************************************************/
void HeartbeatCounter_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (HeartbeatCounter_UsingFixedFunction)
        HeartbeatCounter_GLOBAL_ENABLE |= HeartbeatCounter_BLOCK_EN_MASK;
        HeartbeatCounter_GLOBAL_STBY_ENABLE |= HeartbeatCounter_BLOCK_STBY_EN_MASK;
    #endif /* (HeartbeatCounter_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!HeartbeatCounter_ControlRegRemoved || HeartbeatCounter_UsingFixedFunction)
        HeartbeatCounter_CONTROL |= HeartbeatCounter_CTRL_ENABLE;                
    #endif /* (!HeartbeatCounter_ControlRegRemoved || HeartbeatCounter_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: HeartbeatCounter_Start
********************************************************************************
* Summary:
*  Enables the counter for operation 
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Global variables:
*  HeartbeatCounter_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void HeartbeatCounter_Start(void) 
{
    if(HeartbeatCounter_initVar == 0u)
    {
        HeartbeatCounter_Init();
        
        HeartbeatCounter_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    HeartbeatCounter_Enable();        
}


/*******************************************************************************
* Function Name: HeartbeatCounter_Stop
********************************************************************************
* Summary:
* Halts the counter, but does not change any modes or disable interrupts.
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: If the Enable mode is set to Hardware only then this function
*               has no effect on the operation of the counter.
*
*******************************************************************************/
void HeartbeatCounter_Stop(void) 
{
    /* Disable Counter */
    #if(!HeartbeatCounter_ControlRegRemoved || HeartbeatCounter_UsingFixedFunction)
        HeartbeatCounter_CONTROL &= ((uint8)(~HeartbeatCounter_CTRL_ENABLE));        
    #endif /* (!HeartbeatCounter_ControlRegRemoved || HeartbeatCounter_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (HeartbeatCounter_UsingFixedFunction)
        HeartbeatCounter_GLOBAL_ENABLE &= ((uint8)(~HeartbeatCounter_BLOCK_EN_MASK));
        HeartbeatCounter_GLOBAL_STBY_ENABLE &= ((uint8)(~HeartbeatCounter_BLOCK_STBY_EN_MASK));
    #endif /* (HeartbeatCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: HeartbeatCounter_SetInterruptMode
********************************************************************************
* Summary:
* Configures which interrupt sources are enabled to generate the final interrupt
*
* Parameters:  
*  InterruptsMask: This parameter is an or'd collection of the status bits
*                   which will be allowed to generate the counters interrupt.   
*
* Return: 
*  void
*
*******************************************************************************/
void HeartbeatCounter_SetInterruptMode(uint8 interruptsMask) 
{
    HeartbeatCounter_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: HeartbeatCounter_ReadStatusRegister
********************************************************************************
* Summary:
*   Reads the status register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the status register
*
* Side Effects:
*   Status register bits may be clear on read. 
*
*******************************************************************************/
uint8   HeartbeatCounter_ReadStatusRegister(void) 
{
    return HeartbeatCounter_STATUS;
}


#if(!HeartbeatCounter_ControlRegRemoved)
/*******************************************************************************
* Function Name: HeartbeatCounter_ReadControlRegister
********************************************************************************
* Summary:
*   Reads the control register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
uint8   HeartbeatCounter_ReadControlRegister(void) 
{
    return HeartbeatCounter_CONTROL;
}


/*******************************************************************************
* Function Name: HeartbeatCounter_WriteControlRegister
********************************************************************************
* Summary:
*   Sets the bit-field of the control register.  This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
void    HeartbeatCounter_WriteControlRegister(uint8 control) 
{
    HeartbeatCounter_CONTROL = control;
}

#endif  /* (!HeartbeatCounter_ControlRegRemoved) */


#if (!(HeartbeatCounter_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: HeartbeatCounter_WriteCounter
********************************************************************************
* Summary:
*   This funtion is used to set the counter to a specific value
*
* Parameters:  
*  counter:  New counter value. 
*
* Return: 
*  void 
*
*******************************************************************************/
void HeartbeatCounter_WriteCounter(uint32 counter) \
                                   
{
    #if(HeartbeatCounter_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (HeartbeatCounter_GLOBAL_ENABLE & HeartbeatCounter_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        HeartbeatCounter_GLOBAL_ENABLE |= HeartbeatCounter_BLOCK_EN_MASK;
        CY_SET_REG16(HeartbeatCounter_COUNTER_LSB_PTR, (uint16)counter);
        HeartbeatCounter_GLOBAL_ENABLE &= ((uint8)(~HeartbeatCounter_BLOCK_EN_MASK));
    #else
        CY_SET_REG32(HeartbeatCounter_COUNTER_LSB_PTR, counter);
    #endif /* (HeartbeatCounter_UsingFixedFunction) */
}
#endif /* (!(HeartbeatCounter_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: HeartbeatCounter_ReadCounter
********************************************************************************
* Summary:
* Returns the current value of the counter.  It doesn't matter
* if the counter is enabled or running.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint32) The present value of the counter.
*
*******************************************************************************/
uint32 HeartbeatCounter_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(HeartbeatCounter_UsingFixedFunction)
		(void)CY_GET_REG16(HeartbeatCounter_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(HeartbeatCounter_COUNTER_LSB_PTR_8BIT);
	#endif/* (HeartbeatCounter_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(HeartbeatCounter_UsingFixedFunction)
        return ((uint32)CY_GET_REG16(HeartbeatCounter_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG32(HeartbeatCounter_STATICCOUNT_LSB_PTR));
    #endif /* (HeartbeatCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: HeartbeatCounter_ReadCapture
********************************************************************************
* Summary:
*   This function returns the last value captured.
*
* Parameters:  
*  void
*
* Return: 
*  (uint32) Present Capture value.
*
*******************************************************************************/
uint32 HeartbeatCounter_ReadCapture(void) 
{
    #if(HeartbeatCounter_UsingFixedFunction)
        return ((uint32)CY_GET_REG16(HeartbeatCounter_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG32(HeartbeatCounter_STATICCOUNT_LSB_PTR));
    #endif /* (HeartbeatCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: HeartbeatCounter_WritePeriod
********************************************************************************
* Summary:
* Changes the period of the counter.  The new period 
* will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period: (uint32) A value of 0 will result in
*         the counter remaining at zero.  
*
* Return: 
*  void
*
*******************************************************************************/
void HeartbeatCounter_WritePeriod(uint32 period) 
{
    #if(HeartbeatCounter_UsingFixedFunction)
        CY_SET_REG16(HeartbeatCounter_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG32(HeartbeatCounter_PERIOD_LSB_PTR, period);
    #endif /* (HeartbeatCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: HeartbeatCounter_ReadPeriod
********************************************************************************
* Summary:
* Reads the current period value without affecting counter operation.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint32) Present period value.
*
*******************************************************************************/
uint32 HeartbeatCounter_ReadPeriod(void) 
{
    #if(HeartbeatCounter_UsingFixedFunction)
        return ((uint32)CY_GET_REG16(HeartbeatCounter_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG32(HeartbeatCounter_PERIOD_LSB_PTR));
    #endif /* (HeartbeatCounter_UsingFixedFunction) */
}


#if (!HeartbeatCounter_UsingFixedFunction)
/*******************************************************************************
* Function Name: HeartbeatCounter_WriteCompare
********************************************************************************
* Summary:
* Changes the compare value.  The compare output will 
* reflect the new value on the next UDB clock.  The compare output will be 
* driven high when the present counter value compares true based on the 
* configured compare mode setting. 
*
* Parameters:  
*  Compare:  New compare value. 
*
* Return: 
*  void
*
*******************************************************************************/
void HeartbeatCounter_WriteCompare(uint32 compare) \
                                   
{
    #if(HeartbeatCounter_UsingFixedFunction)
        CY_SET_REG16(HeartbeatCounter_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG32(HeartbeatCounter_COMPARE_LSB_PTR, compare);
    #endif /* (HeartbeatCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: HeartbeatCounter_ReadCompare
********************************************************************************
* Summary:
* Returns the compare value.
*
* Parameters:  
*  void:
*
* Return: 
*  (uint32) Present compare value.
*
*******************************************************************************/
uint32 HeartbeatCounter_ReadCompare(void) 
{
    return (CY_GET_REG32(HeartbeatCounter_COMPARE_LSB_PTR));
}


#if (HeartbeatCounter_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: HeartbeatCounter_SetCompareMode
********************************************************************************
* Summary:
*  Sets the software controlled Compare Mode.
*
* Parameters:
*  compareMode:  Compare Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void HeartbeatCounter_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    HeartbeatCounter_CONTROL &= ((uint8)(~HeartbeatCounter_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    HeartbeatCounter_CONTROL |= compareMode;
}
#endif  /* (HeartbeatCounter_COMPARE_MODE_SOFTWARE) */


#if (HeartbeatCounter_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: HeartbeatCounter_SetCaptureMode
********************************************************************************
* Summary:
*  Sets the software controlled Capture Mode.
*
* Parameters:
*  captureMode:  Capture Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void HeartbeatCounter_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    HeartbeatCounter_CONTROL &= ((uint8)(~HeartbeatCounter_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    HeartbeatCounter_CONTROL |= ((uint8)((uint8)captureMode << HeartbeatCounter_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (HeartbeatCounter_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: HeartbeatCounter_ClearFIFO
********************************************************************************
* Summary:
*   This function clears all capture data from the capture FIFO
*
* Parameters:  
*  void:
*
* Return: 
*  None
*
*******************************************************************************/
void HeartbeatCounter_ClearFIFO(void) 
{

    while(0u != (HeartbeatCounter_ReadStatusRegister() & HeartbeatCounter_STATUS_FIFONEMP))
    {
        (void)HeartbeatCounter_ReadCapture();
    }

}
#endif  /* (!HeartbeatCounter_UsingFixedFunction) */


/* [] END OF FILE */

