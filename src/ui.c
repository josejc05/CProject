#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

// ANSI color codes for console text
// These work in both CLion and most terminals
void set_color(Color color) {
    switch (color) {
        case COLOR_RED:     printf("\033[31m"); break;
        case COLOR_GREEN:   printf("\033[32m"); break;
        case COLOR_YELLOW:  printf("\033[33m"); break;
        case COLOR_BLUE:    printf("\033[34m"); break;
        case COLOR_MAGENTA: printf("\033[35m"); break;
        case COLOR_CYAN:    printf("\033[36m"); break;
        case COLOR_WHITE:   printf("\033[37m"); break;
        case COLOR_RESET:   printf("\033[0m");  break;
        default:            printf("\033[0m");  break;
    }
}

// Displays the game title with decorative formatting
void show_title() {
    set_color(COLOR_CYAN);
    printf("\n=============================================\n");
    printf("             PARKING SIMULATOR GAME           \n");
    printf("=============================================\n");
    set_color(COLOR_RESET);
}

// Displays the main menu and returns the user's choice
int show_main_menu() {
    int choice = 0;

    set_color(COLOR_YELLOW);
    printf("\nSelect game mode:\n");
    set_color(COLOR_RESET);

    printf("1. Smooth mode (light traffic)\n");
    printf("2. Busy mode (heavy traffic)\n");
    printf("3. Exit\n");
    printf("---------------------------------------------\n");
    printf("Your choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n'); // Clear buffer
        return 0;
    }
    getchar(); // Clear buffer
    return choice;
}

// Displays a small transition or message between screens
void show_message(const char *msg, Color color) {
    set_color(color);
    printf("\n%s\n", msg);
    set_color(COLOR_RESET);
}