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

    Texture2D background = LoadTexture("../assets/menu_background.png");
    Texture2D logo = LoadTexture("../assets/logo_menu.png");
    Texture2D settings = LoadTexture("../assets/settings_menu.png");
    Texture2D settings_icon = LoadTexture("../assets/settings_icon.png");
    Texture2D mapSelect_1 = LoadTexture("../assets/mapSmall_1.png");
    
    //Texture2D settings_icon_pressed = LoadTexture("../assets/settings_icon_pressed.png");
    SetTargetFPS(60);

    currentScreen = 0;

    Vector2 playButtonPosition = { (float)screenWidth / 2 - 200, (float)screenHeight / 2 + 150 };
    Vector2 exitButtonPosition = { 25, (float)screenHeight-75};
    Vector2 changeMenuButton = { (float)screenWidth / 2 - 200, (float)screenHeight / 2 + 50 };
    Vector2 settingsButtonPosition = { screenWidth - 150, 0};
    
    

    Vector2 mapSelectPosition = { screenWidth / 2 - 135, screenHeight / 2 - 150 };



    
    Font fontTtf = LoadFontEx("../assets/PixAntiqua.ttf", 32, 0, 250);


    bool showPreGameScreen = true;
    bool useTtf = false;
    bool closeGame = false;
    short numberOfObjects = 10;

    short currentMap = 1;

    while (true) 
    {
        if (WindowShouldClose() && currentScreen == 0 && closeGame == false)
            closeGame = true;
        else if (closeGame && IsKeyPressed(KEY_ESCAPE))
        {
            break;
        }
        switch (currentScreen)
        {
        case 0: case 1:
            {
                BeginDrawing();
                ClearBackground(BLACK);

                DrawTexture(background, 0, 0, WHITE);
                DrawTexture(logo, screenWidth / 2 - 200, 100, WHITE);
                if (closeGame)
                {
                    DrawText("Press ESC again if you want to quit", 200, 425, 80, RED);
                }
                if (CheckCollisionPointRec(GetMousePosition(), { settingsButtonPosition.x, settingsButtonPosition.y, 190, 135 }))
                {
                    DrawTexture(settings_icon, settingsButtonPosition.x, settingsButtonPosition.y, GOLD);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        if (currentScreen == 0)
                        {
                            currentScreen = 1;
                        }
                        else if (currentScreen == 1)
                        {
                            currentScreen = 0;
                        }
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

                if (currentScreen == 1)
                {
                   
                    DrawTexture(settings, screenWidth / 2-260, screenHeight / 2-375, WHITE);

                    DrawText("Settings", screenWidth / 2 - 110, 100, 60, WHITE);
                    DrawText("Select map:", mapSelectPosition.x + 40, mapSelectPosition.y - 75, 40, WHITE);


                    if (CheckCollisionPointRec(GetMousePosition(), { mapSelectPosition.x - 100, mapSelectPosition.y + 80, 60, 60 }))
                    {
                        DrawText("<", mapSelectPosition.x - 85, mapSelectPosition.y + 70, 100, GOLD);

                    }
                    else { DrawText("<", mapSelectPosition.x - 85, mapSelectPosition.y + 70, 100, WHITE); }

                    if (CheckCollisionPointRec(GetMousePosition(), { mapSelectPosition.x + 340, mapSelectPosition.y + 80, 60, 60 }))
                    {
                        DrawText(">", mapSelectPosition.x + 355, mapSelectPosition.y + 70, 100, GOLD);

                    }
                    else { DrawText(">", mapSelectPosition.x + 355, mapSelectPosition.y + 70, 100, WHITE); }

                    DrawTexture(mapSelect_1, mapSelectPosition.x, mapSelectPosition.y, WHITE);


                    DrawText(TextFormat("Number of objects:     %d     ",numberOfObjects), screenWidth / 2 - 200, 600, 30, WHITE);
                    if (CheckCollisionPointRec(GetMousePosition(), { screenWidth / 2 + 200, 595, 30, 30 }))
                    {
                        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                        {
                            if (numberOfObjects < 20) numberOfObjects++;
                            else numberOfObjects = 1;
                        }
                        DrawText("+", screenWidth / 2 + 200, 595, 40, GREEN);
                    }
                    else
                        DrawText("+", screenWidth / 2 + 200, 595, 40, WHITE);
                    if (CheckCollisionPointRec(GetMousePosition(), { screenWidth / 2 + 105, 595, 30, 30 }))
                    {
                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                        {
                            if (numberOfObjects > 1) numberOfObjects--;
                            else numberOfObjects = 20;
                        }
                        DrawText("-", screenWidth / 2 + 105, 595, 40, RED);
                    }
                    else
                        DrawText("-", screenWidth / 2 + 105, 595, 40, WHITE);


                    if ( IsKeyPressed(KEY_ESCAPE)) currentScreen = 0;

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
                currentScreen = inGame(currentMap, numberOfObjects);
            }
        }
    }
    CloseWindow();
}