/*******************************************************************************
* File Name: lcd_test.h
* Version 2.10
*
* Description:
*  This header file contains registers and constants associated with the
*  Character LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CHARLCD_lcd_test_H)
#define CY_CHARLCD_lcd_test_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define lcd_test_CONVERSION_ROUTINES     (1u)
#define lcd_test_CUSTOM_CHAR_SET         (2u)

/* Custom character set types */
#define lcd_test_NONE                     (0u)    /* No Custom Fonts      */
#define lcd_test_HORIZONTAL_BG            (1u)    /* Horizontal Bar Graph */
#define lcd_test_VERTICAL_BG              (2u)    /* Vertical Bar Graph   */
#define lcd_test_USER_DEFINED             (3u)    /* User Defined Fonts   */


/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} lcd_test_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void lcd_test_Init(void) ;
void lcd_test_Enable(void) ;
void lcd_test_Start(void) ;
void lcd_test_Stop(void) ;
void lcd_test_WriteControl(uint8 cByte) ;
void lcd_test_WriteData(uint8 dByte) ;
void lcd_test_PrintString(char8 const string[]) ;
void lcd_test_Position(uint8 row, uint8 column) ;
void lcd_test_PutChar(char8 character) ;
void lcd_test_IsReady(void) ;
void lcd_test_SaveConfig(void) ;
void lcd_test_RestoreConfig(void) ;
void lcd_test_Sleep(void) ;
void lcd_test_Wakeup(void) ;

#if((lcd_test_CUSTOM_CHAR_SET == lcd_test_VERTICAL_BG) || \
                (lcd_test_CUSTOM_CHAR_SET == lcd_test_HORIZONTAL_BG))

    void  lcd_test_LoadCustomFonts(uint8 const customData[])
                        ;

    void  lcd_test_DrawHorizontalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                         ;

    void lcd_test_DrawVerticalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                        ;

#endif /* ((lcd_test_CUSTOM_CHAR_SET == lcd_test_VERTICAL_BG) */

#if(lcd_test_CUSTOM_CHAR_SET == lcd_test_USER_DEFINED)

    void lcd_test_LoadCustomFonts(uint8 const customData[])
                            ;

#endif /* ((lcd_test_CUSTOM_CHAR_SET == lcd_test_USER_DEFINED) */

#if(lcd_test_CONVERSION_ROUTINES == 1u)

    /* ASCII Conversion Routines */
    void lcd_test_PrintInt8(uint8 value) ;
    void lcd_test_PrintInt16(uint16 value) ;
    void lcd_test_PrintInt32(uint32 value) ;
    void lcd_test_PrintNumber(uint16 value) ; 
    void lcd_test_PrintU32Number(uint32 value) ;
    
#endif /* lcd_test_CONVERSION_ROUTINES == 1u */

/* Clear Macro */
#define lcd_test_ClearDisplay() lcd_test_WriteControl(lcd_test_CLEAR_DISPLAY)

/* Off Macro */
#define lcd_test_DisplayOff() lcd_test_WriteControl(lcd_test_DISPLAY_CURSOR_OFF)

/* On Macro */
#define lcd_test_DisplayOn() lcd_test_WriteControl(lcd_test_DISPLAY_ON_CURSOR_OFF)

#define lcd_test_PrintNumber(value) lcd_test_PrintU32Number((uint16) (value))


/***************************************
*           Global Variables
***************************************/

extern uint8 lcd_test_initVar;
extern uint8 lcd_test_enableState;
extern uint8 const CYCODE lcd_test_customFonts[64u];


/***************************************
*           API Constants
***************************************/

/* Full Byte Commands Sent as Two Nibbles */
#define lcd_test_DISPLAY_8_BIT_INIT       (0x03u)
#define lcd_test_DISPLAY_4_BIT_INIT       (0x02u)
#define lcd_test_DISPLAY_CURSOR_OFF       (0x08u)
#define lcd_test_CLEAR_DISPLAY            (0x01u)
#define lcd_test_CURSOR_AUTO_INCR_ON      (0x06u)
#define lcd_test_DISPLAY_CURSOR_ON        (0x0Eu)
#define lcd_test_DISPLAY_2_LINES_5x10     (0x2Cu)
#define lcd_test_DISPLAY_ON_CURSOR_OFF    (0x0Cu)

