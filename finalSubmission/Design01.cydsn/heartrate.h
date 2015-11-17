/* ========================================
 * Code that deals with the heartrate. 
 * Requires the interrupts to be enabled.
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
