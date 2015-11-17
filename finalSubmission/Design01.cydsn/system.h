/* ========================================
 * Provides the base system files and 
 * includes for the project. The 
 * file also contains a method that 
 * initializes all system components. If 
 * the system is in a fault state, it 
 * initializes a limited set of 
 * components.
 * ========================================
*/

#ifndef SYSTEM_H
#define SYSTEM_H
    
#include "pushbutton_isr.h"
#include "CapSense.h"
#include "display.h"
#include "CapSense_CSHL.h"
#include "Comp.h"
#include "WaveDAC8_1.h"
#include "PGA_1.h"
#include "Compint.h"
#include "HeartbeatCounter.h"
#include "PWM.h" 
#include "STOP.h"
#include "STOP_REQUEST.h"
       
#include "motor.h"
#include "speaker.h"
#include "display.h"
#include "system.h"
#include "heartrate.h"
#include "Pushbutton.h"
#include "CapSense.h"
#include "CapSense_CSHL.h"
#include <string.h>
#include <stdio.h>
#include "timer_clock_1.h"
#include "terminal.h"
#include "WDT.h"
#include "WDT_Timer.h"
#include "HEARTRATE_HEALTH.h"
#include "MOTOR_HEALTH.h"
#include "UI_HEALTH.h"
    
void System_init();
void System_fault_init();

#endif

/* [] END OF FILE */
