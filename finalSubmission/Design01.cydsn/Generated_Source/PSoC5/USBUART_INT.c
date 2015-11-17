/*******************************************************************************
* File Name: USBUARTINT.c
* Version 2.50
*
* Description:
*  This file provides all Interrupt Service functionality of the UART component
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "USBUART.h"


/***************************************
* Custom Declarations
***************************************/
/* `#START CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */

#if (USBUART_RX_INTERRUPT_ENABLED && (USBUART_RX_ENABLED || USBUART_HD_ENABLED))
    /*******************************************************************************
    * Function Name: USBUART_RXISR
    ********************************************************************************
    *
    * Summary:
    *  Interrupt Service Routine for RX portion of the UART
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  USBUART_rxBuffer - RAM buffer pointer for save received data.
    *  USBUART_rxBufferWrite - cyclic index for write to rxBuffer,
    *     increments after each byte saved to buffer.
    *  USBUART_rxBufferRead - cyclic index for read from rxBuffer,
    *     checked to detect overflow condition.
    *  USBUART_rxBufferOverflow - software overflow flag. Set to one
    *     when USBUART_rxBufferWrite index overtakes
    *     USBUART_rxBufferRead index.
    *  USBUART_rxBufferLoopDetect - additional variable to detect overflow.
    *     Set to one when USBUART_rxBufferWrite is equal to
    *    USBUART_rxBufferRead
    *  USBUART_rxAddressMode - this variable contains the Address mode,
    *     selected in customizer or set by UART_SetRxAddressMode() API.
    *  USBUART_rxAddressDetected - set to 1 when correct address received,
    *     and analysed to store following addressed data bytes to the buffer.
    *     When not correct address received, set to 0 to skip following data bytes.
    *
    *******************************************************************************/
    CY_ISR(USBUART_RXISR)
    {
        uint8 readData;
        uint8 readStatus;
        uint8 increment_pointer = 0u;

    #if(CY_PSOC3)
        uint8 int_en;
    #endif /* (CY_PSOC3) */

        /* User code required at start of ISR */
        /* `#START USBUART_RXISR_START` */

        /* `#END` */

    #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
        int_en = EA;
        CyGlobalIntEnable;
    #endif /* (CY_PSOC3) */

        do
        {
            /* Read receiver status register */
            readStatus = USBUART_RXSTATUS_REG;
            /* Copy the same status to readData variable for backward compatibility support 
            *  of the user code in USBUART_RXISR_ERROR` section. 
            */
            readData = readStatus;

            if((readStatus & (USBUART_RX_STS_BREAK | 
                            USBUART_RX_STS_PAR_ERROR |
                            USBUART_RX_STS_STOP_ERROR | 
                            USBUART_RX_STS_OVERRUN)) != 0u)
            {
                /* ERROR handling. */
                USBUART_errorStatus |= readStatus & ( USBUART_RX_STS_BREAK | 
                                                            USBUART_RX_STS_PAR_ERROR | 
                                                            USBUART_RX_STS_STOP_ERROR | 
                                                            USBUART_RX_STS_OVERRUN);
                /* `#START USBUART_RXISR_ERROR` */

                /* `#END` */
            }
            
            if((readStatus & USBUART_RX_STS_FIFO_NOTEMPTY) != 0u)
            {
                /* Read data from the RX data register */
                readData = USBUART_RXDATA_REG;
            #if (USBUART_RXHW_ADDRESS_ENABLED)
                if(USBUART_rxAddressMode == (uint8)USBUART__B_UART__AM_SW_DETECT_TO_BUFFER)
                {
                    if((readStatus & USBUART_RX_STS_MRKSPC) != 0u)
                    {
                        if ((readStatus & USBUART_RX_STS_ADDR_MATCH) != 0u)
                        {
                            USBUART_rxAddressDetected = 1u;
                        }
                        else
                        {
                            USBUART_rxAddressDetected = 0u;
                        }
                    }
                    if(USBUART_rxAddressDetected != 0u)
                    {   /* Store only addressed data */
                        USBUART_rxBuffer[USBUART_rxBufferWrite] = readData;
                        increment_pointer = 1u;
                    }
                }
                else /* Without software addressing */
                {
                    USBUART_rxBuffer[USBUART_rxBufferWrite] = readData;
                    increment_pointer = 1u;
                }
            #else  /* Without addressing */
                USBUART_rxBuffer[USBUART_rxBufferWrite] = readData;
                increment_pointer = 1u;
            #endif /* (USBUART_RXHW_ADDRESS_ENABLED) */

                /* Do not increment buffer pointer when skip not addressed data */
                if(increment_pointer != 0u)
                {
                    if(USBUART_rxBufferLoopDetect != 0u)
                    {   /* Set Software Buffer status Overflow */
                        USBUART_rxBufferOverflow = 1u;
                    }
                    /* Set next pointer. */
                    USBUART_rxBufferWrite++;

                    /* Check pointer for a loop condition */
                    if(USBUART_rxBufferWrite >= USBUART_RX_BUFFER_SIZE)
                    {
                        USBUART_rxBufferWrite = 0u;
                    }

                    /* Detect pre-overload condition and set flag */
                    if(USBUART_rxBufferWrite == USBUART_rxBufferRead)
                    {
                        USBUART_rxBufferLoopDetect = 1u;
                        /* When Hardware Flow Control selected */
                        #if (USBUART_FLOW_CONTROL != 0u)
                            /* Disable RX interrupt mask, it is enabled when user read data from the buffer using APIs */
                            USBUART_RXSTATUS_MASK_REG  &= (uint8)~USBUART_RX_STS_FIFO_NOTEMPTY;
                            CyIntClearPending(USBUART_RX_VECT_NUM);
                            break; /* Break the reading of the FIFO loop, leave the data there for generating RTS signal */
                        #endif /* (USBUART_FLOW_CONTROL != 0u) */
                    }
                }
            }
        }while((readStatus & USBUART_RX_STS_FIFO_NOTEMPTY) != 0u);

        /* User code required at end of ISR (Optional) */
        /* `#START USBUART_RXISR_END` */

        /* `#END` */

    #if(CY_PSOC3)
        EA = int_en;
    #endif /* (CY_PSOC3) */
    }

