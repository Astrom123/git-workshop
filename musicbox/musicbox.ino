#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUTTON_MEL_ONE 3
#define PIN_BUTTON_OFF 7
#define PIN_BUZZER 6

Button buttonMelodyOne(PIN_BUTTON_MEL_ONE);
Button buttonOff(PIN_BUTTON_OFF);
Buzzer buzzer(PIN_BUZZER);

int notes[] = {NOTE_A4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
double durations[] = {8, 1, 4, 1};
int melodyLength = 4;

// maybe somewhere in the future we will have one more button...
#define PIN_BUTTON_MEL_TWO 4
#define PIN_BUTTON_MEL_THREE 5

Button buttonMelodyTwo(PIN_BUTTON_MEL_TWO);
Button buttonMelodyThree(PIN_BUTTON_MEL_THREE);

//and the second melody
int notes2[] = {NOTE_C4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
double durations2[] = {4, 1, 4, 1};
int melodyLength2 = 4;

int notesThree[] = {NOTE_CS2, NOTE_B1, NOTE_D1, NOTE_G4, NOTE_FS2, NOTE_B0, NOTE_D5};
double durationsThree[] = {5, 2, 5, 2, 7, 4, 7};
int melodyLengthThree = 7;

void setup()
{
    buzzer.setMelody(notes, durations, melodyLength);
}

void loop()
{
    buzzer.playSound();

    if (buttonOff.wasPressed())
    {
        buzzer.turnSoundOff();
    }

    if (buttonMelodyOne.wasPressed())
    {
        buzzer.setMelody(notes, durations, melodyLength);
        buzzer.turnSoundOn();
    }

    if (buttonMelodyTwo.wasPressed()) 
    {
        buzzer.setMelody(notes, durations, melodyLength2);
        buzzer.turnSoundOn();
    }

    if (buttonMelodyThree.wasPressed())
    {
        buzzer.setMelody(notesThree, durationsThree, melodyLengthThree);
        buzzer.turnSoundOn();
    }
}
