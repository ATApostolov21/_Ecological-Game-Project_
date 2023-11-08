#include "Header.h"

int main()
{
    const int screenWidth = 1260;
    const int screenHeight = 750;

    InitWindow(screenWidth, screenHeight, "raylib menu example");

    Texture2D background = LoadTexture("../assets/background_menu.png");
    Texture2D logo = LoadTexture("../assets/logoMenu.png");
    Texture2D playButton = LoadTexture("../assets/play.button.png");
    Texture2D exitButton = LoadTexture("../assets/exit.button.png");

    short state = 0;

    Vector2 playButtonPosition = { (float)screenWidth / 2 - playButton.width * 0.25, (float)screenHeight / 2 - playButton.height * 0.5 };
    Vector2 exitButtonPosition = { (float)screenWidth / 2 - exitButton.width * 0.25, (float)screenHeight / 2 };
    Vector2 changeMenuButton = { (float)screenWidth / 2 - 200, (float)screenHeight / 2 + 50 };

    Rectangle playButtonRec = { playButtonPosition.x, playButtonPosition.y, (float)playButton.width * 0.5, (float)playButton.height * 0.5 };
    Rectangle exitButtonRec = { exitButtonPosition.x, exitButtonPosition.y, (float)exitButton.width * 0.5, (float)exitButton.height * 0.5 };

    Font fontTtf = LoadFontEx("../assets/PixAntiqua.ttf", 32, 0, 250);

    bool useTtf = false;

    Rectangle sourceRec = { 0.0f, 0.0f, (float)logo.width, (float)logo.height };
    Rectangle destRec = { screenWidth / 3 - 100, 100, (float)logo.width * 0.5, (float)logo.height * 0.5 };
    Vector2 origin = { 0.0f, 0.0f };

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, WHITE);
        DrawTexturePro(logo, sourceRec, destRec, origin, 0.0f, WHITE);

        DrawTexturePro(playButton, sourceRec, playButtonRec, origin, 0.0f, WHITE);
        DrawTexturePro(exitButton, sourceRec, exitButtonRec, origin, 0.0f, WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), playButtonRec)) {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                // The game is here
            }
        }

        if (CheckCollisionPointRec(GetMousePosition(), exitButtonRec)) {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
            }
        }
        if (state == 0)
        {
            if (CheckCollisionPointRec(GetMousePosition(), { changeMenuButton.x, changeMenuButton.y, 450, 50 }))
            {
                DrawText("Click to change - No", changeMenuButton.x + 18, changeMenuButton.y + 15, 40, BLUE);
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {
                    state = 1;
                }
            }
            else
            {
                DrawText("Click to change - No", changeMenuButton.x + 18, changeMenuButton.y + 15, 40, RED);
            }
        }
        else
        {
            if (CheckCollisionPointRec(GetMousePosition(), { changeMenuButton.x, changeMenuButton.y, 450, 50 }))
            {
                DrawText("Click to change - Yes", changeMenuButton.x + 18, changeMenuButton.y + 15, 40, BLUE);
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {
                    state = 0;
                }
            }
            else
            {
                DrawText("Click to change - Yes", changeMenuButton.x + 18, changeMenuButton.y + 15, 40, RED);
            }
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
