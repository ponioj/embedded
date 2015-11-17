/*******************************************************************************
* File Name: lcd_test.c
* Version 2.10
*
* Description:
*  This file provides source code for the Character LCD component's API.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CyLib.h"
#include "lcd_test.h"


static void lcd_test_WrDatNib(uint8 nibble) ;
static void lcd_test_WrCntrlNib(uint8 nibble) ;

/* Stores state of component. Indicates whether component is or not
* in enable state.
*/
uint8 lcd_test_enableState = 0u;

uint8 lcd_test_initVar = 0u;


/*******************************************************************************
* Function Name: lcd_test_Init
********************************************************************************
*
* Summary:
*  Performs initialization required for the components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enables a 4-bit interface
*        Clears the display
*        Enables the auto cursor increment
*        Resets the cursor to start position
*  Also, it loads a custom character set to the LCD if it was defined in the customizer.
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
void lcd_test_Init(void) 
{
    /* INIT CODE */
    CyDelay(40u);                                                        /* Delay 40 ms */
    lcd_test_WrCntrlNib(lcd_test_DISPLAY_8_BIT_INIT);    /* Selects 8-bit mode */
    CyDelay(5u);                                                         /* Delay 5 ms */
    lcd_test_WrCntrlNib(lcd_test_DISPLAY_8_BIT_INIT);    /* Selects 8-bit mode */
    CyDelay(15u);                                                        /* Delay 15 ms */
    lcd_test_WrCntrlNib(lcd_test_DISPLAY_8_BIT_INIT);    /* Selects 8-bit mode */
    CyDelay(1u);                                                         /* Delay 1 ms */
    lcd_test_WrCntrlNib(lcd_test_DISPLAY_4_BIT_INIT);    /* Selects 4-bit mode */
    CyDelay(5u);                                                         /* Delay 5 ms */

    lcd_test_WriteControl(lcd_test_CURSOR_AUTO_INCR_ON);    /* Incr Cursor After Writes */
    lcd_test_WriteControl(lcd_test_DISPLAY_CURSOR_ON);      /* Turn Display, Cursor ON */
    lcd_test_WriteControl(lcd_test_DISPLAY_2_LINES_5x10);   /* 2 Lines by 5x10 Characters */
    lcd_test_WriteControl(lcd_test_DISPLAY_CURSOR_OFF);     /* Turn Display, Cursor OFF */
    lcd_test_WriteControl(lcd_test_CLEAR_DISPLAY);          /* Clear LCD Screen */
    lcd_test_WriteControl(lcd_test_DISPLAY_ON_CURSOR_OFF);  /* Turn Display ON, Cursor OFF */
    lcd_test_WriteControl(lcd_test_RESET_CURSOR_POSITION);  /* Set Cursor to 0,0 */
    CyDelay(5u);

    #if(lcd_test_CUSTOM_CHAR_SET != lcd_test_NONE)
        lcd_test_LoadCustomFonts(lcd_test_customFonts);
    #endif /* lcd_test_CUSTOM_CHAR_SET != lcd_test_NONE */
}


/*******************************************************************************
* Function Name: lcd_test_Enable
********************************************************************************
*
* Summary:
*  Turns on the display.
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
* Theory:
*  This function has no effect when it is called the first time as
*  lcd_test_Init() turns on the LCD.
*
*******************************************************************************/
void lcd_test_Enable(void) 
{
    lcd_test_DisplayOn();
    lcd_test_enableState = 1u;
}


/*******************************************************************************
* Function Name: lcd_test_Start
********************************************************************************
*
* Summary:
*  Performs initialization required for the components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enables 4-bit interface
*        Clears the display
*        Enables auto cursor increment
*        Resets the cursor to start position
*  Also, it loads a custom character set to the LCD if it was defined in the customizer.
*  If it was not the first call in this project, then it just turns on the
*  display
*
*
* Parameters:
*  lcd_test_initVar - global variable.
*
* Return:
*  lcd_test_initVar - global variable.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void lcd_test_Start(void) 
{
    /* If not initialized, perform initialization */
    if(lcd_test_initVar == 0u)
    {
        lcd_test_Init();
        lcd_test_initVar = 1u;
    }

    /* Turn on the LCD */
    lcd_test_Enable();
}


