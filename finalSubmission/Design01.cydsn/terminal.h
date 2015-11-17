/* ========================================
 * File for UART terminal interaction.
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
