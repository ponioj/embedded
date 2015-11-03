/*******************************************************************************
* File Name: HeartbeatCounter.h  
* Version 3.0
*
*  Description:
*   Contains the function prototypes and constants available to the counter
*   user module.
*
*   Note:
*    None
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
    
#if !defined(CY_COUNTER_HeartbeatCounter_H)
#define CY_COUNTER_HeartbeatCounter_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 HeartbeatCounter_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Counter_v3_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Error message for removed HeartbeatCounter_CounterUDB_sCTRLReg_ctrlreg through optimization */
#ifdef HeartbeatCounter_CounterUDB_sCTRLReg_ctrlreg__REMOVED
    #error Counter_v3_0 detected with a constant 0 for the enable, a \
                                constant 0 for the count or constant 1 for \
                                the reset. This will prevent the component from\
                                operating.
#endif /* HeartbeatCounter_CounterUDB_sCTRLReg_ctrlreg__REMOVED */


/**************************************
*           Parameter Defaults        
**************************************/

#define HeartbeatCounter_Resolution            32u
#define HeartbeatCounter_UsingFixedFunction    0u
#define HeartbeatCounter_ControlRegRemoved     0u
#define HeartbeatCounter_COMPARE_MODE_SOFTWARE 0u
#define HeartbeatCounter_CAPTURE_MODE_SOFTWARE 0u
#define HeartbeatCounter_RunModeUsed           0u


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Mode API Support
 * Backup structure for Sleep Wake up operations
 *************************************************************************/
typedef struct
{
    uint8 CounterEnableState; 
    uint32 CounterUdb;         /* Current Counter Value */

    #if (!HeartbeatCounter_ControlRegRemoved)
        uint8 CounterControlRegister;               /* Counter Control Register */
    #endif /* (!HeartbeatCounter_ControlRegRemoved) */

}HeartbeatCounter_backupStruct;


/**************************************
 *  Function Prototypes
 *************************************/
void    HeartbeatCounter_Start(void) ;
void    HeartbeatCounter_Stop(void) ;
void    HeartbeatCounter_SetInterruptMode(uint8 interruptsMask) ;
uint8   HeartbeatCounter_ReadStatusRegister(void) ;
#define HeartbeatCounter_GetInterruptSource() HeartbeatCounter_ReadStatusRegister()
#if(!HeartbeatCounter_ControlRegRemoved)
    uint8   HeartbeatCounter_ReadControlRegister(void) ;
    void    HeartbeatCounter_WriteControlRegister(uint8 control) \
        ;
#endif /* (!HeartbeatCounter_ControlRegRemoved) */
#if (!(HeartbeatCounter_UsingFixedFunction && (CY_PSOC5A)))
    void    HeartbeatCounter_WriteCounter(uint32 counter) \
            ; 
#endif /* (!(HeartbeatCounter_UsingFixedFunction && (CY_PSOC5A))) */
uint32  HeartbeatCounter_ReadCounter(void) ;
uint32  HeartbeatCounter_ReadCapture(void) ;
void    HeartbeatCounter_WritePeriod(uint32 period) \
    ;
uint32  HeartbeatCounter_ReadPeriod( void ) ;
#if (!HeartbeatCounter_UsingFixedFunction)
    void    HeartbeatCounter_WriteCompare(uint32 compare) \
        ;
    uint32  HeartbeatCounter_ReadCompare( void ) \
        ;
#endif /* (!HeartbeatCounter_UsingFixedFunction) */

#if (HeartbeatCounter_COMPARE_MODE_SOFTWARE)
    void    HeartbeatCounter_SetCompareMode(uint8 compareMode) ;
#endif /* (HeartbeatCounter_COMPARE_MODE_SOFTWARE) */
#if (HeartbeatCounter_CAPTURE_MODE_SOFTWARE)
    void    HeartbeatCounter_SetCaptureMode(uint8 captureMode) ;
