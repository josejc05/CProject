#ifndef UI_H
#define UI_H

// Enum for different text colors
typedef enum {
    COLOR_RED,
    COLOR_GREEN,
    COLOR_YELLOW,
    COLOR_BLUE,
    COLOR_MAGENTA,
    COLOR_CYAN,
    COLOR_WHITE,
    COLOR_RESET
} Color;

// Changes the terminal text color
void set_color(Color color);

// Prints the main game title
void show_title();

// Shows the main menu and returns the selected option
int show_main_menu();

// Prints a colored message
void show_message(const char *msg, Color color);

#endif
