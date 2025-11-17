#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vehicle.h"
#include "utils.h"

// Creates and initializes a new vehicle with default values
VEHICULE create_vehicle(char type, int posx, int posy, int color) {
    VEHICULE v;

    v.direction = 'E';      // Default direction: East
    v.posx = posx;
    v.posy = posy;
    v.vitesse = random_int(1, 3);  // Random speed between 1–3
    v.alignement = 'g';     // default alignment (left)
    v.type = type;          // 'v' = car, 'c' = truck, etc.
    v.code_couleur = color;
    v.etat = '1';           // '1' active, '0' inactive
    v.tps = 0;
    v.NXT = NULL;

    // Initialize vehicle body (simple ASCII or loaded from file)
    strcpy(v.Carrosserie[0], "╔══╗");
    strcpy(v.Carrosserie[1], "║██║");
    strcpy(v.Carrosserie[2], "║██║");
    strcpy(v.Carrosserie[3], "╚══╝");

    return v;
}

// Displays a vehicle on screen (for now, prints its structure)
void display_vehicle(const VEHICULE *v) {
    if (!v) return;

    // Move cursor to vehicle position
    // (ANSI escape code to move cursor to x,y)
    printf("\033[%d;%dH", v->posy, v->posx);

    // Print the 4 lines of the vehicle body
    for (int i = 0; i < 4; i++) {
        printf("%s\n", v->Carrosserie[i]);
        printf("\033[%d;%dH", v->posy + i + 1, v->posx);
    }
}

// Moves the vehicle depending on its direction and speed
void move_vehicle(VEHICULE *v, int maxWidth, int maxHeight) {
    if (!v || v->etat == '0') return;

    // Simple horizontal movement
    switch (v->direction) {
        case 'E':
            v->posx += v->vitesse;
            if (v->posx >= maxWidth - 6) v->direction = 'O'; // bounce
            break;
        case 'O':
            v->posx -= v->vitesse;
            if (v->posx <= 1) v->direction = 'E';
            break;
        case 'N':
            v->posy -= v->vitesse;
            if (v->posy <= 1) v->direction = 'S';
            break;
        case 'S':
            v->posy += v->vitesse;
            if (v->posy >= maxHeight - 5) v->direction = 'N';
            break;
    }
}

// Deactivates the vehicle (used when leaving the parking)
void deactivate_vehicle(VEHICULE *v) {
    if (!v) return;
    v->etat = '0';
}

// Prints vehicle info (debugging)
void print_vehicle_info(const VEHICULE *v) {
    if (!v) return;

    printf("Type: %c | Pos: (%d,%d) | Dir: %c | Speed: %d | State: %c\n",
           v->type, v->posx, v->posy, v->direction, v->vitesse, v->etat);
}