#endif /* (HeartbeatCounter_CAPTURE_MODE_SOFTWARE) */
void HeartbeatCounter_ClearFIFO(void)     ;
void HeartbeatCounter_Init(void)          ;
void HeartbeatCounter_Enable(void)        ;
void HeartbeatCounter_SaveConfig(void)    ;
void HeartbeatCounter_RestoreConfig(void) ;
void HeartbeatCounter_Sleep(void)         ;
void HeartbeatCounter_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Counter__CompareModes, Used in Compare Mode retained for backward compatibility of tests*/
#define HeartbeatCounter__B_COUNTER__LESS_THAN 1
#define HeartbeatCounter__B_COUNTER__LESS_THAN_OR_EQUAL 2
#define HeartbeatCounter__B_COUNTER__EQUAL 0
#define HeartbeatCounter__B_COUNTER__GREATER_THAN 3
#define HeartbeatCounter__B_COUNTER__GREATER_THAN_OR_EQUAL 4
#define HeartbeatCounter__B_COUNTER__SOFTWARE 5

/* Enumerated Type Counter_CompareModes */
#define HeartbeatCounter_CMP_MODE_LT 1u
#define HeartbeatCounter_CMP_MODE_LTE 2u
#define HeartbeatCounter_CMP_MODE_EQ 0u
#define HeartbeatCounter_CMP_MODE_GT 3u
#define HeartbeatCounter_CMP_MODE_GTE 4u
#define HeartbeatCounter_CMP_MODE_SOFTWARE_CONTROLLED 5u

/* Enumerated Type B_Counter__CaptureModes, Used in Capture Mode retained for backward compatibility of tests*/
#define HeartbeatCounter__B_COUNTER__NONE 0
#define HeartbeatCounter__B_COUNTER__RISING_EDGE 1
#define HeartbeatCounter__B_COUNTER__FALLING_EDGE 2
#define HeartbeatCounter__B_COUNTER__EITHER_EDGE 3
#define HeartbeatCounter__B_COUNTER__SOFTWARE_CONTROL 4

/* Enumerated Type Counter_CompareModes */
#define HeartbeatCounter_CAP_MODE_NONE 0u
#define HeartbeatCounter_CAP_MODE_RISE 1u
#define HeartbeatCounter_CAP_MODE_FALL 2u
#define HeartbeatCounter_CAP_MODE_BOTH 3u
#define HeartbeatCounter_CAP_MODE_SOFTWARE_CONTROLLED 4u


/***************************************
 *  Initialization Values
 **************************************/
#define HeartbeatCounter_CAPTURE_MODE_CONF       0u
#define HeartbeatCounter_INIT_PERIOD_VALUE       4294967295u
#define HeartbeatCounter_INIT_COUNTER_VALUE      4294967295u
#if (HeartbeatCounter_UsingFixedFunction)
#define HeartbeatCounter_INIT_INTERRUPTS_MASK    ((uint8)((uint8)0u << HeartbeatCounter_STATUS_ZERO_INT_EN_MASK_SHIFT))
#else
#define HeartbeatCounter_INIT_COMPARE_VALUE      128u
#define HeartbeatCounter_INIT_INTERRUPTS_MASK ((uint8)((uint8)0u << HeartbeatCounter_STATUS_ZERO_INT_EN_MASK_SHIFT) | \
        ((uint8)((uint8)0u << HeartbeatCounter_STATUS_CAPTURE_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << HeartbeatCounter_STATUS_CMP_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << HeartbeatCounter_STATUS_OVERFLOW_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << HeartbeatCounter_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT)))
#define HeartbeatCounter_DEFAULT_COMPARE_MODE    1u

#if( 0 != HeartbeatCounter_CAPTURE_MODE_CONF)
    #define HeartbeatCounter_DEFAULT_CAPTURE_MODE    ((uint8)((uint8)0u << HeartbeatCounter_CTRL_CAPMODE0_SHIFT))
