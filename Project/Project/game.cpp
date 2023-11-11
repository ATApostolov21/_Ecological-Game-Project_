#include "Header.h"
short currentScreen;
// 0 - MAIN MENU
// 1 - SETTINGS
// 2 - PREGAME SCREEN
// 3 - INGAME SCREEN
// 4 - END SCREEN


void main()
{

    InitWindow(screenWidth, screenHeight, "raylib menu example");

    Texture2D background = LoadTexture("../assets/background_menu.png");
    Texture2D logo = LoadTexture("../assets/logo_menu.png");
    Texture2D settings_icon = LoadTexture("../assets/settings_icon.png");
    
    Texture2D mapSelect_1 = LoadTexture("../assets/mapSmall_1.png");
    
    //Texture2D settings_icon_pressed = LoadTexture("../assets/settings_icon_pressed.png");
    SetTargetFPS(60);

    currentScreen = 0;

    Vector2 playButtonPosition = { (float)screenWidth / 2 - 200, (float)screenHeight / 2 + 150 };
    Vector2 exitButtonPosition = { 25, (float)screenHeight-75};
    Vector2 changeMenuButton = { (float)screenWidth / 2 - 200, (float)screenHeight / 2 + 50 };
    Vector2 settingsButtonPosition = { screenWidth - 150, 0};
    
    

    Vector2 mapSelectPosition = { screenWidth / 2 - 140, screenHeight / 2 - 250 };



    
    Font fontTtf = LoadFontEx("../assets/PixAntiqua.ttf", 32, 0, 250);


    bool showPreGameScreen = true;
    bool useTtf = false;


    short currentMap = 1;

    while (!WindowShouldClose()) 
    {
        
        switch (currentScreen)
        {
            case 0:
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
                        currentScreen = 1;
                    }
                }
                else
                {
                    DrawTexture(settings_icon, settingsButtonPosition.x, settingsButtonPosition.y, WHITE);
                }




                DrawText("Press SPACE to start", playButtonPosition.x, playButtonPosition.y, 40, WHITE);
                if (IsKeyPressed(KEY_SPACE))
                {
                    if (showPreGameScreen)
                        currentScreen = 2;
                    else
                        currentScreen = 3;
                    
                    

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
                EndDrawing();
                break;
            }
            case 1:
            {
                BeginDrawing();
                ClearBackground(BLACK);
                DrawText("Select map:", mapSelectPosition.x + 45, mapSelectPosition.y -75 , 40, WHITE);


                if (CheckCollisionPointRec(GetMousePosition(), { mapSelectPosition.x - 115, mapSelectPosition.y + 80, 60, 60 }))
                {
                    DrawText("<", mapSelectPosition.x - 100, mapSelectPosition.y + 70, 100, GOLD);

                }
                else { DrawText("<", mapSelectPosition.x - 100, mapSelectPosition.y + 70, 100, WHITE); }

                if (CheckCollisionPointRec(GetMousePosition(), { mapSelectPosition.x + 355, mapSelectPosition.y + 80, 60, 60 }))
                {
                    DrawText(">", mapSelectPosition.x + 370, mapSelectPosition.y + 70, 100, GOLD);

                }
                else { DrawText(">", mapSelectPosition.x + 370, mapSelectPosition.y + 70, 100, WHITE); }

                DrawTexture(mapSelect_1, mapSelectPosition.x, mapSelectPosition.y, WHITE);




                if (CheckCollisionPointRec(GetMousePosition(), { exitButtonPosition.x, exitButtonPosition.y, 100, 50 }))
                {
                    DrawText("Back", exitButtonPosition.x + 18, exitButtonPosition.y + 15, 40, GOLD);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        currentScreen = 0;
                    }
                }
                else
                {
                    DrawText("Back", exitButtonPosition.x + 18, exitButtonPosition.y + 15, 40, WHITE);
                }
                
                EndDrawing();
                break;
            }
            case 2:
            {

                currentScreen = preGame();
            }
            case 3:
            {
                currentScreen = inGame(currentMap);
            }
        }
    }
    CloseWindow();
}