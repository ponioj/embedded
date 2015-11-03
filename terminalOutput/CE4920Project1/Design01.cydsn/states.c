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
#include "states.h"

int selectedProfile = 0;
extern float heartbeatCounter;

STATE State_sleep(){
    LCD_ClearDisplay();
    Display_sleep();
    CapSense_UpdateEnabledBaselines();
    CapSense_ScanEnabledWidgets();
	while(CapSense_IsBusy() != 0);
    if (CapSense_ReadSensorRaw(CapSense_SENSOR_LINEARSLIDER0_E0__LS) > 15000){
        int countDown;
        for (countDown = 10; countDown > 0; countDown--) {
            CapSense_ScanEnabledWidgets();
            if (CapSense_ReadSensorRaw(CapSense_SENSOR_LINEARSLIDER0_E4__LS) > 15000){
                Prev_state = STATE_SLEEP;
                LCD_ClearDisplay();
                currentState = STATE_PROFILE_SELECTION;
            }
            else {
                CyDelay(10);        
            }
        }
    }
    return currentState;
}

STATE State_reset(){
    System_init();
    Display_welcome_message();
    Play_startup_music();
    Prev_state = STATE_RESET;
    LCD_Position(0,0);
    LCD_PrintString("RESET");
    return STATE_START;
}

STATE State_start(){
    LCD_PrintString("START");
    Prev_state = STATE_START;
    return STATE_PROFILE_SELECTION;   
}

STATE State_profile_selection(){
    if(Prev_state == STATE_PROFILE_SELECTION) {
        LCD_Position(0,0); 
    }
    else {
        LCD_ClearDisplay();  
        LCD_PrintString("Select a profile..");
        Prev_state = STATE_PROFILE_SELECTION;
        
    }
    LCD_Position(1,0);
    CapSense_UpdateEnabledBaselines();
    CapSense_ScanEnabledWidgets();
    while(CapSense_IsBusy() != 0);
    
    if (CapSense_CheckIsWidgetActive(CapSense_BUTTON0__BTN)) {
        if (selectedProfile >= 0) {
            selectedProfile--;
            CyDelay(500);
        }
        else {
            selectedProfile = 5;   
        }
    }
    else if (CapSense_CheckIsWidgetActive(CapSense_BUTTON1__BTN)) {
            Display_profile_selection(selectedProfile);
            Motor_rampUp();
            return STATE_MOVING;
    }
    switch (selectedProfile){
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
    return STATE_PROFILE_SELECTION;   
}

STATE State_moving(){
    Prev_state = STATE_MOVING;
    /* wait for a detection of heartrate change */
    //Detect_heartrate();
    LCD_Position(0,0);
//    LCD_PrintU32Number(heartrate);
 //   LCD_PrintString("    ")
    Detect_heartrate();
    return STATE_MOVING;   
}

STATE State_heartrate_change(){
    Prev_state = STATE_HEARTRATE_CHANGE;
    return STATE_MOVING;   
}




/* [] END OF FILE */