#else    
    #define HeartbeatCounter_DEFAULT_CAPTURE_MODE    (0u )
#endif /* ( 0 != HeartbeatCounter_CAPTURE_MODE_CONF) */

#endif /* (HeartbeatCounter_UsingFixedFunction) */


/**************************************
 *  Registers
 *************************************/
#if (HeartbeatCounter_UsingFixedFunction)
    #define HeartbeatCounter_STATICCOUNT_LSB     (*(reg16 *) HeartbeatCounter_CounterHW__CAP0 )
    #define HeartbeatCounter_STATICCOUNT_LSB_PTR ( (reg16 *) HeartbeatCounter_CounterHW__CAP0 )
    #define HeartbeatCounter_PERIOD_LSB          (*(reg16 *) HeartbeatCounter_CounterHW__PER0 )
    #define HeartbeatCounter_PERIOD_LSB_PTR      ( (reg16 *) HeartbeatCounter_CounterHW__PER0 )
    /* MODE must be set to 1 to set the compare value */
    #define HeartbeatCounter_COMPARE_LSB         (*(reg16 *) HeartbeatCounter_CounterHW__CNT_CMP0 )
    #define HeartbeatCounter_COMPARE_LSB_PTR     ( (reg16 *) HeartbeatCounter_CounterHW__CNT_CMP0 )
    /* MODE must be set to 0 to get the count */
    #define HeartbeatCounter_COUNTER_LSB         (*(reg16 *) HeartbeatCounter_CounterHW__CNT_CMP0 )
    #define HeartbeatCounter_COUNTER_LSB_PTR     ( (reg16 *) HeartbeatCounter_CounterHW__CNT_CMP0 )
    #define HeartbeatCounter_RT1                 (*(reg8 *) HeartbeatCounter_CounterHW__RT1)
    #define HeartbeatCounter_RT1_PTR             ( (reg8 *) HeartbeatCounter_CounterHW__RT1)
