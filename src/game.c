#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // For sleep()
#include "game.h"
#include "map.h"
#include "utils.h"

// Main game loop controller
void start_game(int mode) {
    // Load the map file depending on the mode (can be the same for now)
    const char *mapPath = "assets/maps/parking1.txt";
    char **map = load_map(mapPath);

    if (!map) {
        printf("Error: could not load map from %s\n", mapPath);
        return;
    }

    int running = 1;
    int frame = 0;

    printf("\n--- Game started in %s mode ---\n\n",
           (mode == 0) ? "SMOOTH" : "BUSY");

    // Simple simulation loop (to be replaced with real-time logic later)
    while (running) {
        clear_screen();          // Custom helper from utils
        draw_map(map);           // Render the static map

        // Display some dynamic info
        printf("\nFrame: %d | Mode: %s\n",
               frame, (mode == 0) ? "Smooth" : "Busy");

        // Simulate different speeds for each mode
        if (mode == 0)
            sleep(1);   // Slower updates
        else
            usleep(400000); // Faster updates (0.4s)

        frame++;

        // Stop after 20 frames for now
        if (frame > 20)
            running = 0;
    }

    free_map(map); // Release allocated memory
    printf("\nGame ended.\n");
}