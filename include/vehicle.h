#ifndef VEHICLE_H
#define VEHICLE_H

// Vehicle structure definition (based on project specs)
typedef struct voiture {
    char direction;             // N,S,E,O
    int posx;                   // X position (column)
    int posy;                   // Y position (row)
    int vitesse;                // Speed
    char alignement;            // 'g' = left, 'd' = right
    char type;                  // 'v' = car, 'c' = truck, etc.
    char Carrosserie[4][30];    // Vehicle body
    int code_couleur;           // Color code for display
    char etat;                  // '1' active, '0' inactive
    unsigned long int tps;      // Time spent in parking
    struct voiture *NXT;        // Next vehicle (linked list)
} VEHICULE;

// Creates and initializes a new vehicle
VEHICULE create_vehicle(char type, int posx, int posy, int color);

// Displays a vehicle at its position
void display_vehicle(const VEHICULE *v);

// Moves the vehicle depending on its direction
void move_vehicle(VEHICULE *v, int maxWidth, int maxHeight);

// Deactivates a vehicle
void deactivate_vehicle(VEHICULE *v);

// Prints vehicle information for debugging
void print_vehicle_info(const VEHICULE *v);

#endif