/*******************************************************************************
* Function Name: lcd_test_Stop
********************************************************************************
*
* Summary:
*  Turns off the display of the LCD screen.
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
void lcd_test_Stop(void) 
{
    /* Calls LCD Off Macro */
    lcd_test_DisplayOff();
    lcd_test_enableState = 0u;
}


/*******************************************************************************
*  Function Name: lcd_test_Position
********************************************************************************
*
* Summary:
*  Moves the active cursor location to a point specified by the input arguments
*
* Parameters:
*  row:    Specific row of LCD module to be written
*  column: Column of LCD module to be written
*
* Return:
*  None.
*
* Note:
*  This only applies for LCD displays that use the 2X40 address mode.
*  In this case Row 2 starts with a 0x28 offset from Row 1.
*  When there are more than 2 rows, each row must be fewer than 20 characters.
*
*******************************************************************************/
void lcd_test_Position(uint8 row, uint8 column) 
{
    switch (row)
    {
        case (uint8)0:
            lcd_test_WriteControl(lcd_test_ROW_0_START + column);
            break;
        case (uint8) 1:
            lcd_test_WriteControl(lcd_test_ROW_1_START + column);
            break;
        case (uint8) 2:
            lcd_test_WriteControl(lcd_test_ROW_2_START + column);
            break;
        case (uint8) 3:
            lcd_test_WriteControl(lcd_test_ROW_3_START + column);
            break;
        default:
            /* if default case is hit, invalid row argument was passed.*/
            break;
    }
}


/*******************************************************************************
* Function Name: lcd_test_PrintString
********************************************************************************
*
* Summary:
*  Writes a zero terminated string to the LCD.
*
* Parameters:
*  string: Pointer to head of char8 array to be written to the LCD module
*
* Return:
*  None.
*
*******************************************************************************/
void lcd_test_PrintString(char8 const string[]) 
{
    uint8 indexU8 = 1u;
    char8 current = *string;

    /* Until null is reached, print next character */
    while((char8) '\0' != current)
    {
        lcd_test_WriteData((uint8)current);
        current = string[indexU8];
        indexU8++;
    }
}


/*******************************************************************************
*  Function Name: lcd_test_PutChar
********************************************************************************
*
* Summary:
*  Writes a single character to the current cursor position of the LCD module.
*  Custom character names (_CUSTOM_0 through
*  _CUSTOM_7) are acceptable as inputs.
*
* Parameters:
*  character: Character to be written to LCD
*
* Return:
*  None.
*
*******************************************************************************/
void lcd_test_PutChar(char8 character) 
{
    lcd_test_WriteData((uint8)character);
}


/*******************************************************************************
*  Function Name: lcd_test_WriteData
********************************************************************************
*
* Summary:
*  Writes a data byte to the LCD module's Data Display RAM.
*
* Parameters:
*  dByte: Byte to be written to the LCD module
*
* Return:
*  None.
*
*******************************************************************************/
void lcd_test_WriteData(uint8 dByte) 
{
    uint8 nibble;

    lcd_test_IsReady();
    nibble = dByte >> lcd_test_NIBBLE_SHIFT;

    /* Write high nibble */
    lcd_test_WrDatNib(nibble);

    nibble = dByte & lcd_test_NIBBLE_MASK;
    /* Write low nibble */
    lcd_test_WrDatNib(nibble);
}


/*******************************************************************************
*  Function Name: lcd_test_WriteControl
********************************************************************************
*
* Summary:
*  Writes a command byte to the LCD module.
*
* Parameters:
*  cByte:  The byte to be written to theLCD module
* 
* Return:
*  None.
*
*******************************************************************************/
void lcd_test_WriteControl(uint8 cByte) 
{
    uint8 nibble;

    lcd_test_IsReady();

    nibble = cByte >> lcd_test_NIBBLE_SHIFT;
    
    /* WrCntrlNib(High Nibble) */
    lcd_test_WrCntrlNib(nibble);
    nibble = cByte & lcd_test_NIBBLE_MASK;

    /* WrCntrlNib(Low Nibble) */
    lcd_test_WrCntrlNib(nibble);
}


