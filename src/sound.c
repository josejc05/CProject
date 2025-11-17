// src/sound.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sound.h"
#include <sys/wait.h> // Optional, for more robust process handling if needed

// Helper function to execute system command safely
void execute_command(const char* command) {
    if (!command) return;
    int result = system(command);
    // Optionally check result if needed, but often fire-and-forget is fine
    (void)result; // Suppress unused variable warning
}

// Plays any sound or music file using SoX's 'play' command in the background
void play_sound(const char *filename) {
    if (!filename) return;

    char command[512]; // Increased buffer size for safety
    // The command "&" runs the process in the background
    snprintf(command, sizeof(command), "play -q '%s' &", filename);
    execute_command(command);
}

// Starts the background music in the background
void play_background_music(const char *filename) {
    play_sound(filename);
}

// Stops all currently playing 'play' processes
void stop_all_sounds() {
    // Use pidof to find the process ID of 'play' and kill it
    execute_command("kill $(pidof play) 2>/dev/null");
    // The '2>/dev/null' suppresses error messages if no 'play' processes are found.
}

// ------------------ GAME-SPECIFIC SOUND HELPERS ------------------ //

// Plays the background menu music
void play_menu_music() {
    play_sound("assets/sounds/menu.mp3");
}

// Plays acceleration sound effect
void play_accelerate_sound() {
    play_sound("assets/sounds/accelerate.mp3");
}

// Plays braking sound effect
void play_brake_sound() {
    play_sound("assets/sounds/brake.mp3");
}