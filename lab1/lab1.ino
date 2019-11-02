#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUZZER 6
#define PIN_INCREASE_SPEED 5
#define PIN_DECREASE_SPEED 4
#define PIN_INCREASE_STEP 3
#define PIN_DECREASE_STEP 2

Button buttonIncreaseSpeed(PIN_INCREASE_SPEED);
Button buttonDecreaseSpeed(PIN_DECREASE_SPEED);
Button buttonIncreaseStep(PIN_INCREASE_STEP);
Button buttonDecreaseStep(PIN_DECREASE_STEP);
Buzzer buzzer(PIN_BUZZER);

int melodyStep = 2;
int notes[] = {NOTE_G3, NOTE_E3, NOTE_E3, NOTE_G3, NOTE_E3, NOTE_E3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_C3, NOTE_SILENCE, 
    NOTE_A3, NOTE_C4, NOTE_A3, NOTE_G3, NOTE_E3, NOTE_E3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_C3, NOTE_SILENCE, 
    NOTE_A3, NOTE_C4, NOTE_A3, NOTE_G3, NOTE_E3, NOTE_E3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_C3, NOTE_SILENCE};
double durations[] = {8, 4, 4, 8, 4, 4, 4, 4, 4, 4, 8, 8, 
    8, 4, 4, 8, 4, 4, 4, 4, 4, 4, 8, 8, 
    8, 4, 4, 8, 4, 4, 4, 4, 4, 4, 8, 8};
int melodyLength = 36;

void setup() {
    buzzer.setMelody(notes, durations, melodyLength);
    buzzer.turnSoundOn();
}

void loop() {
    buzzer.playSound();
    if (buttonIncreaseSpeed.wasPressed())
    {
        for (int i = 0; i < melodyLength; i++) {
          durations[i] /= melodyStep;
        }
        buzzer.setMelody(notes, durations, melodyLength);
    }
    if (buttonDecreaseSpeed.wasPressed())
    {
        for (int i = 0; i < melodyLength; i++) {
          durations[i] *= melodyStep;
        }
        buzzer.setMelody(notes, durations, melodyLength);
    }
    if (buttonIncreaseStep.wasPressed())
    {
        melodyStep++;
    }
    if (buttonDecreaseStep.wasPressed())
    {
        if (melodyStep > 1) {
          melodyStep--;
      }
    }
}
