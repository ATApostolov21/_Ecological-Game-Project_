#include "Header.h"
typedef enum GameScreen { MAIN = 0, SETTINGS} GameScreen;
void main()
{
    const int screenWidth = 1260;
    const int screenHeight = 750;

    InitWindow(screenWidth, screenHeight, "raylib menu example");

    Texture2D background = LoadTexture("../assets/background_menu.png");
    Texture2D logo = LoadTexture("../assets/logo_menu.png");
    Texture2D settings_icon = LoadTexture("../assets/settings_icon.png");
    //Texture2D settings_icon_pressed = LoadTexture("../assets/settings_icon_pressed.png");
    SetTargetFPS(60);
    ////////////////
    short state = 0;
    ////////////////
    GameScreen currentScreen = MAIN;

    Vector2 playButtonPosition = { (float)screenWidth / 2 - 200, (float)screenHeight / 2 + 150 };
    Vector2 exitButtonPosition = { 25, (float)screenHeight-75};
    Vector2 changeMenuButton = { (float)screenWidth / 2 - 200, (float)screenHeight / 2 + 50 };
    Vector2 settingsButtonPosition = { screenWidth - 150, 0};



    Font fontTtf = LoadFontEx("../assets/PixAntiqua.ttf", 32, 0, 250);



    bool useTtf = false;



    while (!WindowShouldClose()) {
        switch (currentScreen)
        {
            case MAIN:
            {
                BeginDrawing();

                ClearBackground(BLACK);

                //DrawTexture(background, 0, 0, WHITE);
                DrawTexture(logo, screenWidth / 2 - 200, 100, WHITE);

                if (CheckCollisionPointRec(GetMousePosition(), { settingsButtonPosition.x, settingsButtonPosition.y, 190, 135 }))
                {
                    DrawTexture(settings_icon, settingsButtonPosition.x, settingsButtonPosition.y, GOLD);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        currentScreen = SETTINGS;
                    }
                }
                else
                {
                    DrawTexture(settings_icon, settingsButtonPosition.x, settingsButtonPosition.y, WHITE);
                }




                DrawText("Press SPACE to start", playButtonPosition.x, playButtonPosition.y, 40, WHITE);
                if (IsKeyPressed(KEY_SPACE))
                {
                    CloseWindow();
                    // The game is here
                }


                if (CheckCollisionPointRec(GetMousePosition(), { exitButtonPosition.x, exitButtonPosition.y, 100, 50 }))
                {
                    DrawText("Exit", exitButtonPosition.x + 18, exitButtonPosition.y + 15, 40, GOLD);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        CloseWindow();
                    }
                }
                else
                {
                    DrawText("Exit", exitButtonPosition.x + 18, exitButtonPosition.y + 15, 40, WHITE);
                }
                if (state == 0)
                {
                    if (CheckCollisionPointRec(GetMousePosition(), { changeMenuButton.x, changeMenuButton.y, 450, 50 }))
                    {
                        DrawText("Click to change - No", changeMenuButton.x + 18, changeMenuButton.y + 15, 40, GOLD);
                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                        {

                            state = 1;

                        }
                    }
                    else
                    {
                        DrawText("Click to change - No", changeMenuButton.x + 18, changeMenuButton.y + 15, 40, WHITE);
                    }
                }
                else
                {
                    if (CheckCollisionPointRec(GetMousePosition(), { changeMenuButton.x, changeMenuButton.y, 450, 50 }))
                    {
                        DrawText("Click to change - Yes", changeMenuButton.x + 18, changeMenuButton.y + 15, 40, GOLD);
                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                        {
                            state = 0;
                        }
                    }
                    else
                    {
                        DrawText("Click to change - Yes", changeMenuButton.x + 18, changeMenuButton.y + 15, 40, WHITE);
                    }
                }
                EndDrawing();
                break;
            }
            case SETTINGS:
            {
                BeginDrawing();
                ClearBackground(BLACK);





                
                if (CheckCollisionPointRec(GetMousePosition(), { exitButtonPosition.x, exitButtonPosition.y, 100, 50 }))
                {
                    DrawText("Back", exitButtonPosition.x + 18, exitButtonPosition.y + 15, 40, GOLD);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        currentScreen = MAIN;
                    }
                }
                else
                {
                    DrawText("Back", exitButtonPosition.x + 18, exitButtonPosition.y + 15, 40, WHITE);
                }
                
                EndDrawing();
                break;
            }
        }
    }
    CloseWindow();
}