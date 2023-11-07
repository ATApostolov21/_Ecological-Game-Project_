#include "Header.h"

void main() 
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "raylib menu example");

    Texture2D background = LoadTexture("../assets/background_menu.png");
    Texture2D logo = LoadTexture("../assets/logo_menu.png");



    Vector2 playButtonPosition = { (float)screenWidth / 2 - 50, (float)screenHeight / 2 - 50 };
    Vector2 exitButtonPosition = { (float)screenWidth / 2 - 50, (float)screenHeight / 2 };

    
    Font fontTtf = LoadFontEx("../assets/PixAntiqua.ttf", 32, 0, 250);

   

    bool useTtf = false;



    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(logo, 100, 200, WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), { playButtonPosition.x, playButtonPosition.y, 100, 50 })) 
        {

            DrawText("Play", playButtonPosition.x + 18, playButtonPosition.y + 15, 40, BLUE);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
            {
                // The game is here
            }
        }
        else 
        {
            DrawText("Play", playButtonPosition.x + 18, playButtonPosition.y + 15, 40, WHITE);
        }

        if (CheckCollisionPointRec(GetMousePosition(), { exitButtonPosition.x, exitButtonPosition.y, 100, 50 })) 
        {
            DrawText("Exit", exitButtonPosition.x + 18, exitButtonPosition.y + 15, 40, BLUE);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
            {
                CloseWindow();
            }
        }
        else 
        {
            DrawText("Exit", exitButtonPosition.x + 18, exitButtonPosition.y + 15, 40, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();

}




