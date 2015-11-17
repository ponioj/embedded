#include "display.h"

int loading_bar_speed_ms = 100;

/************************************************
 * Method that displays a welcome message to the
 * user. It first displays a loading bar then
 * displays "Welcome to My Treadmill"
 ***********************************************/
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

/************************************************
 * Method that displays a fault message. It has
 * a similar loading bar to the welcome message,
 * but eventually displays "COMPONENT FAILED DO
 * NOT USE"
 ***********************************************/
void Display_fault_message(){
    LCD_ClearDisplay();
    int i;
    for (i=0; i<16; i++){
        LCD_Position(0,i);
        LCD_PutChar(LCD_CUSTOM_5);
        CyDelay(loading_bar_speed_ms);
    }
    LCD_ClearDisplay();
    LCD_Position(0,0);
    LCD_PrintString("COMPONENT FAILED");
    LCD_Position(1,0);
    LCD_PrintString("  DO NOT USE!!  ");
}   

/************************************************
 * Displays the profile based on what option
 * the user is on when selecting profiles.
 ***********************************************/
void Display_profile_selection(int profile){
    int i;
    for (i=4;i>0;i--){
        LCD_ClearDisplay();
        CyDelay(100);
        switch (profile){
            case PROFILE_REGULAR:
                LCD_Position(1,0);
                LCD_PrintString("Regular   ");
                break;
            case PROFILE_CARDIO:
                LCD_Position(1,0);
                LCD_PrintString("Cardio    ");
                break;
            case PROFILE_FATBURN:
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
