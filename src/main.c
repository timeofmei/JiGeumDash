#include "main.h"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Usage: %s <music_name> <music_zip_path> <resource_zip_path>\n", argv[0]);
        printf("Spaces in path is not supported.\n");
        return 1;
    }

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    InitAudioDevice();
    SetTargetFPS(FPS);

    const char *music_name = argv[1];
    const char *music_zip_path = argv[2];
    const char *resource_zip_path = argv[3];

    char music_destloc[dest_path_len(music_name)], resource_destloc[dest_path_len(music_name)];

    const int music_zip_extract_result = extract(MUSIC_ZIP, music_zip_path, music_name, music_destloc);
    const int resource_zip_extract_result = extract(RESOURCE_ZIP, resource_zip_path, music_name, resource_destloc);

    if (music_zip_extract_result || resource_zip_extract_result)
    {
        printf("Failed to extract file\n");
        return 1;
    }

    AppState *as = MemAlloc(sizeof(AppState));
    as->last_frame_time = GetTime();
    as->ball.x = 20;
    as->ball.y = 20;
    as->ball.width = 15;
    as->ball.height = 15;

    Texture2D texture = LoadTexture(strcat(resource_destloc, "\\sakura.png"));
    printf("%d\n", texture.format);

    Music music = LoadMusicStream(strcat(music_destloc, "\\music.mp3"));
    PlayMusicStream(music);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        BeginDrawing();
        handle_keyboard_input(as);
        ClearBackground(GRAY);
        DrawTexture(texture, WINDOW_WIDTH/2 - texture.width/2, WINDOW_HEIGHT/2 - texture.height/2, WHITE);
        const Rectangle ball_rect = {as->ball.x, as->ball.y, as->ball.width, as->ball.height};
        DrawRectangleRec(ball_rect, WHITE);
        DrawText("It works!", 20, 20, 20, RAYWHITE);
        EndDrawing();
    }
    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}