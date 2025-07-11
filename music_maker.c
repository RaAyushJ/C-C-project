#include <windows.h>
#include <stdio.h>

// Define note frequencies (in Hertz)
#define NOTE_C4  261
#define NOTE_D4  294
#define NOTE_E4  329
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

// Define note durations (in ms)
#define WHOLE    1000
#define HALF     500
#define QUARTER  250
#define EIGHTH   125

void playNote(int frequency, int duration) {
    Beep(frequency, duration);
    Sleep(50);  // Short pause between notes
}

void playMelody() {
    printf("🎶 Playing melody...\n");

    playNote(NOTE_C4, QUARTER);
    playNote(NOTE_D4, QUARTER);
    playNote(NOTE_E4, QUARTER);
    playNote(NOTE_C4, QUARTER);

    playNote(NOTE_C4, QUARTER);
    playNote(NOTE_D4, QUARTER);
    playNote(NOTE_E4, QUARTER);
    playNote(NOTE_C4, QUARTER);

    playNote(NOTE_E4, QUARTER);
    playNote(NOTE_F4, QUARTER);
    playNote(NOTE_G4, HALF);

    playNote(NOTE_E4, QUARTER);
    playNote(NOTE_F4, QUARTER);
    playNote(NOTE_G4, HALF);

    printf("✅ Melody finished!\n");
}

int main() {
    printf("🎵 Easy Music Maker 🎵\n");
    printf("----------------------\n");

    playMelody();

    return 0;
}
