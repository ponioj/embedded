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
#include "terminal.h"

void TERMINAL_WriteString(const char8 string[]) {
    while(USBUART_CDCIsReady() == 0);
    USBUART_PutString(string);
}

void TERMINAL_WriteNumber(float number) {
    char8 str2[50];
    sprintf(str2, "Your heartrate: %i    \r",(int)number);
    while(USBUART_CDCIsReady() == 0);
    USBUART_PutString(str2);
}

/* [] END OF FILE */



