#ifndef MAP_H
#define MAP_H

// Loads a map from a .txt file and returns a pointer to it
char **load_map(const char *filename);

// Draws the map on the screen
void draw_map(char **map);

// Frees the memory used by the map
void free_map(char **map);

#endif