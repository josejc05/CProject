#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_MAP_LINES 50

// Loads a map from a .txt file and returns a pointer to it
char **load_map(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening map file");
        return NULL;
    }

    char **map = (char **)malloc(MAX_MAP_LINES * sizeof(char *));
    if (!map) {
        perror("Error allocating memory for map");
        fclose(file);
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    int lineCount = 0;

    while (fgets(line, sizeof(line), file) && lineCount < MAX_MAP_LINES) {
        map[lineCount] = (char *)malloc(strlen(line) + 1);
        if (!map[lineCount]) {
            perror("Error allocating memory for map line");
            for (int i = 0; i < lineCount; i++) {
                free(map[i]);
            }
            free(map);
            fclose(file);
            return NULL;
        }
        strcpy(map[lineCount], line);
        lineCount++;
    }

    map[lineCount] = NULL; // Null-terminate the map
    fclose(file);
    return map;
}

// Draws the map on the screen
void draw_map(char **map) {
    if (!map) return;

    for (int i = 0; map[i] != NULL; i++) {
        printf("%s", map[i]);
    }
}

// Frees the memory used by the map
void free_map(char **map) {
    if (!map) return;

    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
    }
    free(map);
}