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
            case STATE_WAIT:
                currentState = State_wait();
                break;
            case STATE_MOVING:
                currentState = State_moving();
                break;
            case STATE_PROFILE_SELECTION:
                currentState = State_profile_selection();
                break;
            case STATE_STOP:
                currentState = State_stop();
                break;
            case STATE_HEARTRATE_CHANGE:
                currentState = State_heartrate_change();
                break;
            case STATE_RAMPUP:
                currentState = State_rampup();
                break;
            default:
                break;
        }
        
    }
    return 0;

}

/* [] END OF FILE */
