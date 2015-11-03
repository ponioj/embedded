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
extern int speed;


float Detect_heartrate(void) {
    LCD_Position(0,0);
    LCD_PrintString("Heartrate: ");
    heartrate = (600000/(endCounts-startCounts));
    LCD_Position(1,0);
    LCD_PrintU32Number(heartrate);
    LCD_PrintString("   ");
//    TERMINAL_WriteNumber(heartrate);
    Move_motor(heartrate);
    return heartrate;
}


/* [] END OF FILE */
