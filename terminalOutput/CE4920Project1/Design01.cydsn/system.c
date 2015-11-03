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

#include "system.h"


void System_init(){
    Comp_Start();
    Comp_ZeroCal(); 
    LCD_Start();
    CapSense_Start();
    CapSense_Enable();
    CapSense_ScanEnabledWidgets();
    CapSense_InitializeAllBaselines();
    WaveDAC8_1_Start();  
    PGA_1_Start();
    Compint_Start();
    HeartbeatCounter_Start(); 
    timer_clock_1_Start();
    USBUART_Start(0, USBUART_3V_OPERATION);
    TERMINAL_WriteString("Welcome to my treadmill!\n\r");

}

/* [] END OF FILE */
