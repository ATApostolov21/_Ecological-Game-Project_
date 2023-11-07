#include "Header.h"

int main() 
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib menu example");

    Texture2D background = LoadTexture("background.png");
    Texture2D logo = LoadTexture("logo.png");



    Vector2 playButtonPosition = { (float)screenWidth / 2 - 50, (float)screenHeight / 2 - 50 };
    Vector2 exitButtonPosition = { (float)screenWidth / 2 - 50, (float)screenHeight / 2 };

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(logo, 50, 50, WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), { playButtonPosition.x, playButtonPosition.y, 100, 50 })) {
            DrawText("Play", playButtonPosition.x + 18, playButtonPosition.y + 15, 20, RED);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                // Играта тук
            }
        }

        else {
            DrawText("Play", playButtonPosition.x + 18, playButtonPosition.y + 15, 20, BLACK);
        }

        if (CheckCollisionPointRec(GetMousePosition(), { exitButtonPosition.x, exitButtonPosition.y, 100, 50 })) {
            DrawText("Exit", exitButtonPosition.x + 18, exitButtonPosition.y + 15, 20, RED);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
            }
        }
        else {
            DrawText("Exit", exitButtonPosition.x + 18, exitButtonPosition.y + 15, 20, BLACK);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}




