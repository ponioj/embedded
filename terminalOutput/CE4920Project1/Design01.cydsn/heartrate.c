/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "heartrate.h"
extern int startCounts;
extern int endCounts;
int ht;


float Detect_heartrate(void) {
//    while((Timer_ReadStatusRegister() & Timer_STATUS_TC) == 0)
    LCD_Position(0,0);
    LCD_PrintString("Heartrate: ");  
    LCD_Position(1,0);
    heartrate = (600000/(endCounts-startCounts));
    LCD_PrintU32Number(heartrate);
    LCD_PrintString("     ");
//    LCD_Position(1,5);
//    LCD_Position(0,0);
//    LCD_PrintString("en: ");
//    LCD_PrintU32Number(endCounts);
//    LCD_PrintString("  ");
//    LCD_Position(1,0);
//    LCD_PrintString("st: ");
//    LCD_PrintU32Number(startCounts);
    TERMINAL_WriteNumber(heartrate);
    return heartrate;
}


/* [] END OF FILE */
