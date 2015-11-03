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

#include "motor.h"

void Start_motor(){
    PWM_Start();
//    Move_motor(500);
}

void Motor_rampUp(int topSpeed){
    int i;
    if (speed < topSpeed){
        for(i=speed; i<topSpeed; i++){
            Move_motor(i);
            CyDelay(10);
        }
    } else {
        for(i=speed; i>topSpeed; i--){
            Move_motor(i);
            CyDelay(10);
        }   
    }
}

/*
    stops motor over 2 seconds
*/
void Motor_stop(){    
    int delay = 100;        // 100ms delay between each decrement
    int time = 2000;        // 2 seconds total motor stop time
    int decrementer = speed/(time/delay);
    int i;
    for (i=speed; i>0; (i-=decrementer)){
        Move_motor(i);
        CyDelay(delay);
    }
    Move_motor(0);          // just to ensure it's stopped
    LCD_Position(1,0);
}

void Move_motor(int motorSpeed){
    speed = motorSpeed;
    PWM_WritePeriod(motorSpeed);
}

/* [] END OF FILE */
