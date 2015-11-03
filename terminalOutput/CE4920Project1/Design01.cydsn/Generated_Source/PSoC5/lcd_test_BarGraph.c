/*******************************************************************************
* File Name: lcd_test_BarGraph.c
* Version 2.10
*
* Description:
*  This file provides the custom character data and API for creating and using
*  bar graphs with the Character LCD component.
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


uint8 const CYCODE lcd_test_customFonts[] = \
{
    /* Character lcd_test_CUSTOM_0   */
    0x00u,    0x00u,    0x00u,    0x00u,    0x00u,    0x00u,    0x00u,    0x1Fu, \
    /* Character lcd_test_CUSTOM_1   */
    0x00u,    0x00u,    0x00u,    0x00u,    0x00u,    0x00u,    0x1Fu,    0x1Fu, \
    /* Character lcd_test_CUSTOM_2   */
    0x00u,    0x00u,    0x00u,    0x00u,    0x00u,    0x1Fu,    0x1Fu,    0x1Fu, \
    /* Character lcd_test_CUSTOM_3   */
    0x00u,    0x00u,    0x00u,    0x00u,    0x1Fu,    0x1Fu,    0x1Fu,    0x1Fu, \
    /* Character lcd_test_CUSTOM_4   */
    0x00u,    0x00u,    0x00u,    0x1Fu,    0x1Fu,    0x1Fu,    0x1Fu,    0x1Fu, \
    /* Character lcd_test_CUSTOM_5   */
    0x00u,    0x00u,    0x1Fu,    0x1Fu,    0x1Fu,    0x1Fu,    0x1Fu,    0x1Fu, \
    /* Character lcd_test_CUSTOM_6   */
    0x00u,    0x1Fu,    0x1Fu,    0x1Fu,    0x1Fu,    0x1Fu,    0x1Fu,    0x1Fu, \
    /* Character lcd_test_CUSTOM_7   */
    0x1Fu,    0x1Fu,    0x1Fu,    0x1Fu,    0x1Fu,    0x1Fu,    0x1Fu,    0x1Fu \
};


/*******************************************************************************
* Function Name: lcd_test_LoadCustomFonts
********************************************************************************
*
* Summary:
*  Loads 8 custom font characters into the LCD Module for use.  Cannot use
*  characters from two different font sets at once, but font sets can be
*  switched out during runtime.
*
* Parameters:
*  customData:  pointer to a constant array of 64 bytes representing 8 custom
*               font characters.
* Return:
*  None.
*
* Theory:
*  Prior to using this function user need to import the pointer to custom
*  font array to your project by writting the following in the source code file
*  where custom font will be used:
*       extern uint8 const CYCODE LCD_Char_customFonts[];
*  This function is not automatically called by the Start() routine and must be
*  called manually by the user.
*******************************************************************************/
void lcd_test_LoadCustomFonts(uint8 const customData[]) 
{
    uint8 indexU8;

    lcd_test_IsReady();
    /* Set starting address in the LCD Module */
    /* Optionally: Read the current address to restore at a later time */
    lcd_test_WriteControl(lcd_test_CGRAM_0);

    /* Load in the 64 bytes of CustomChar Data */
    for(indexU8 = 0u; indexU8 < lcd_test_CUSTOM_CHAR_SET_LEN; indexU8++)
    {
        /* Delay between each write */
        lcd_test_WriteData(customData[indexU8]);
    }

    lcd_test_IsReady();
    lcd_test_WriteControl(lcd_test_DDRAM_0);
}


