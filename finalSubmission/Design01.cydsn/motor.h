/* ========================================
 * Method that deals with moving the 
 * motors.
 * ========================================
*/

#ifndef MOTOR_H
#define MOTOR_H

#include "system.h"
    
int speed;
void Start_motor();
void Motor_rampUp(int topSpeed);
void Move_motor(int motorSpeed);
void Motor_stop();
    
#endif

/* [] END OF FILE */

