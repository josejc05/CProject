#ifndef SOUND_H
#define SOUND_H

// Generic playback functions
void play_sound(const char *filename);
void play_background_music(const char *filename);
void stop_all_sounds();

// Game-specific sound helpers
void play_menu_music();
void play_accelerate_sound();
void play_brake_sound();

#endif
