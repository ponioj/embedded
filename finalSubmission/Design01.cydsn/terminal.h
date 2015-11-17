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
#ifndef TERMINAL_H
#define TERMINAL_H

#include "system.h"
#include "USBUART.h"
    
void TERMINAL_WriteString(const char8 string[]);
void TERMINAL_WriteNumber(float number);   
    
#endif
/* [] END OF FILE */