#else
    
    #if (HeartbeatCounter_Resolution <= 8u) /* 8-bit Counter */
    
        #define HeartbeatCounter_STATICCOUNT_LSB     (*(reg8 *) \
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__F0_REG )
        #define HeartbeatCounter_STATICCOUNT_LSB_PTR ( (reg8 *) \
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__F0_REG )
        #define HeartbeatCounter_PERIOD_LSB          (*(reg8 *) \
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D0_REG )
        #define HeartbeatCounter_PERIOD_LSB_PTR      ( (reg8 *) \
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D0_REG )
        #define HeartbeatCounter_COMPARE_LSB         (*(reg8 *) \
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D1_REG )
        #define HeartbeatCounter_COMPARE_LSB_PTR     ( (reg8 *) \
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D1_REG )
        #define HeartbeatCounter_COUNTER_LSB         (*(reg8 *) \
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__A0_REG )  
        #define HeartbeatCounter_COUNTER_LSB_PTR     ( (reg8 *)\
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__A0_REG )
    
    #elif(HeartbeatCounter_Resolution <= 16u) /* 16-bit Counter */
        #if(CY_PSOC3) /* 8-bit address space */ 
            #define HeartbeatCounter_STATICCOUNT_LSB     (*(reg16 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__F0_REG )
            #define HeartbeatCounter_STATICCOUNT_LSB_PTR ( (reg16 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__F0_REG )
            #define HeartbeatCounter_PERIOD_LSB          (*(reg16 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D0_REG )
            #define HeartbeatCounter_PERIOD_LSB_PTR      ( (reg16 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D0_REG )
            #define HeartbeatCounter_COMPARE_LSB         (*(reg16 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D1_REG )
            #define HeartbeatCounter_COMPARE_LSB_PTR     ( (reg16 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D1_REG )
            #define HeartbeatCounter_COUNTER_LSB         (*(reg16 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__A0_REG )  
            #define HeartbeatCounter_COUNTER_LSB_PTR     ( (reg16 *)\
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define HeartbeatCounter_STATICCOUNT_LSB     (*(reg16 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__16BIT_F0_REG )
            #define HeartbeatCounter_STATICCOUNT_LSB_PTR ( (reg16 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__16BIT_F0_REG )
            #define HeartbeatCounter_PERIOD_LSB          (*(reg16 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__16BIT_D0_REG )
            #define HeartbeatCounter_PERIOD_LSB_PTR      ( (reg16 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__16BIT_D0_REG )
            #define HeartbeatCounter_COMPARE_LSB         (*(reg16 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__16BIT_D1_REG )
            #define HeartbeatCounter_COMPARE_LSB_PTR     ( (reg16 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__16BIT_D1_REG )
            #define HeartbeatCounter_COUNTER_LSB         (*(reg16 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__16BIT_A0_REG )  
            #define HeartbeatCounter_COUNTER_LSB_PTR     ( (reg16 *)\
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */   
    #elif(HeartbeatCounter_Resolution <= 24u) /* 24-bit Counter */
        
        #define HeartbeatCounter_STATICCOUNT_LSB     (*(reg32 *) \
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__F0_REG )
        #define HeartbeatCounter_STATICCOUNT_LSB_PTR ( (reg32 *) \
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__F0_REG )
        #define HeartbeatCounter_PERIOD_LSB          (*(reg32 *) \
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D0_REG )
        #define HeartbeatCounter_PERIOD_LSB_PTR      ( (reg32 *) \
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D0_REG )
        #define HeartbeatCounter_COMPARE_LSB         (*(reg32 *) \
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D1_REG )
        #define HeartbeatCounter_COMPARE_LSB_PTR     ( (reg32 *) \
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D1_REG )
        #define HeartbeatCounter_COUNTER_LSB         (*(reg32 *) \
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__A0_REG )  
        #define HeartbeatCounter_COUNTER_LSB_PTR     ( (reg32 *)\
            HeartbeatCounter_CounterUDB_sC32_counterdp_u0__A0_REG )
    
    #else /* 32-bit Counter */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define HeartbeatCounter_STATICCOUNT_LSB     (*(reg32 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__F0_REG )
            #define HeartbeatCounter_STATICCOUNT_LSB_PTR ( (reg32 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__F0_REG )
            #define HeartbeatCounter_PERIOD_LSB          (*(reg32 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D0_REG )
            #define HeartbeatCounter_PERIOD_LSB_PTR      ( (reg32 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D0_REG )
            #define HeartbeatCounter_COMPARE_LSB         (*(reg32 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D1_REG )
            #define HeartbeatCounter_COMPARE_LSB_PTR     ( (reg32 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__D1_REG )
            #define HeartbeatCounter_COUNTER_LSB         (*(reg32 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__A0_REG )  
            #define HeartbeatCounter_COUNTER_LSB_PTR     ( (reg32 *)\
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define HeartbeatCounter_STATICCOUNT_LSB     (*(reg32 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__32BIT_F0_REG )
            #define HeartbeatCounter_STATICCOUNT_LSB_PTR ( (reg32 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__32BIT_F0_REG )
            #define HeartbeatCounter_PERIOD_LSB          (*(reg32 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__32BIT_D0_REG )
            #define HeartbeatCounter_PERIOD_LSB_PTR      ( (reg32 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__32BIT_D0_REG )
            #define HeartbeatCounter_COMPARE_LSB         (*(reg32 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__32BIT_D1_REG )
            #define HeartbeatCounter_COMPARE_LSB_PTR     ( (reg32 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__32BIT_D1_REG )
            #define HeartbeatCounter_COUNTER_LSB         (*(reg32 *) \
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__32BIT_A0_REG )  
            #define HeartbeatCounter_COUNTER_LSB_PTR     ( (reg32 *)\
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */   
    #endif

	#define HeartbeatCounter_COUNTER_LSB_PTR_8BIT     ( (reg8 *)\
                HeartbeatCounter_CounterUDB_sC32_counterdp_u0__A0_REG )
				
    #define HeartbeatCounter_AUX_CONTROLDP0 \
        (*(reg8 *) HeartbeatCounter_CounterUDB_sC32_counterdp_u0__DP_AUX_CTL_REG)
    
    #define HeartbeatCounter_AUX_CONTROLDP0_PTR \
        ( (reg8 *) HeartbeatCounter_CounterUDB_sC32_counterdp_u0__DP_AUX_CTL_REG)
    
    #if (HeartbeatCounter_Resolution == 16 || HeartbeatCounter_Resolution == 24 || HeartbeatCounter_Resolution == 32)
       #define HeartbeatCounter_AUX_CONTROLDP1 \
           (*(reg8 *) HeartbeatCounter_CounterUDB_sC32_counterdp_u1__DP_AUX_CTL_REG)
       #define HeartbeatCounter_AUX_CONTROLDP1_PTR \
           ( (reg8 *) HeartbeatCounter_CounterUDB_sC32_counterdp_u1__DP_AUX_CTL_REG)
    #endif /* (HeartbeatCounter_Resolution == 16 || HeartbeatCounter_Resolution == 24 || HeartbeatCounter_Resolution == 32) */
    
    #if (HeartbeatCounter_Resolution == 24 || HeartbeatCounter_Resolution == 32)
       #define HeartbeatCounter_AUX_CONTROLDP2 \
           (*(reg8 *) HeartbeatCounter_CounterUDB_sC32_counterdp_u2__DP_AUX_CTL_REG)
       #define HeartbeatCounter_AUX_CONTROLDP2_PTR \
           ( (reg8 *) HeartbeatCounter_CounterUDB_sC32_counterdp_u2__DP_AUX_CTL_REG)
    #endif /* (HeartbeatCounter_Resolution == 24 || HeartbeatCounter_Resolution == 32) */
    
    #if (HeartbeatCounter_Resolution == 32)
       #define HeartbeatCounter_AUX_CONTROLDP3 \
           (*(reg8 *) HeartbeatCounter_CounterUDB_sC32_counterdp_u3__DP_AUX_CTL_REG)
       #define HeartbeatCounter_AUX_CONTROLDP3_PTR \
           ( (reg8 *) HeartbeatCounter_CounterUDB_sC32_counterdp_u3__DP_AUX_CTL_REG)
    #endif /* (HeartbeatCounter_Resolution == 32) */

