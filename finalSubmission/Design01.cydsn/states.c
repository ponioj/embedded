#include "states.h"

int selectedProfile = 0;
extern float heartbeatCounter;

int MOTOR_RUNNING_SPEED = 50;
int MOTOR_WALKING_SPEED = 300;
int MOTOR_FAST_WALKING_SPEED = 200;
float movingAverage[] =  {0,0,0,0,0,0,0,0,0,0}; 

/************************************************
 * Reset state of the treadmill.
 /**********************************************/
STATE State_reset(){
    int hearthealth = HEARTRATE_HEALTH_Read();
    int motorhealth = MOTOR_HEALTH_Read();
    int uihealth = UI_HEALTH_Read();
    RESET_CAUSE = ((hearthealth && motorhealth && uihealth) > 0);
    if(RESET_CAUSE == RESET_FAULT){
        System_fault_init();
        Display_fault_message();
        Move_motor(0);
        Play_startup_music();
        Prev_state= STATE_RESET;
        currentState = STATE_RESET;
        RESET_CAUSE = RESET_NORMAL; // make it restart normally if reset again
        if (!hearthealth) {
            TERMINAL_WriteString("HEART HEALTH FAILED\n");
        }
        if (!motorhealth) {
            TERMINAL_WriteString("MOTOR FAILED\n");
        }
        if (!uihealth) {
            TERMINAL_WriteString("USER INTERFACE FAILED\n");
        }
        while(1) {
        }
    }
    else if (RESET_CAUSE == RESET_NORMAL) {
        System_init();
        Move_motor(0);
        Display_welcome_message();
        Play_startup_music();
        Prev_state = STATE_RESET;
        currentState = STATE_WAIT;
    }
    return currentState;
}

/************************************************
 * Wait state of the treadmill. Waits for the
 * user to activate the touch slider.
 /**********************************************/
STATE State_wait(){
    LCD_ClearDisplay();
    Motor_stop();
    CapSense_UpdateEnabledBaselines();
    CapSense_ScanEnabledWidgets();
	while(CapSense_IsBusy() != 0);
    if (CapSense_ReadSensorRaw(CapSense_SENSOR_LINEARSLIDER0_E0__LS) > 15000){
        int countDown;
        for (countDown = 10; countDown > 0; countDown--) {
            CapSense_ScanEnabledWidgets();
            if (CapSense_ReadSensorRaw(CapSense_SENSOR_LINEARSLIDER0_E4__LS) > 15000){
                Prev_state = STATE_WAIT;
                currentState = STATE_PROFILE_SELECTION;
            }
            else {
                CyDelay(10);        
            }
        }
    }
    return currentState;
}

/************************************************
 * State for selecting the profile. 
 /**********************************************/
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
            return STATE_RAMPUP;
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

/************************************************
 * State for slowly increasing the motor speed
 * when the treadmill first starts.
 /**********************************************/
STATE State_rampup(){
    int i;
    int delay = 10;
    int rampMax = 80000/MOTOR_WALKING_SPEED;
    for (i=0; i<rampMax; i++){
        Move_motor(i);
        CyDelay(delay);
    }
    currentState = STATE_MOVING;
    return currentState;
}

/************************************************
 * Reset state of the treadmill.
 /**********************************************/
STATE State_moving(){
    Prev_state = STATE_MOVING;
    TERMINAL_WriteNumber(heartrate);
    Detect_heartrate();
    int i;
    for (i=0; i<9; i++){ 
        movingAverage[i]=movingAverage[i+1];
    }
    movingAverage[9]=heartrate;
    int difference = movingAverage[0]-heartrate;
    int change = (difference*difference);
    if ((change)>=100){
        if(difference>0){
            increasingHr = 0;   
        }
        else{
            increasingHr = 1;
        }
        currentState = STATE_HEARTRATE_CHANGE;
    }
    return currentState;   
}

/************************************************
 * State that it enters if the heartrate changes
 * more than 10%. Depending on the profile and 
 * the heartrate, the system reacts according
 * to the profile.
 **********************************************/
STATE State_heartrate_change(){
    Prev_state = STATE_HEARTRATE_CHANGE;
    switch (selectedProfile){
        case PROFILE_REGULAR:
            if (heartrate>100){
                Motor_rampUp(MOTOR_WALKING_SPEED);
            }
            else if (heartrate<80){
                Motor_rampUp(MOTOR_RUNNING_SPEED);
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
/************************************************
 * Stop state if the user hits the emergency
 * stop button. Stops the motors and enteres
 * the wait state. 
 **********************************************/
STATE State_stop(){
    Prev_state = STATE_STOP;
    Motor_stop();
    return STATE_WAIT; 
}

/* [] END OF FILE */