#include "motor.h"

/************************************************
 * Method that allows the PWM to start 
 * sending out a signal.
 ***********************************************/
void Start_motor(){
    PWM_Start();
}

/************************************************
 * Method that ramps the motor up to the passed
 * in speed.
 * @param topSpeed the ending value to write to
 *                  the PWM
 ***********************************************/
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

/************************************************
 * Method to stop the motor over 2 seconds.
 ***********************************************/
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
}

/************************************************
 * Method that sets the motor's PWM value to 
 * the passed in value.
 * @param motorSpeed The PWM value for the motor
 *                      speed
 ***********************************************/
void Move_motor(int motorSpeed){
    speed = motorSpeed;
    PWM_WriteCompare(motorSpeed);
}

/* [] END OF FILE */
