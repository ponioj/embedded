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

#ifndef HEARTRATE_H
#define HEARTRATE_H
    
#include "Timer.h"
#include "display.h"
    
float heartrate;
float heartbeatCounter;
int timer_status;   /* 1 for on, 0 for off */
int timer_value;
    
float Detect_heartrate(void);
    
    
#endif

/* [] END OF FILE */