/*******************************************************************************
* Function Name: lcd_test_IsReady
********************************************************************************
*
* Summary:
*  Polls the LCD until the ready bit is set or a timeout occurs.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  Changes the pins to High-Z.
*
*******************************************************************************/
void lcd_test_IsReady(void) 
{
    uint8 value;
    uint32 timeout;
    timeout = lcd_test_READY_DELAY;

    /* Clear LCD port*/
    lcd_test_PORT_DR_REG &= ((uint8)(~lcd_test_PORT_MASK));

    /* PSoC4 has a little different from PSoC3/5 port/pin organization for setting Drive Modes.
  
    */
    #if (CY_PSOC4)
        
        /* Mask off data pins to clear old values out */
        value = lcd_test_PORT_PC_REG & ((uint32) (~ lcd_test_DM_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        lcd_test_PORT_PC_REG = value | lcd_test_HIGH_Z_DATA_DM;

    #else
    
        /* Change Port to High-Z Status on data pins */

        /* Mask off data pins to clear old values out */
        value = lcd_test_PORT_DM0_REG & ((uint8)(~lcd_test_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        lcd_test_PORT_DM0_REG = value | (lcd_test_HIGH_Z_DM0 & lcd_test_DATA_MASK);

        /* Mask off data pins to clear old values out */
        value = lcd_test_PORT_DM1_REG & ((uint8)(~lcd_test_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        lcd_test_PORT_DM1_REG = value;

        /* Mask off data pins to clear old values out */
        value = lcd_test_PORT_DM2_REG & ((uint8)(~lcd_test_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        lcd_test_PORT_DM2_REG = value;
    
    #endif /* CY_PSOC4 */
    
    /* Make sure RS is low */
    lcd_test_PORT_DR_REG &= ((uint8)(~lcd_test_RS));

    /* Set R/W high to read */
    lcd_test_PORT_DR_REG |= lcd_test_RW;

    do
    {
        /* 40 ns delay required before rising Enable and 500ns between neighbour Enables */
        CyDelayUs(0u);

        /* Set E high */
        lcd_test_PORT_DR_REG |= lcd_test_E;

        /* 360 ns delay setup time for data pins */
        CyDelayUs(1u);

        /* Get port state */
        value = lcd_test_PORT_PS_REG;

        /* Set enable low */
        lcd_test_PORT_DR_REG &= ((uint8)(~lcd_test_E));

        /* This gives true delay between disabling Enable bit and polling Ready bit */
        CyDelayUs(0u);

        /* Extract ready bit */
        value &= lcd_test_READY_BIT;

        /* Set E high as we in 4-bit interface we need extra operation */
        lcd_test_PORT_DR_REG |= lcd_test_E;

        /* 360 ns delay setup time for data pins */
        CyDelayUs(1u);

        /* Set enable low */
        lcd_test_PORT_DR_REG &= ((uint8)(~lcd_test_E));

        /* If LCD is not ready make a delay */
        if (value == 0u)
        {
            CyDelayUs(10u);
        }

        /* Repeat until bit 4 is not zero or until timeout. */
        timeout--;

    } while ((value != 0u) && (timeout > 0u));

    /* Set R/W low to write */
    lcd_test_PORT_DR_REG &= ((uint8)(~lcd_test_RW));

    /* Clear LCD port*/
    lcd_test_PORT_DR_REG &= ((uint8)(~lcd_test_PORT_MASK));

    #if (CY_PSOC4)
        
        /* Mask off data pins to clear old values out */
        value = lcd_test_PORT_PC_REG & ((uint32)(~ lcd_test_DM_DATA_MASK));
        /* Load in high Z values for data pins, others unchanged */
        lcd_test_PORT_PC_REG = value | lcd_test_STRONG_DATA_DM;

    #else

        /* Change Port to Output (Strong) on data pins */
        /* Mask off data pins to clear high z values out. Configure data pins 
        * to Strong Drive, others unchanged.
        */
        lcd_test_PORT_DM0_REG &= ((uint8)(~lcd_test_DATA_MASK));
        /* Mask off data pins to clear high z values out */
        value = lcd_test_PORT_DM1_REG & ((uint8)(~lcd_test_DATA_MASK));
        /* Configure data pins to Strong Drive, others unchanged */
        lcd_test_PORT_DM1_REG = value | (lcd_test_STRONG_DM1 & lcd_test_DATA_MASK);

        /* Mask off data pins to clear high z values out */
        value = lcd_test_PORT_DM2_REG & ((uint8)(~lcd_test_DATA_MASK));
        /* Configure data pins to Strong Drive, others unchanged */
        lcd_test_PORT_DM2_REG = value | (lcd_test_STRONG_DM2 & lcd_test_DATA_MASK);
    
    #endif /* CY_PSOC4 */
}


/*******************************************************************************
*  Function Name: lcd_test_WrDatNib
********************************************************************************
*
* Summary:
*  Writes a data nibble to the LCD module.
*
* Parameters:
*  nibble:  Byte containing nibble in the least significant nibble to be
*           written to the LCD module.
*
* Return:
*  None.
*
*******************************************************************************/
static void lcd_test_WrDatNib(uint8 nibble) 
{
    /* RS should be low to select data register */
    lcd_test_PORT_DR_REG |= lcd_test_RS;
    /* Reset RW for write operation */
    lcd_test_PORT_DR_REG &= ((uint8)(~lcd_test_RW));

    /* Guaranteed delay between Setting RS and RW and setting E bits */
    CyDelayUs(0u);
    
    /* Clear data pins */
    lcd_test_PORT_DR_REG &= ((uint8)(~lcd_test_DATA_MASK));

    /* Write data, bring E high */
    #if(0u != lcd_test_PORT_SHIFT) /* MISRA forbids shift by 0 so need to handle that */
        lcd_test_PORT_DR_REG |= 
            (lcd_test_E | ((uint8)(((uint8) nibble) << lcd_test_PORT_SHIFT)));
    #else
        lcd_test_PORT_DR_REG |= (lcd_test_E | nibble);
    #endif /* (0u != lcd_test_PORT_SHIFT) */

    /* Minimum of 230 ns delay */
    CyDelayUs(1u);

    lcd_test_PORT_DR_REG &= ((uint8)(~lcd_test_E));
}


/*******************************************************************************
*  Function Name: lcd_test_WrCntrlNib
********************************************************************************
*
* Summary:
*  Writes a control nibble to the LCD module.
*
* Parameters:
*  nibble: The byte containing a nibble in the four least significant bits.????
*
* Return:
*  None.
*
*******************************************************************************/
static void lcd_test_WrCntrlNib(uint8 nibble) 
{
    /* RS and RW should be low to select instruction register and  write operation respectively */
    lcd_test_PORT_DR_REG &= ((uint8)(~(lcd_test_RS | lcd_test_RW)));

    /* Two following lines of code will give 40ns delay */
    /* Clear data pins */
    lcd_test_PORT_DR_REG &= ((uint8)(~lcd_test_DATA_MASK));

    /* Write control data and set enable signal */
    #if(0u != lcd_test_PORT_SHIFT) /* MISRA forbids shift by 0 so need to handle that */
        lcd_test_PORT_DR_REG |= 
            (lcd_test_E | ((uint8)(((uint8) nibble) << lcd_test_PORT_SHIFT)));
    #else
        lcd_test_PORT_DR_REG |= (lcd_test_E | nibble);
    #endif /* (0u != lcd_test_PORT_SHIFT) */

    /* Minimum of 230 ns delay */
    CyDelayUs(1u);

    lcd_test_PORT_DR_REG &= ((uint8)(~lcd_test_E));
}


#if(lcd_test_CONVERSION_ROUTINES == 1u)

    /*******************************************************************************
    *  Function Name: lcd_test_PrintInt8
    ********************************************************************************
    *
    * Summary:
    *  Print a byte as two ASCII characters.
    *
    * Parameters:
    *  value: The byte to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void lcd_test_PrintInt8(uint8 value) 
    {
        static char8 const CYCODE lcd_test_hex[16u] = "0123456789ABCDEF";
        
        lcd_test_PutChar((char8) lcd_test_hex[value >> lcd_test_BYTE_UPPER_NIBBLE_SHIFT]);
        lcd_test_PutChar((char8) lcd_test_hex[value & lcd_test_BYTE_LOWER_NIBBLE_MASK]);
    }


    /*******************************************************************************
    *  Function Name: lcd_test_PrintInt16
    ********************************************************************************
    *
    * Summary:
    *  Print a uint16 as four ASCII characters.
    *
    * Parameters:
    *  value: The uint16 to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void lcd_test_PrintInt16(uint16 value) 
    {
        lcd_test_PrintInt8((uint8)(value >> lcd_test_U16_UPPER_BYTE_SHIFT));
        lcd_test_PrintInt8((uint8)(value & lcd_test_U16_LOWER_BYTE_MASK));
    }

    
    /*******************************************************************************
    *  Function Name: lcd_test_PrintInt32
    ********************************************************************************
    *
    * Summary:
    *  Print a uint32 hexadecimal number as eight ASCII characters.
    *
    * Parameters:
    *  value: The uint32 to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void lcd_test_PrintInt32(uint32 value) 
    {
        uint8 shift = lcd_test_32_BIT_SHIFT;
        
        while (shift != 0u)
        {
            /* "shift" var is to be subtracted by 8 prior shifting. This implements 
            * shifting by 24, 16, 8 and 0u. 
            */
            shift -= lcd_test_8_BIT_SHIFT;
            
            /* Print 8 bits of uint32 hex number */
            lcd_test_PrintInt8((uint8) ((uint32) (value >> shift)));
        }
    }
    
    
    /*******************************************************************************
    *  Function Name: lcd_test_PrintNumber
    ********************************************************************************
    *
    * Summary:
    *  Print an uint16 value as a left-justified decimal value.
    *
    * Parameters:
    *  value: A 16-bit value to be printed in ASCII characters as a decimal number
    *
    * Return:
    *  None.
    *
    * Note:
    *  This function is implemented as a macro.
    *
    *******************************************************************************/

    
    /*******************************************************************************
    *  Function Name: lcd_test_PrintU32Number
    ********************************************************************************
    *
    * Summary:
    *  Print an uint32 value as a left-justified decimal value.
    *
    * Parameters:
    *  value: A 32-bit value to be printed in ASCII characters as a decimal number
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void lcd_test_PrintU32Number(uint32 value) 
    {
        uint8 tmpDigit;
        char8 number[lcd_test_NUMBER_OF_REMAINDERS_U32 + 1u];
        uint8 digIndex = lcd_test_NUMBER_OF_REMAINDERS_U32;
        
        /* This API will output a decimal number as a string and that string will be 
        * filled from end to start. Set Null termination character first.
        */
        number[digIndex] = (char8) '\0';
        digIndex--;
        
        /* Load these in reverse order */
        while(value >= lcd_test_TEN)
        {
            /* Extract decimal digit, indexed by 'digIndex', from 'value' and
            * convert it to ASCII character.
            */
            tmpDigit = (uint8) (((uint8) (value % lcd_test_TEN)) + (uint8) lcd_test_ZERO_CHAR_ASCII);
            
            /* Temporary variable 'tmpDigit' is used to avoid Violation of MISRA rule 
            * #10.3.
            */
            number[digIndex] = (char8) tmpDigit;
            value /= lcd_test_TEN;
            digIndex--;
        }
        
        /* Extract last decimal digit 'digIndex', from the 'value' and convert it
        * to ASCII character.
        */
        tmpDigit = (uint8) (((uint8)(value % lcd_test_TEN)) + (uint8) lcd_test_ZERO_CHAR_ASCII);
        number[digIndex] = (char8) tmpDigit;

        /* Print out number */
        lcd_test_PrintString(&number[digIndex]);
    }
    
#endif /* lcd_test_CONVERSION_ROUTINES == 1u */


/* [] END OF FILE */
