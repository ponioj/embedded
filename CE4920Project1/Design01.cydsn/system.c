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
    STOP_Start();
    HeartbeatCounter_Start(); 
    timer_clock_1_Start();
    Start_motor();
    WDT_Timer_Start();
    WDT_Start();
    CyWdtStart(CYWDT_1024_TICKS, CYWDT_LPMODE_NOCHANGE);
    USBUART_Start(0, USBUART_3V_OPERATION);
    TERMINAL_WriteString("Welcome to my treadmill!\n\r");
}

void System_fault_init(){
    LCD_Start();
    STOP_Start();
    Start_motor();
    USBUART_Start(0, USBUART_3V_OPERATION);
    TERMINAL_WriteString("ERROR!\n");    
}

/* [] END OF FILE */
