#include "utils.h"
#include <stdio.h>
#include <stdlib.h> // For rand and srand
#include <time.h>   // For time, clock, and CLOCKS_PER_SEC

void clear_screen() {
    // ANSI escape code to clear the screen
    printf("\033[H\033[J");
}

int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

void init_random() {
    srand((unsigned int)time(NULL));
}

unsigned long get_time_ms() {
    return (unsigned long)(clock() * 1000 / CLOCKS_PER_SEC);
}

void pause_console() {
    printf("Press ENTER to continue...");
    getchar();
}