#endif  /* (HeartbeatCounter_UsingFixedFunction) */

#if (HeartbeatCounter_UsingFixedFunction)
    #define HeartbeatCounter_STATUS         (*(reg8 *) HeartbeatCounter_CounterHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define HeartbeatCounter_STATUS_MASK             (*(reg8 *) HeartbeatCounter_CounterHW__SR0 )
    #define HeartbeatCounter_STATUS_MASK_PTR         ( (reg8 *) HeartbeatCounter_CounterHW__SR0 )
    #define HeartbeatCounter_CONTROL                 (*(reg8 *) HeartbeatCounter_CounterHW__CFG0)
    #define HeartbeatCounter_CONTROL_PTR             ( (reg8 *) HeartbeatCounter_CounterHW__CFG0)
    #define HeartbeatCounter_CONTROL2                (*(reg8 *) HeartbeatCounter_CounterHW__CFG1)
    #define HeartbeatCounter_CONTROL2_PTR            ( (reg8 *) HeartbeatCounter_CounterHW__CFG1)
    #if (CY_PSOC3 || CY_PSOC5LP)
        #define HeartbeatCounter_CONTROL3       (*(reg8 *) HeartbeatCounter_CounterHW__CFG2)
        #define HeartbeatCounter_CONTROL3_PTR   ( (reg8 *) HeartbeatCounter_CounterHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define HeartbeatCounter_GLOBAL_ENABLE           (*(reg8 *) HeartbeatCounter_CounterHW__PM_ACT_CFG)
    #define HeartbeatCounter_GLOBAL_ENABLE_PTR       ( (reg8 *) HeartbeatCounter_CounterHW__PM_ACT_CFG)
    #define HeartbeatCounter_GLOBAL_STBY_ENABLE      (*(reg8 *) HeartbeatCounter_CounterHW__PM_STBY_CFG)
    #define HeartbeatCounter_GLOBAL_STBY_ENABLE_PTR  ( (reg8 *) HeartbeatCounter_CounterHW__PM_STBY_CFG)
    

    /********************************
    *    Constants
    ********************************/

    /* Fixed Function Block Chosen */
    #define HeartbeatCounter_BLOCK_EN_MASK          HeartbeatCounter_CounterHW__PM_ACT_MSK
    #define HeartbeatCounter_BLOCK_STBY_EN_MASK     HeartbeatCounter_CounterHW__PM_STBY_MSK 
    
    /* Control Register Bit Locations */    
    /* As defined in Register Map, part of TMRX_CFG0 register */
    #define HeartbeatCounter_CTRL_ENABLE_SHIFT      0x00u
    #define HeartbeatCounter_ONESHOT_SHIFT          0x02u
    /* Control Register Bit Masks */
    #define HeartbeatCounter_CTRL_ENABLE            ((uint8)((uint8)0x01u << HeartbeatCounter_CTRL_ENABLE_SHIFT))         
    #define HeartbeatCounter_ONESHOT                ((uint8)((uint8)0x01u << HeartbeatCounter_ONESHOT_SHIFT))

    /* Control2 Register Bit Masks */
    /* Set the mask for run mode */
    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        #define HeartbeatCounter_CTRL_MODE_SHIFT        0x01u    
        #define HeartbeatCounter_CTRL_MODE_MASK         ((uint8)((uint8)0x07u << HeartbeatCounter_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Use CFG2 Mode bits to set run mode */
        #define HeartbeatCounter_CTRL_MODE_SHIFT        0x00u    
        #define HeartbeatCounter_CTRL_MODE_MASK         ((uint8)((uint8)0x03u << HeartbeatCounter_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    /* Set the mask for interrupt (raw/status register) */
    #define HeartbeatCounter_CTRL2_IRQ_SEL_SHIFT     0x00u
    #define HeartbeatCounter_CTRL2_IRQ_SEL          ((uint8)((uint8)0x01u << HeartbeatCounter_CTRL2_IRQ_SEL_SHIFT))     
    
    /* Status Register Bit Locations */
    #define HeartbeatCounter_STATUS_ZERO_SHIFT      0x07u  /* As defined in Register Map, part of TMRX_SR0 register */ 

    /* Status Register Interrupt Enable Bit Locations */
    #define HeartbeatCounter_STATUS_ZERO_INT_EN_MASK_SHIFT      (HeartbeatCounter_STATUS_ZERO_SHIFT - 0x04u)

    /* Status Register Bit Masks */                           
    #define HeartbeatCounter_STATUS_ZERO            ((uint8)((uint8)0x01u << HeartbeatCounter_STATUS_ZERO_SHIFT))

    /* Status Register Interrupt Bit Masks*/
    #define HeartbeatCounter_STATUS_ZERO_INT_EN_MASK       ((uint8)((uint8)HeartbeatCounter_STATUS_ZERO >> 0x04u))
    
    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define HeartbeatCounter_RT1_SHIFT            0x04u
    #define HeartbeatCounter_RT1_MASK             ((uint8)((uint8)0x03u << HeartbeatCounter_RT1_SHIFT))  /* Sync TC and CMP bit masks */
    #define HeartbeatCounter_SYNC                 ((uint8)((uint8)0x03u << HeartbeatCounter_RT1_SHIFT))
    #define HeartbeatCounter_SYNCDSI_SHIFT        0x00u
    #define HeartbeatCounter_SYNCDSI_MASK         ((uint8)((uint8)0x0Fu << HeartbeatCounter_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    #define HeartbeatCounter_SYNCDSI_EN           ((uint8)((uint8)0x0Fu << HeartbeatCounter_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    
