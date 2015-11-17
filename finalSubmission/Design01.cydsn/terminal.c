#include "terminal.h"

/************************************************
 * Method that writes a string to the terminal.
 * @param message[] the string to be written
 ***********************************************/
void TERMINAL_WriteString(const char8 message[]) {
    while(USBUART_CDCIsReady() == 0);
    USBUART_PutString(string);
}

/************************************************
 * Method to write a number to the terminal. 
 * @param number the number to be written
 ***********************************************/
void TERMINAL_WriteNumber(float number) {
    char8 str2[50];
    sprintf(str2, "Your heartrate: %i    \r",(int)number);
    while(USBUART_CDCIsReady() == 0);
    USBUART_PutString(str2);
}

/* [] END OF FILE */



