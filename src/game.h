#ifndef GAME_H
#define GAME_H

#include "main.h"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800
#define WINDOW_NAME "JiGeum Dash"
#define FPS 240

#define STEP 10

typedef struct
{
    float x;
    float y;
    float width;
    float height;
} Ball;

typedef struct
{
    double last_frame_time;
    Music music;
    int music_playing;
    int music_played;
    int audio_open;
    Ball ball;
} AppState;

void update(AppState *as);

void handle_keyboard_input(AppState *as);

void pause_resume_game(AppState *as);

#endif