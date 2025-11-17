#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "utils.h"

int main() {
    int choice = 0;

    // Simple title screen
    printf("=====================================\n");
    printf("       PARKING SIMULATOR GAME        \n");
    printf("=====================================\n\n");

    printf("Select game mode:\n");
    printf("1. Smooth mode (light traffic)\n");
    printf("2. Busy mode (heavy traffic)\n");
    printf("3. Exit\n");
    printf("-------------------------------------\n");
    printf("Your choice: ");

    scanf("%d", &choice);
    getchar(); // clear newline from buffer

    switch (choice) {
        case 1:
            printf("\nStarting SMOOTH mode...\n");
            start_game(0);   // 0 = smooth mode
            break;

        case 2:
            printf("\nStarting BUSY mode...\n");
            start_game(1);   // 1 = busy mode
            break;

        case 3:
            printf("\nGoodbye!\n");
            exit(0);
            break;

        default:
            printf("\nInvalid choice. Exiting.\n");
            exit(1);
    }

    return 0;
}
