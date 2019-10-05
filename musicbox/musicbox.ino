#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUTTON_MEL_ONE 3
#define PIN_BUTTON_OFF 5
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

//melody 2
int notesSecond[2][4] = {{NOTE_C4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE}, {NOTE_E4, NOTE_A5, NOTE_C4, NOTE_CS8}};
double durationsSecond[2][4] = {{4, 1, 4, 1}, {5, 8, 5, 3}};
int melodyLengthSecond = 4;
int secondNoteIndex = 0;

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
        buzzer.setMelody(notesSecond[secondNoteIndex], durationsSecond[secondNoteIndex], melodyLengthSecond);
        secondNoteIndex = (secondNoteIndex + 1) % 2;
        buzzer.turnSoundOn();
    }
}
