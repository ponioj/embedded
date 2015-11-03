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

#include "display.h"

int loading_bar_speed_ms = 100;


void Display_welcome_message(){
    LCD_ClearDisplay();
    int i;
    for (i=0; i<16; i++){
        LCD_Position(0,i);
        LCD_PutChar(LCD_CUSTOM_5);
        CyDelay(loading_bar_speed_ms);
    }
    LCD_ClearDisplay();
    LCD_Position(0,3);
    LCD_PrintString("Welcome to ");
    LCD_Position(1,2);
    LCD_PrintString("My Treadmill");
}   

/*
void Display_welcome_message(){
    LCD_ClearDisplay();
    LCD_Position(0,0);
    LCD_PrintString("8");
    int i;
    for (i=0; i<14; i++){
        LCD_PrintString("=");
        CyDelay(loading_bar_speed_ms);
    }
    LCD_PrintString("D");
}   
*/
void Display_sleep(){    
    LCD_Position(0,0);
    LCD_PrintString("Sleeping...");
//        LCD_DrawHorizontalBG(0,0,8,i);
//        LCD_PrintString("zzzzzz");
//        CyDelay(1000);
    
}

void Display_profile_selection(int profile){
    int i;
    for (i=4;i>0;i--){
        LCD_ClearDisplay();
        CyDelay(100);
        switch (profile){
            case REGULAR:
                LCD_Position(1,0);
                LCD_PrintString("Regular   ");
                break;
            case LIGHT:
                LCD_Position(1,0);
                LCD_PrintString("Light     ");
                break; 
            case HILLS:
                LCD_Position(1,0);
                LCD_PrintString("Hills     ");
                break;
            case CARDIO:
                LCD_Position(1,0);
                LCD_PrintString("Cardio    ");
                break;
            case FATBURN:
                LCD_Position(1,0);
                LCD_PrintString("Fat Burn  ");
                break;
            default:
                break;
        }
        CyDelay(100);
    }
}


/* [] END OF FILE */
