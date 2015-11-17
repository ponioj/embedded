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

#ifndef MOTOR_H
#define MOTOR_H

#include "system.h"
    
int speed;
void Start_motor();
void Motor_rampUp(int topSpeed);
void Move_motor(int motorSpeed);
void Motor_stop();
    

/* [] END OF FILE */

#endif
