#include "Header.h"

void main() 
{
    const int screenWidth = 1260;
    const int screenHeight = 750;

    InitWindow(screenWidth, screenHeight, "raylib menu example");

    Texture2D background = LoadTexture("../assets/background_menu.png");
    Texture2D logo = LoadTexture("../assets/logoMenu.png");

    ////////////////
    short state = 0;
    ////////////////

    Vector2 playButtonPosition = { (float)screenWidth / 2 - 50, (float)screenHeight / 2 - 50 };
    Vector2 exitButtonPosition = { (float)screenWidth / 2 - 50, (float)screenHeight / 2 };
    Vector2 changeMenuButton = { (float)screenWidth / 2 - 200, (float)screenHeight / 2 + 50 };


    
    Font fontTtf = LoadFontEx("../assets/PixAntiqua.ttf", 32, 0, 250);

   

    bool useTtf = false;



    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        Rectangle sourceRec = { 0.0f, 0.0f, (float)logo.width, (float)logo.height };
        Rectangle destRec = { screenWidth / 3 - 100, 100, (float)logo.width * 0.5, (float)logo.height * 0.5 };
        Vector2 origin = { 0.0f, 0.0f };

        // Draw the logo with the new size
        DrawTexture(background, 0, 0, WHITE);
        DrawTexturePro(logo, sourceRec, destRec, origin, 0.0f, WHITE);

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
                DrawText("Play", playButtonPosition.x + 18, playButtonPosition.y + 15, 40, RED);
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
            DrawText("Exit", exitButtonPosition.x + 18, exitButtonPosition.y + 15, 40, RED);
        }
        if (state == 0)
        {
            if (CheckCollisionPointRec(GetMousePosition(), { changeMenuButton.x, changeMenuButton.y, 450, 50 }))
            {
                DrawText("Click to change - No", changeMenuButton.x + 18, changeMenuButton.y + 15, 40, BLUE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
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
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
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
}