#endif /* (USBUART_RX_INTERRUPT_ENABLED && (USBUART_RX_ENABLED || USBUART_HD_ENABLED)) */


#if (USBUART_TX_INTERRUPT_ENABLED && USBUART_TX_ENABLED)
    /*******************************************************************************
    * Function Name: USBUART_TXISR
    ********************************************************************************
    *
    * Summary:
    * Interrupt Service Routine for the TX portion of the UART
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  USBUART_txBuffer - RAM buffer pointer for transmit data from.
    *  USBUART_txBufferRead - cyclic index for read and transmit data
    *     from txBuffer, increments after each transmitted byte.
    *  USBUART_rxBufferWrite - cyclic index for write to txBuffer,
    *     checked to detect available for transmission bytes.
    *
    *******************************************************************************/
    CY_ISR(USBUART_TXISR)
    {
    #if(CY_PSOC3)
        uint8 int_en;
    #endif /* (CY_PSOC3) */

        /* User code required at start of ISR */
        /* `#START USBUART_TXISR_START` */

        /* `#END` */

    #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
        int_en = EA;
        CyGlobalIntEnable;
    #endif /* (CY_PSOC3) */

        while((USBUART_txBufferRead != USBUART_txBufferWrite) &&
             ((USBUART_TXSTATUS_REG & USBUART_TX_STS_FIFO_FULL) == 0u))
        {
            /* Check pointer wrap around */
            if(USBUART_txBufferRead >= USBUART_TX_BUFFER_SIZE)
            {
                USBUART_txBufferRead = 0u;
            }

            USBUART_TXDATA_REG = USBUART_txBuffer[USBUART_txBufferRead];

            /* Set next pointer */
            USBUART_txBufferRead++;
        }

        /* User code required at end of ISR (Optional) */
        /* `#START USBUART_TXISR_END` */

        /* `#END` */

    #if(CY_PSOC3)
        EA = int_en;
    #endif /* (CY_PSOC3) */
    }

#endif /* (USBUART_TX_INTERRUPT_ENABLED && USBUART_TX_ENABLED) */


/* [] END OF FILE */
