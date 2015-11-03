/*******************************************************************************
* File Name: USBUART_cdc.h
* Version 2.80
*
* Description:
*  Header File for the USBFS component.
*  Contains CDC class prototypes and constant values.
*
* Related Document:
*  Universal Serial Bus Class Definitions for Communication Devices Version 1.1
*
********************************************************************************
* Copyright 2012-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_USBFS_USBUART_cdc_H)
#define CY_USBFS_USBUART_cdc_H

#include "cytypes.h"


/***************************************
* Prototypes of the USBUART_cdc API.
***************************************/

#if (USBUART_ENABLE_CDC_CLASS_API != 0u)
    void USBUART_CDC_Init(void) ;
    void USBUART_PutData(const uint8* pData, uint16 length) ;
    void USBUART_PutString(const char8 string[]) ;
    void USBUART_PutChar(char8 txDataByte) ;
    void USBUART_PutCRLF(void) ;
    uint16 USBUART_GetCount(void) ;
    uint8 USBUART_CDCIsReady(void) ;
    uint8 USBUART_DataIsReady(void) ;
    uint16 USBUART_GetData(uint8* pData, uint16 length) ;
    uint16 USBUART_GetAll(uint8* pData) ;
    uint8 USBUART_GetChar(void) ;
    uint8 USBUART_IsLineChanged(void) ;
    uint32 USBUART_GetDTERate(void) ;
    uint8 USBUART_GetCharFormat(void) ;
    uint8 USBUART_GetParityType(void) ;
    uint8 USBUART_GetDataBits(void) ;
    uint16 USBUART_GetLineControl(void) ;
#endif  /*  USBUART_ENABLE_CDC_CLASS_API */


/***************************************
*  Constants for USBUART_cdc API.
***************************************/

/* CDC Class-Specific Request Codes (CDC ver 1.2 Table 19) */
#define USBUART_CDC_SET_LINE_CODING        (0x20u)
#define USBUART_CDC_GET_LINE_CODING        (0x21u)
#define USBUART_CDC_SET_CONTROL_LINE_STATE (0x22u)

#define USBUART_LINE_CODING_CHANGED        (0x01u)
#define USBUART_LINE_CONTROL_CHANGED       (0x02u)

#define USBUART_1_STOPBIT                  (0x00u)
#define USBUART_1_5_STOPBITS               (0x01u)
#define USBUART_2_STOPBITS                 (0x02u)

#define USBUART_PARITY_NONE                (0x00u)
#define USBUART_PARITY_ODD                 (0x01u)
#define USBUART_PARITY_EVEN                (0x02u)
#define USBUART_PARITY_MARK                (0x03u)
#define USBUART_PARITY_SPACE               (0x04u)

#define USBUART_LINE_CODING_SIZE           (0x07u)
#define USBUART_LINE_CODING_RATE           (0x00u)
#define USBUART_LINE_CODING_STOP_BITS      (0x04u)
#define USBUART_LINE_CODING_PARITY         (0x05u)
#define USBUART_LINE_CODING_DATA_BITS      (0x06u)

#define USBUART_LINE_CONTROL_DTR           (0x01u)
#define USBUART_LINE_CONTROL_RTS           (0x02u)


/***************************************
* External data references
***************************************/

extern volatile uint8 USBUART_lineCoding[USBUART_LINE_CODING_SIZE];
extern volatile uint8 USBUART_lineChanged;
extern volatile uint16 USBUART_lineControlBitmap;
extern volatile uint8 USBUART_cdc_data_in_ep;
extern volatile uint8 USBUART_cdc_data_out_ep;

#endif /*  CY_USBFS_USBUART_cdc_H */


/* [] END OF FILE */
