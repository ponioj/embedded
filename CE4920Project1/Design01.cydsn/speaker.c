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

#include "speaker.h"

#define B1 61.735
#define B2 123.27
#define B3 246.94
#define B4 493.88


#define F3S 185
#define F4S 369.99

#define C1 16.352
#define C2 65.406
#define C3 130.81
#define C4 261.63
#define C5 523.25
#define C6 1046.5
#define C7 2093
#define C8 4186


#define D2 73.416
#define D3 146.83
#define D4 293.66

#define E1 41.203
#define E2 82.407
#define E3 164.81
#define E4 329.63

#define G1 48.999
#define G2 97.999
#define G3 196
#define G4 392

#define C3S 138.59
#define C4S 277.18

void Play_startup_music(){
   Play_song_one();
}

void Play_song_one() {
    // F#, C#, B, C#
    // C3 D3 C2 G2
    Play_note(C4, C4/2);
    CyDelay(32);
    Play_note(D3, D3/3);
    CyDelay(64);
    Play_note(C3, C3/2);
    CyDelay(32);
    Play_note(G3, G3/3);
    CyDelay(100);
    int i = B1;
    for (i; i>58; i--){
       Play_note(i, i/2);   
    }
}

void Play_note(float toneFrequency, int duration) {
    int toneHalfPeriod = 0;
    toneHalfPeriod = calculatePeriodDelay( toneFrequency );
    do
    {
        Speaker_Output_Write(1);
        CyDelayUs(toneHalfPeriod);
        Speaker_Output_Write(0);
        CyDelayUs(toneHalfPeriod);
        toneFrequency--; // make this many per second
    }while(toneFrequency > duration); 
}

int calculatePeriodDelay(int frequency) {
    // put a boundary on the frequency
    return (int)(1000000.0/(2.0*frequency)); // type cast to in   
}
/* [] END OF FILE */
