#include "Header.h"
short preGame() 
{
	Texture2D WASD = LoadTexture("../assets/WASD.png");
	while (!(IsKeyPressed(KEY_ENTER)) && !WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Press ENTER to start", screenWidth / 2 - 200, screenHeight / 2 + 300, 40, WHITE);

		DrawText("Controls", screenWidth / 2 - 500, screenHeight / 2 - 300, 40, WHITE);
		DrawTexture(WASD, screenWidth / 2 - 525, screenHeight / 2 - 250, WHITE);
		EndDrawing();
	}
	return 3;
}
