#include "game.h"

void update(AppState *as)
{
    const float delta_time = GetFrameTime();
    as->last_frame_time = GetTime();
}

void handle_keyboard_input(AppState *as)
{
    if (IsKeyPressed(KEY_UP))
        as->ball.y -= STEP;
    if (IsKeyPressed(KEY_DOWN))
        as->ball.y += STEP;
    if (IsKeyPressed(KEY_LEFT))
        as->ball.x -= STEP;
    if (IsKeyPressed(KEY_RIGHT))
        as->ball.x += STEP;
    if (IsKeyPressed(KEY_SPACE))
        pause_resume_game(as);
}

void pause_resume_game(AppState *as) {}