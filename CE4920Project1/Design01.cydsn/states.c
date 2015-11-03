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

int MOTOR_RUNNING_SPEED = 50;
int MOTOR_WALKING_SPEED = 300;
int MOTOR_FAST_WALKING_SPEED = 200;
float movingAverage[] =  {0,0,0,0,0,0,0,0,0,0}; 


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
            selectedProfile = 2;   
        }
    }
    else if (CapSense_CheckIsWidgetActive(CapSense_BUTTON1__BTN)) {
            Display_profile_selection(selectedProfile);
            return STATE_MOVING;
    }
    switch (selectedProfile){
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
    return STATE_PROFILE_SELECTION;   
}

STATE State_moving(){
    Prev_state = STATE_MOVING;
    Detect_heartrate();
    int i;
    for (i=0; i<9; i++){ 
        movingAverage[i]=movingAverage[i+1];
    }
    movingAverage[9]=heartrate;
    int difference = movingAverage[0]-heartrate;
    int change = (difference*difference);
    LCD_Position(0,0);
    int average=0;
    for (i=0; i<10; i++){
        average +=movingAverage[i];
    }
    average /= 10;
    LCD_PrintNumber(difference);
    LCD_PrintString("      ");
    if ((change)>=100){
        if(difference>0){
            increasingHr = 0;   
        }
        else{
            increasingHr = 1;
        }
        LCD_Position(1,5);
        LCD_PrintNumber(increasingHr);
        currentState = STATE_HEARTRATE_CHANGE;
    }
    CyDelay(100);
    return currentState;   
}

STATE State_heartrate_change(){
    Prev_state = STATE_HEARTRATE_CHANGE;
    LCD_Position(0,9);
    LCD_PrintNumber(selectedProfile);
    switch (selectedProfile){
        case PROFILE_REGULAR:
            if (heartrate>100){
                Motor_rampUp(MOTOR_WALKING_SPEED);
                LCD_Position(0,0);
                LCD_PrintString("Walking");
            }
            else if (heartrate<80){
                Motor_rampUp(MOTOR_RUNNING_SPEED);
                LCD_Position(0,0);
                LCD_PrintString("Running");
            }
            break;
        case PROFILE_CARDIO:
            if (heartrate>180){
                Motor_rampUp(MOTOR_WALKING_SPEED);
            }
            else if (heartrate<120){
                Motor_rampUp(MOTOR_RUNNING_SPEED);
            }
            break;
        case PROFILE_FATBURN:
            if (heartrate>100){
                Motor_rampUp(MOTOR_FAST_WALKING_SPEED);
            }
            else if (heartrate<60){
                Motor_rampUp(MOTOR_RUNNING_SPEED);
            }
            break;
        default:
            break;
    }
    return STATE_MOVING;   
}

STATE State_stop(){
    Prev_state = STATE_STOP;
    Motor_stop();
    return STATE_SLEEP; 
}



/* [] END OF FILE */
