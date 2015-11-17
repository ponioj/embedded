/* ========================================
 * File that deals with playing sounds. 
 * ========================================
*/

#ifndef SPEAKER_H
#define SPEAKER_H
    
void Play_startup_music();
void Play_note(float toneFrequency, int duration);
void Play_song_one();
int calculatePeriodDelay(int frequency);

#endif

/* [] END OF FILE */

