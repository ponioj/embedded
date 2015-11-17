/* ========================================
 * File that deals with displaying 
 * information on the LCD.
 * ========================================
*/

#ifndef DISPLAY_H
#define DISPLAY_H
    
#include "LCD.h"
#include "CyLib.h"
#include "lcd_test.h"
#include "states.h"

void Display_welcome_message();

void Display_fault_message();

void Display_sleep();

void Display_flash_profile();

void Display_profile_selection(int profile);

#endif

/* [] END OF FILE */

