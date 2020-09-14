#include <Arduino.h>
#include "Config.h"
#include "ToneManager.h"
// #include <Tone.h>

// Tone notePlayer;
void tone_mgr_setup(){
    // notePlayer.begin(BUZZER);
    // pinMode(BUZZER, OUTPUT);
}

// void play(){
//     unsigned char i, j; //define variable
//     for (i = 0; i < 80; i++) // output a frequency sound

//         {
//             digitalWrite(BUZZER, HIGH); // sound

//             delay(1); //delay1ms

//             digitalWrite(BUZZER, LOW); //not sound

//             delay(1); //ms delay
//         }

//         for (i = 0; i < 100; i++) // output a frequency sound

//         {

//             digitalWrite(BUZZER, HIGH); // sound

//             digitalWrite(BUZZER, LOW); //not sound

//             delay(2); //2ms delay
//         }
// }

void tone_mgr_playMelody(const int melody[], int size, int tempo)
{
    // Serial.println("Should play melody");
    
    // // notePlayer.play(NOTE_A1, 1000);

    // int notes = size; 
    // //  int notes = sizeof(melody) / sizeof(melody[0]) / 2;
    // Serial.print("Sises: ");
    // Serial.print(sizeof(melody) );
    // Serial.print(" :-: ");
    // Serial.print(sizeof(melody[0]));
    // Serial.print(" :-: ");
    // Serial.print(melody[4]);
    // Serial.print(" :-: ");
    // Serial.println(notes);

    // // this calculates the duration of a whole note in ms
    // int wholenote = (60000 * 4) / tempo;

    // int divider = 0, noteDuration = 0;

    // for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2)
    // {

    //     // calculates the duration of each note
    //     divider = melody[thisNote + 1];
    //     if (divider > 0)
    //     {
    //         // regular note, just proceed
    //         noteDuration = (wholenote) / divider;
    //     }
    //     else if (divider < 0)
    //     {
    //         // dotted notes are represented with negative durations!!
    //         noteDuration = (wholenote) / abs(divider);
    //         noteDuration *= 1.5; // increases the duration in half for dotted notes
    //     }

    //     Serial.print("Playing ");
    //     Serial.print(melody[thisNote]);
    //     Serial.print(" for ");
    //     Serial.println(noteDuration);
    //     int dur = noteDuration * 0.9;

                                   // we only play the note for 90% of the duration, leaving 10% as a pause
                                //    notePlayer.play(melody[thisNote], dur);
                                //    delay(dur);
        // notePlayer.play(melody[thisNote], noteDuration * 0.9);
        // tone(BUZZER, melody[thisNote], noteDuration * 0.9);

        // Wait for the specief duration before playing the next note.
        // delay(noteDuration);

        // stop the waveform generation before the next note.
        // noTone(BUZZER);
    // }
}

void tone_mgr_playStartup(){
    // notePlayer.play(NOTE_C4);
    // delay(400);
    // notePlayer.play(NOTE_G4);
    // delay(400);
    // notePlayer.play(NOTE_C5);
    // delay(800);
    // notePlayer.stop();
}