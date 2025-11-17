#ifndef UTILS_H
#define UTILS_H

// Clears the terminal screen
void clear_screen();

// Generates a random integer between two values
int random_int(int min, int max);

// Initializes random seed (should be called once at program start)
void init_random();

// Returns current time in milliseconds
unsigned long get_time_ms();

// Pauses the console until user presses ENTER
void pause_console();

#endif