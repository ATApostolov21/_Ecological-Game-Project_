#include "Header.h"
#include <stdlib.h>
#include <time.h>

struct TRASH {
    int posX = 0;
    int posY = 0;
    bool grabbed = true;
};

short inGame(short map)
{
    const short trash = 10;
    TRASH objects[trash];

    int frameTime = 0;
    int randPosX = 0;
    int randPosY = 0;
    Texture2D mapDisplay = LoadTexture("../assets/map_1.png");
    Texture2D texture = LoadTexture("../assets/sprite_temp.png");

    Vector2 spritePosition = { (float)screenWidth / 2, (float)screenHeight / 2 };

    while (true)
    {
        frameTime++;
        Color bgColor = { 0, 51, 102 };
        BeginDrawing();
        ClearBackground(bgColor);
        //DrawTexture(mapDisplay, 0, 200, WHITE);
        DrawTexture(texture, spritePosition.x, spritePosition.y, WHITE);
        DrawText(TextFormat("Current randPos: %d, %d", randPosX, randPosY), screenWidth / 2 - 200, 100, 40, WHITE);
        if (IsKeyDown(KEY_W)) spritePosition.y -= 2.0f;
        if (IsKeyDown(KEY_S)) spritePosition.y += 2.0f;
        if (IsKeyDown(KEY_A)) spritePosition.x -= 2.0f;
        if (IsKeyDown(KEY_D)) spritePosition.x += 2.0f;

        EndDrawing();

        if (frameTime >= 60)
        {
            randPosX = rand() % 1160 + 100;
            randPosY = rand() % 800 + 200;
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
                if (CheckCollisionRecs({ (float)spritePosition.x, (float)spritePosition.y, (float)texture.width, (float)texture.height }, { (float)objects[i].posX - 15, (float)objects[i].posY - 15, 30, 30 }))
                {
                    objects[i].grabbed = true;
                }
                else
                {
                    DrawCircle(objects[i].posX, objects[i].posY, 15, RED);
                }
            }
        }
    }

    UnloadTexture(mapDisplay);
    return 0;
}