#define lcd_test_RESET_CURSOR_POSITION    (0x03u)
#define lcd_test_CURSOR_WINK              (0x0Du)
#define lcd_test_CURSOR_BLINK             (0x0Fu)
#define lcd_test_CURSOR_SH_LEFT           (0x10u)
#define lcd_test_CURSOR_SH_RIGHT          (0x14u)
#define lcd_test_DISPLAY_SCRL_LEFT        (0x18u)
#define lcd_test_DISPLAY_SCRL_RIGHT       (0x1Eu)
#define lcd_test_CURSOR_HOME              (0x02u)
#define lcd_test_CURSOR_LEFT              (0x04u)
#define lcd_test_CURSOR_RIGHT             (0x06u)

/* Point to Character Generator Ram 0 */
#define lcd_test_CGRAM_0                  (0x40u)

/* Point to Display Data Ram 0 */
#define lcd_test_DDRAM_0                  (0x80u)

/* LCD Characteristics */
#define lcd_test_CHARACTER_WIDTH          (0x05u)
#define lcd_test_CHARACTER_HEIGHT         (0x08u)

#if(lcd_test_CONVERSION_ROUTINES == 1u)
    #define lcd_test_NUMBER_OF_REMAINDERS_U32 (0x0Au)
    #define lcd_test_TEN                      (0x0Au)
    #define lcd_test_8_BIT_SHIFT              (8u)
    #define lcd_test_32_BIT_SHIFT             (32u)
    #define lcd_test_ZERO_CHAR_ASCII          (48u)
#endif /* lcd_test_CONVERSION_ROUTINES == 1u */

/* Nibble Offset and Mask */
#define lcd_test_NIBBLE_SHIFT             (0x04u)
#define lcd_test_NIBBLE_MASK              (0x0Fu)

/* LCD Module Address Constants */
#define lcd_test_ROW_0_START              (0x80u)
#define lcd_test_ROW_1_START              (0xC0u)
#define lcd_test_ROW_2_START              (0x94u)
#define lcd_test_ROW_3_START              (0xD4u)

/* Custom Character References */
#define lcd_test_CUSTOM_0                 (0x00u)
#define lcd_test_CUSTOM_1                 (0x01u)
#define lcd_test_CUSTOM_2                 (0x02u)
#define lcd_test_CUSTOM_3                 (0x03u)
#define lcd_test_CUSTOM_4                 (0x04u)
#define lcd_test_CUSTOM_5                 (0x05u)
#define lcd_test_CUSTOM_6                 (0x06u)
#define lcd_test_CUSTOM_7                 (0x07u)

/* Other constants */
#define lcd_test_BYTE_UPPER_NIBBLE_SHIFT  (0x04u)
#define lcd_test_BYTE_LOWER_NIBBLE_MASK   (0x0Fu)
#define lcd_test_U16_UPPER_BYTE_SHIFT     (0x08u)
#define lcd_test_U16_LOWER_BYTE_MASK      (0xFFu)
#define lcd_test_CUSTOM_CHAR_SET_LEN      (0x40u)

#define lcd_test_LONGEST_CMD_US           (0x651u)
#define lcd_test_WAIT_CYCLE               (0x10u)
#define lcd_test_READY_DELAY              ((lcd_test_LONGEST_CMD_US * 4u)/(lcd_test_WAIT_CYCLE))


/***************************************
*             Registers
***************************************/

/* Device specific registers */
#if (CY_PSOC4)

    #define lcd_test_PORT_DR_REG           (*(reg32 *) lcd_test_LCDPort__DR)  /* Data Output Register */
    #define lcd_test_PORT_DR_PTR           ( (reg32 *) lcd_test_LCDPort__DR)
    #define lcd_test_PORT_PS_REG           (*(reg32 *) lcd_test_LCDPort__PS)  /* Pin State Register */
    #define lcd_test_PORT_PS_PTR           ( (reg32 *) lcd_test_LCDPort__PS)
    
    #define lcd_test_PORT_PC_REG           (*(reg32 *) lcd_test_LCDPort__PC)
    #define lcd_test_PORT_PC_PTR           (*(reg32 *) lcd_test_LCDPort__PC)
    
#else

    #define lcd_test_PORT_DR_REG           (*(reg8 *) lcd_test_LCDPort__DR)  /* Data Output Register */
    #define lcd_test_PORT_DR_PTR           ( (reg8 *) lcd_test_LCDPort__DR)
    #define lcd_test_PORT_PS_REG           (*(reg8 *) lcd_test_LCDPort__PS)  /* Pin State Register */
    #define lcd_test_PORT_PS_PTR           ( (reg8 *) lcd_test_LCDPort__PS)

    #define lcd_test_PORT_DM0_REG          (*(reg8 *) lcd_test_LCDPort__DM0) /* Port Drive Mode 0 */
    #define lcd_test_PORT_DM0_PTR          ( (reg8 *) lcd_test_LCDPort__DM0)
    #define lcd_test_PORT_DM1_REG          (*(reg8 *) lcd_test_LCDPort__DM1) /* Port Drive Mode 1 */
    #define lcd_test_PORT_DM1_PTR          ( (reg8 *) lcd_test_LCDPort__DM1)
    #define lcd_test_PORT_DM2_REG          (*(reg8 *) lcd_test_LCDPort__DM2) /* Port Drive Mode 2 */
    #define lcd_test_PORT_DM2_PTR          ( (reg8 *) lcd_test_LCDPort__DM2)

