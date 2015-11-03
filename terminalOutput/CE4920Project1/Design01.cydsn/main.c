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
#include <project.h>
#include "states.h"
/* State types and variables */

extern STATE currentState;

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

   
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    currentState = STATE_RESET;
    LCD_ClearDisplay();
    for(;;)
    {      
        /* Place your application code here. */            
        switch (currentState) {
            case STATE_RESET:
                currentState = State_reset();
                break;
            case STATE_START:
                currentState = State_start();
                break; 
            case STATE_SLEEP:
                currentState = State_sleep();
                break;
            case STATE_MOVING:
                currentState = State_moving();
                break;
            case STATE_PROFILE_SELECTION:
                currentState = State_profile_selection();
                break;
            default:
                break;
        }
        
    }
    return 0;

}

/* [] END OF FILE */
