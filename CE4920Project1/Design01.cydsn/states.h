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
extern int RESET_CAUSE;
float average;
int increasingHr;                         // used as a bool

int PROFILE;
#define PROFILE_REGULAR 0
#define PROFILE_FATBURN 1
#define PROFILE_CARDIO 2


#define STATE_WAIT 0
#define STATE_RESET 1
#define STATE_START 2
#define STATE_PROFILE_SELECTION 3
#define STATE_RAMPUP 4
#define STATE_MOVING 5
#define STATE_HEARTRATE_CHANGE 6
#define STATE_STOP 7

int RESET_CAUSE;
#define RESET_FAULT 0
#define RESET_NORMAL 1
    
/* State functions */
STATE State_wait();

STATE State_reset();

STATE State_start();

STATE State_profile_selection();

STATE State_rampup();

STATE State_moving();

STATE State_heartrate_change();

STATE State_stop();

STATE currentState;

STATE Prev_state;

#endif
