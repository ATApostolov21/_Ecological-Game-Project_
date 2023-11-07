#include "Header.h"

int main() 
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib menu example");

    Vector2 playButtonPosition = { (float)screenWidth / 2 - 50, (float)screenHeight / 2 - 50 };
    Vector2 exitButtonPosition = { (float)screenWidth / 2 - 50, (float)screenHeight / 2 };

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);



        if (CheckCollisionPointRec(GetMousePosition(), { playButtonPosition.x, playButtonPosition.y, 100, 50 }))
        {
            DrawText("Play", playButtonPosition.x + 18, playButtonPosition.y + 15, 20, RED);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                // ������ ���
            }
        }

        else
        {
            DrawText("Play", playButtonPosition.x + 18, playButtonPosition.y + 15, 20, BLACK);
        }
        EndDrawing();
    }

    CloseWindow();

    


}