#endif /* CY_PSOC4 */


/***************************************
*       Register Constants
***************************************/

/* SHIFT must be 1 or 0 */
#if (0 == lcd_test_LCDPort__SHIFT)
    #define lcd_test_PORT_SHIFT               (0x00u)
#else
    #define lcd_test_PORT_SHIFT               (0x01u)
#endif /* (0 == lcd_test_LCDPort__SHIFT) */

#define lcd_test_PORT_MASK                ((uint8) (lcd_test_LCDPort__MASK))

#if (CY_PSOC4)

    #define lcd_test_DM_PIN_STEP              (3u)
    /* Hi-Z Digital is defined by the value of "001b" and this should be set for
    * four data pins, in this way we get - 0x00000249. A similar Strong drive
    * is defined with "110b" so we get 0x00000DB6.
    */
    #define lcd_test_HIGH_Z_DATA_DM           ((0x00000249ul) << (lcd_test_PORT_SHIFT *\
                                                                          lcd_test_DM_PIN_STEP))
    #define lcd_test_STRONG_DATA_DM           ((0x00000DB6ul) << (lcd_test_PORT_SHIFT *\
                                                                          lcd_test_DM_PIN_STEP))
    #define lcd_test_DATA_PINS_MASK           (0x00000FFFul)
    #define lcd_test_DM_DATA_MASK             ((uint32) (lcd_test_DATA_PINS_MASK << \
                                                      (lcd_test_PORT_SHIFT * lcd_test_DM_PIN_STEP)))

#else

    /* Drive Mode register values for High Z */
    #define lcd_test_HIGH_Z_DM0               (0xFFu)
    #define lcd_test_HIGH_Z_DM1               (0x00u)
    #define lcd_test_HIGH_Z_DM2               (0x00u)

    /* Drive Mode register values for High Z Analog */
    #define lcd_test_HIGH_Z_A_DM0             (0x00u)
    #define lcd_test_HIGH_Z_A_DM1             (0x00u)
    #define lcd_test_HIGH_Z_A_DM2             (0x00u)

    /* Drive Mode register values for Strong */
    #define lcd_test_STRONG_DM0               (0x00u)
    #define lcd_test_STRONG_DM1               (0xFFu)
    #define lcd_test_STRONG_DM2               (0xFFu)

#endif /* CY_PSOC4 */

/* Pin Masks */
#define lcd_test_RS                     ((uint8) \
                                                (((uint8) 0x20u) << lcd_test_LCDPort__SHIFT))
#define lcd_test_RW                     ((uint8) \
                                                (((uint8) 0x40u) << lcd_test_LCDPort__SHIFT))
#define lcd_test_E                      ((uint8) \
                                                (((uint8) 0x10u) << lcd_test_LCDPort__SHIFT))
#define lcd_test_READY_BIT              ((uint8) \
                                                (((uint8) 0x08u) << lcd_test_LCDPort__SHIFT))
#define lcd_test_DATA_MASK              ((uint8) \
                                                (((uint8) 0x0Fu) << lcd_test_LCDPort__SHIFT))

/* These names are obsolete and will be removed in future revisions */
#define lcd_test_PORT_DR                  lcd_test_PORT_DR_REG
#define lcd_test_PORT_PS                  lcd_test_PORT_PS_REG
#define lcd_test_PORT_DM0                 lcd_test_PORT_DM0_REG
#define lcd_test_PORT_DM1                 lcd_test_PORT_DM1_REG
#define lcd_test_PORT_DM2                 lcd_test_PORT_DM2_REG


/***************************************
*       Obsolete function names
***************************************/
#if(lcd_test_CONVERSION_ROUTINES == 1u)
    /* This function names are obsolete and will be removed in future 
    * revisions of the component.
    */
    #define lcd_test_PrintDecUint16(x)   lcd_test_PrintNumber(x)  
    #define lcd_test_PrintHexUint8(x)    lcd_test_PrintInt8(x)
    #define lcd_test_PrintHexUint16(x)   lcd_test_PrintInt16(x)        

#endif /* lcd_test_CONVERSION_ROUTINES == 1u */

#endif /* CY_CHARLCD_lcd_test_H */


/* [] END OF FILE */
