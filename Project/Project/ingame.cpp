#include "Header.h"
#include <stdlib.h>
#include <time.h>

struct TRASH {
    int posX = 0;
    int posY = 0;
    bool grabbed = true;
};

short inGame(short map, const short trash)
{
    //const short trash = 10;
    TRASH objects[20];

    int trashPicked = 0;
    int frameTime = 0;
    int randPosX = 0;
    int randPosY = 0;
    Texture2D mapDisplay = LoadTexture("../assets/game_bg.png");
    Texture2D character = LoadTexture("../assets/sprite_temp.png");
    Texture2D trashSprite = LoadTexture("../assets/trash.png");
    Texture2D dumpsterSprite = LoadTexture("../assets/dumpster.png");

    Vector2 spritePosition = { static_cast<int>((float)screenWidth / 2), static_cast<int>((float)screenHeight / 2) };

    while (!WindowShouldClose())
    {
        frameTime++;
        Color bgColor = { 0, 51, 102 };
        BeginDrawing();
        ClearBackground(bgColor);
        DrawTexturePro(mapDisplay, { 0.0f, 0.0f, (float)mapDisplay.width, (float)mapDisplay.height }, { 0.0f, 0.0f, (float)GetScreenWidth(), (float)GetScreenHeight() }, { 0, 0 }, 0.0f, WHITE);

        for (int i = 0; i < trash; i++)
        {
            if (objects[i].grabbed == false)
            {
                DrawTexture(trashSprite, objects[i].posX, objects[i].posY, WHITE);
            }
        }
        DrawTexture(dumpsterSprite  , screenWidth/2-64, screenHeight - 125, WHITE);
        DrawTexture(character, spritePosition.x, spritePosition.y, WHITE);
        DrawText(TextFormat("Current randPos: %d, %d", randPosX, randPosY), screenWidth / 2 - 200, 100, 40, WHITE);
        DrawText(TextFormat("Trash picked: %d", trashPicked), screenWidth - 165, screenHeight - 20, 20, WHITE);
        
        if (IsKeyDown(KEY_W) && spritePosition.y > 0) spritePosition.y -= 6.0f;
        if (IsKeyDown(KEY_S) && spritePosition.y < screenHeight-125 - character.height) spritePosition.y += 6.0f;
        if (IsKeyDown(KEY_A) && spritePosition.x > 0) spritePosition.x -= 6.0f;
        if (IsKeyDown(KEY_D) && spritePosition.x < screenWidth - character.width) spritePosition.x += 6.0f;

        if (frameTime >= 60)
        {
            randPosX = rand() % 1060 + 100;
            randPosY = rand() % 700 + 200;
            frameTime = 0;
            for (int i = 0; i < trash; i++)
            {
                if (objects[i].grabbed == true)
                {
                    objects[i].grabbed = false;
                    objects[i].posX = randPosX;
                    objects[i].posY = randPosY;
                    break;
                }
            }
        }

        for (int i = 0; i < trash; i++)
        {
            if (objects[i].grabbed == false)
            {
                // Check for collision with sprite
                if (CheckCollisionRecs({ (float)spritePosition.x, (float)spritePosition.y, (float)character.width, (float)character.height }, { (float)objects[i].posX - 15, (float)objects[i].posY - 15, 30, 30 }))
                {
                    DrawText("[SPACE] to pick up", spritePosition.x + 20, spritePosition.y - 20, 20, WHITE);
                    if (IsKeyPressed(KEY_SPACE))
                    {
                        objects[i].grabbed = true;
                        trashPicked++;
                    }
                    
                }
                DrawTexture(trashSprite, objects[i].posX, objects[i].posY, WHITE);
            }
        }
        EndDrawing();
    }

    UnloadTexture(mapDisplay);
    return 0;
}
