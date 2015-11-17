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


/************************************************
 * Method to calculate the heartrate based on 
 * the start and end values of a counter that
 * is driven by interrupts which are driven by
 * the heartbeat.
 * @return heartrate The last recorded heartrate
 ************************************************/
float Detect_heartrate(void) {
    LCD_Position(0,0);
    LCD_PrintString("Heartrate: ");
    LCD_PrintString("      ");
    LCD_Position(1,0);
    /* 600000 because the clock speed of the 
     heartrate is set to kHz */
    heartrate = (600000/(endCounts-startCounts));
    LCD_PrintU32Number(heartrate);
    LCD_PrintString("      ");
    return heartrate;
}

/* [] END OF FILE */
