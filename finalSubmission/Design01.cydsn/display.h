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

/* [] END OF FILE */

#endif
