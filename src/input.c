// src/input.c
#include <stdio.h>
#include <termios.h> // For termios, tcgetattr, tcsetattr
#include <unistd.h>  // For STDIN_FILENO, read, fcntl
#include <fcntl.h>   // For fcntl
#include "input.h"

// Detects if a key is pressed (non-blocking on Linux)
char key_pressed() {
    struct termios oldterm, newterm;
    int oldfd;
    char c, result = 0;

    // Get current terminal attributes
    tcgetattr(STDIN_FILENO, &oldterm);
    newterm = oldterm;

    // Disable canonical mode and echo
    newterm.c_lflag &= ~(ICANON | ECHO);

    // Apply new attributes immediately
    tcsetattr(STDIN_FILENO, TCSANOW, &newterm);

    // Get the current file status flags
    oldfd = fcntl(STDIN_FILENO, F_GETFL, 0);

    // Set the O_NONBLOCK flag to make read non-blocking
    fcntl(STDIN_FILENO, F_SETFL, oldfd | O_NONBLOCK);

    // Attempt to read a character
    c = getchar();

    // Restore original terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &oldterm);

    // Restore original file status flags
    fcntl(STDIN_FILENO, F_SETFL, oldfd);

    // If a character was read (not EOF)
    if (c != EOF) {
        // Push it back to stdin so the next getchar() gets it
        ungetc(c, stdin);
        // Read the character again to return it
        result = getchar();
    }
    // If c was EOF, result remains 0

    return result;
}