#else /* !HeartbeatCounter_UsingFixedFunction */
    #define HeartbeatCounter_STATUS               (* (reg8 *) HeartbeatCounter_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define HeartbeatCounter_STATUS_PTR           (  (reg8 *) HeartbeatCounter_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define HeartbeatCounter_STATUS_MASK          (* (reg8 *) HeartbeatCounter_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define HeartbeatCounter_STATUS_MASK_PTR      (  (reg8 *) HeartbeatCounter_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define HeartbeatCounter_STATUS_AUX_CTRL      (*(reg8 *) HeartbeatCounter_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define HeartbeatCounter_STATUS_AUX_CTRL_PTR  ( (reg8 *) HeartbeatCounter_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define HeartbeatCounter_CONTROL              (* (reg8 *) HeartbeatCounter_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )
    #define HeartbeatCounter_CONTROL_PTR          (  (reg8 *) HeartbeatCounter_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )


    /********************************
    *    Constants
    ********************************/
    /* Control Register Bit Locations */
    #define HeartbeatCounter_CTRL_CAPMODE0_SHIFT    0x03u       /* As defined by Verilog Implementation */
    #define HeartbeatCounter_CTRL_RESET_SHIFT       0x06u       /* As defined by Verilog Implementation */
    #define HeartbeatCounter_CTRL_ENABLE_SHIFT      0x07u       /* As defined by Verilog Implementation */
    /* Control Register Bit Masks */
    #define HeartbeatCounter_CTRL_CMPMODE_MASK      0x07u 
    #define HeartbeatCounter_CTRL_CAPMODE_MASK      0x03u  
    #define HeartbeatCounter_CTRL_RESET             ((uint8)((uint8)0x01u << HeartbeatCounter_CTRL_RESET_SHIFT))  
    #define HeartbeatCounter_CTRL_ENABLE            ((uint8)((uint8)0x01u << HeartbeatCounter_CTRL_ENABLE_SHIFT)) 

    /* Status Register Bit Locations */
    #define HeartbeatCounter_STATUS_CMP_SHIFT       0x00u       /* As defined by Verilog Implementation */
    #define HeartbeatCounter_STATUS_ZERO_SHIFT      0x01u       /* As defined by Verilog Implementation */
    #define HeartbeatCounter_STATUS_OVERFLOW_SHIFT  0x02u       /* As defined by Verilog Implementation */
    #define HeartbeatCounter_STATUS_UNDERFLOW_SHIFT 0x03u       /* As defined by Verilog Implementation */
    #define HeartbeatCounter_STATUS_CAPTURE_SHIFT   0x04u       /* As defined by Verilog Implementation */
    #define HeartbeatCounter_STATUS_FIFOFULL_SHIFT  0x05u       /* As defined by Verilog Implementation */
    #define HeartbeatCounter_STATUS_FIFONEMP_SHIFT  0x06u       /* As defined by Verilog Implementation */
    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define HeartbeatCounter_STATUS_CMP_INT_EN_MASK_SHIFT       HeartbeatCounter_STATUS_CMP_SHIFT       
    #define HeartbeatCounter_STATUS_ZERO_INT_EN_MASK_SHIFT      HeartbeatCounter_STATUS_ZERO_SHIFT      
    #define HeartbeatCounter_STATUS_OVERFLOW_INT_EN_MASK_SHIFT  HeartbeatCounter_STATUS_OVERFLOW_SHIFT  
    #define HeartbeatCounter_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT HeartbeatCounter_STATUS_UNDERFLOW_SHIFT 
    #define HeartbeatCounter_STATUS_CAPTURE_INT_EN_MASK_SHIFT   HeartbeatCounter_STATUS_CAPTURE_SHIFT   
    #define HeartbeatCounter_STATUS_FIFOFULL_INT_EN_MASK_SHIFT  HeartbeatCounter_STATUS_FIFOFULL_SHIFT  
    #define HeartbeatCounter_STATUS_FIFONEMP_INT_EN_MASK_SHIFT  HeartbeatCounter_STATUS_FIFONEMP_SHIFT  
    /* Status Register Bit Masks */                
    #define HeartbeatCounter_STATUS_CMP             ((uint8)((uint8)0x01u << HeartbeatCounter_STATUS_CMP_SHIFT))  
    #define HeartbeatCounter_STATUS_ZERO            ((uint8)((uint8)0x01u << HeartbeatCounter_STATUS_ZERO_SHIFT)) 
    #define HeartbeatCounter_STATUS_OVERFLOW        ((uint8)((uint8)0x01u << HeartbeatCounter_STATUS_OVERFLOW_SHIFT)) 
    #define HeartbeatCounter_STATUS_UNDERFLOW       ((uint8)((uint8)0x01u << HeartbeatCounter_STATUS_UNDERFLOW_SHIFT)) 
    #define HeartbeatCounter_STATUS_CAPTURE         ((uint8)((uint8)0x01u << HeartbeatCounter_STATUS_CAPTURE_SHIFT)) 
    #define HeartbeatCounter_STATUS_FIFOFULL        ((uint8)((uint8)0x01u << HeartbeatCounter_STATUS_FIFOFULL_SHIFT))
    #define HeartbeatCounter_STATUS_FIFONEMP        ((uint8)((uint8)0x01u << HeartbeatCounter_STATUS_FIFONEMP_SHIFT))
    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define HeartbeatCounter_STATUS_CMP_INT_EN_MASK            HeartbeatCounter_STATUS_CMP                    
    #define HeartbeatCounter_STATUS_ZERO_INT_EN_MASK           HeartbeatCounter_STATUS_ZERO            
    #define HeartbeatCounter_STATUS_OVERFLOW_INT_EN_MASK       HeartbeatCounter_STATUS_OVERFLOW        
    #define HeartbeatCounter_STATUS_UNDERFLOW_INT_EN_MASK      HeartbeatCounter_STATUS_UNDERFLOW       
    #define HeartbeatCounter_STATUS_CAPTURE_INT_EN_MASK        HeartbeatCounter_STATUS_CAPTURE         
    #define HeartbeatCounter_STATUS_FIFOFULL_INT_EN_MASK       HeartbeatCounter_STATUS_FIFOFULL        
    #define HeartbeatCounter_STATUS_FIFONEMP_INT_EN_MASK       HeartbeatCounter_STATUS_FIFONEMP         
    

    /* StatusI Interrupt Enable bit Location in the Auxilliary Control Register */
    #define HeartbeatCounter_STATUS_ACTL_INT_EN     0x10u /* As defined for the ACTL Register */
    
    /* Datapath Auxillary Control Register definitions */
    #define HeartbeatCounter_AUX_CTRL_FIFO0_CLR         0x01u   /* As defined by Register map */
    #define HeartbeatCounter_AUX_CTRL_FIFO1_CLR         0x02u   /* As defined by Register map */
    #define HeartbeatCounter_AUX_CTRL_FIFO0_LVL         0x04u   /* As defined by Register map */
    #define HeartbeatCounter_AUX_CTRL_FIFO1_LVL         0x08u   /* As defined by Register map */
    #define HeartbeatCounter_STATUS_ACTL_INT_EN_MASK    0x10u   /* As defined for the ACTL Register */
    
#endif /* HeartbeatCounter_UsingFixedFunction */

#endif  /* CY_COUNTER_HeartbeatCounter_H */


/* [] END OF FILE */

