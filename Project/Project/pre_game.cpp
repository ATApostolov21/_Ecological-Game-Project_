#include "Header.h"
short preGame() 
{
	
	while (!(IsKeyPressed(KEY_ENTER)) && !WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Press ENTER to start", screenWidth / 2 - 200, screenHeight / 2 + 300, 40, WHITE);

		DrawText("Controls", screenWidth / 2 - 500, screenHeight / 2 - 300, 40, WHITE);
		DrawText("W\nS", screenWidth / 2 - 430, screenHeight / 2 - 200, 40, WHITE);
		DrawText("\nA     D", screenWidth / 2 - 482.5, screenHeight / 2 - 200, 40, WHITE);
		EndDrawing();
	}
	return 3;
}
