/* ========================================
 *
 * Copyright John Ponio 2015
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF JOHN PONIO.
 *
 * ========================================
*/
#ifndef STATES_H
#define STATES_H

#include "system.h"

typedef int STATE;
typedef char * string;
    
extern float heartrate;

#define STATE_SLEEP 0
#define STATE_RESET 1
#define STATE_START 2
#define STATE_PROFILE_SELECTION 3
#define STATE_MOVING 4
#define STATE_HEARTRATE_CHANGE 5
#define STATE_STOP 6

/* State functions */
STATE State_sleep();

STATE State_reset();

STATE State_start();

STATE State_profile_selection();

STATE State_moving();

STATE State_heartrate_change();

STATE State_stop();

STATE currentState;

STATE Prev_state;

#define REGULAR 0
#define LIGHT 1
#define HILLS 2
#define CARDIO 3
#define FATBURN 4

    /*
profile[0] = "REGULAR";
profile[1] = "LIGHT";
profile[2] = "HILLS";
profile[3] = "CARDIO";
profile[4] = "FAT BURN";
    */
/* [] END OF FILE */

#endif