#if (lcd_test_CUSTOM_CHAR_SET == lcd_test_HORIZONTAL_BG)

    /*******************************************************************************
    * Function Name: lcd_test_DrawHorizontalBG
    ********************************************************************************
    *
    * Summary:
    *  Draws the horizontal bargraph.
    *
    * Parameters:
    *  row:            The row in which the bar graph starts.
    *  column:         The column in which the bar graph starts.
    *  maxCharacters:  The max length of the graph in whole characters.
    *  value:          The current length or height of the graph in pixels.
    *
    * Return:
    *  void.
    *
    *******************************************************************************/
    void lcd_test_DrawHorizontalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value) \
                                                            
    {
        /* 8-bit Counter */
        uint8 count8;
        uint8 fullChars;
        uint8 remainingPixels;

        /* Number of full characters to draw */
        fullChars = value / lcd_test_CHARACTER_WIDTH;

        /* Number of remaining pixels to draw */
        remainingPixels = value % lcd_test_CHARACTER_WIDTH;

        /* Ensure that the maximum character limit is followed. */
        if(fullChars >= maxCharacters)
        {
            fullChars = maxCharacters;
        }

        /* Put Cursor at start position */
        lcd_test_Position(row, column);

        /* Write full characters */
        for(count8 = 0u; count8 < fullChars; count8++)
        {
            lcd_test_WriteData(lcd_test_CUSTOM_5);
        }

        if(fullChars < maxCharacters)
        {
            /* Write remaining pixels */
            lcd_test_WriteData(remainingPixels);

            if(fullChars < (maxCharacters - 1u))
            {
                /* Fill with whitespace to end of bar graph */
                for(count8 = 0u; count8 < (maxCharacters - fullChars - 1u); count8++)
                {
                    lcd_test_WriteData(lcd_test_CUSTOM_0);
                }
            }
        }
    }

#endif /* lcd_test_CUSTOM_CHAR_SET == lcd_test_HORIZONTAL_BG */


#if (lcd_test_CUSTOM_CHAR_SET == lcd_test_VERTICAL_BG)

    /*******************************************************************************
    *  Function Name: lcd_test_DrawVerticalBG
    ********************************************************************************
    *
    * Summary:
    *  Draws the vertical bargraph.
    *
    * Parameters:
    *  row:            The row in which the bar graph starts.
    *  column:         The column in which the bar graph starts.
    *  maxCharacters:  The max height of the graph in whole characters.
    *  value:          The current length or height of the graph in pixels.
    *
    * Return:
    *  void.
    *
    *******************************************************************************/
    void lcd_test_DrawVerticalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value) \
                                                            
    {
        /* 8-bit Counter */
        uint8 count8 = 0u;
        /* Current Row Tracker */
        int8 currentRow;
        uint8 fullChars;
        uint8 remainingPixels;

        /* Number of full characters to draw */
        fullChars = value / lcd_test_CHARACTER_HEIGHT;

        /* Number of remaining pixels to draw */
        remainingPixels = value % lcd_test_CHARACTER_HEIGHT;

        /* Put Cursor at start position */
        lcd_test_Position(row, column);

        /* Make sure the bar graph fits inside the space allotted */
        if(fullChars >= maxCharacters)
        {
            fullChars = maxCharacters;
        }

        /*  Write full characters */
        while(count8 < fullChars)
        {
            lcd_test_WriteData(lcd_test_CUSTOM_7);

            count8++;

            /* Each pass through, move one row higher */
            if((((int8) row) - ((int8) count8)) >= 0)
            {
                lcd_test_Position(row - count8, column);
            }
            else
            {
                break;
            }
        }

        if(((((int8) row) - ((int8) count8)) >= 0) && (fullChars < maxCharacters))
        {
            /* Write remaining pixels */
            if(remainingPixels == 0u)
            {
                lcd_test_WriteData((uint8) ' ');
            }
            else
            {
                lcd_test_WriteData(remainingPixels - 1u);
            }

            currentRow = ((int8) row) - ((int8) count8) - 1;

            if(currentRow >= 0)
            {
                /* Move up one row and fill with whitespace till top of bar graph */
                for(count8 = 0u; count8 < (maxCharacters - fullChars - 1u); count8++)
                {
                    lcd_test_Position((uint8)currentRow, column);
                    lcd_test_WriteData((uint8) ' ');
                    currentRow --;
                }
            }
        }
    }

#endif /* lcd_test_CUSTOM_CHAR_SET == lcd_test_VERTICAL_BG */


/* [] END OF FILE */
