#include "Header.h"

void main() 
{
    const int screenWidth = 1260;
    const int screenHeight = 750;

    InitWindow(screenWidth, screenHeight, "raylib menu example");

    Texture2D background = LoadTexture("../assets/background_menu.png");
    Texture2D logo = LoadTexture("../assets/logo_menu.png");
    Texture2D settings_icon = LoadTexture("../assets/settings_icon1.png");

    ////////////////
    short state = 0;
    ////////////////

    Vector2 playButtonPosition = { (float)screenWidth / 2 - 200, (float)screenHeight / 2 + 150 };
    Vector2 exitButtonPosition = { 0, screenHeight - 60};
    Vector2 changeMenuButton = { (float)screenWidth / 2 - 200, (float)screenHeight / 2 + 50 };


    
    Font fontTtf = LoadFontEx("../assets/PixAntiqua.ttf", 32, 0, 250);

   

    bool useTtf = false;



    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        //DrawTexture(background, 0, 0, WHITE);
        DrawTexture(logo, screenWidth/2 - 250, 100, RED);
        DrawTexture(settings_icon, screenWidth-175, 25, WHITE);

        //
        DrawText("Press SPACE to start", playButtonPosition.x, playButtonPosition.y, 40, WHITE);
        if (IsKeyPressed(KEY_SPACE))
                {
                    state = 1;
                }
        //

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




