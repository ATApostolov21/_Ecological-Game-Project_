#include "Header.h"
short preGame()
{
	Texture2D WASD = LoadTexture("../assets/WASD.png");
	Font font = LoadFontEx("../assets/PixAntiqua.ttf", 32, 0, 250);

	while (!(IsKeyPressed(KEY_ENTER)) && !WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTextEx(font, "Press ENTER to start", { screenWidth / 2 - 200, screenHeight / 2 + 300 }, font.baseSize, 2.0f, WHITE);
		DrawTextEx(font, "Press ESC to go back to menu", { screenWidth / 2 - 280, screenHeight / 2 + 340 }, font.baseSize, 2.0f, WHITE);
		DrawTextEx(font, "Controls", { screenWidth / 2 - 500, screenHeight / 2 - 300 }, font.baseSize, 2.0f, WHITE);
		DrawTexture(WASD, screenWidth / 2 - 525, screenHeight / 2 - 250, WHITE);
		EndDrawing();
	}
	UnloadTexture(WASD);
	UnloadFont(font);
	if (IsKeyPressed(KEY_ENTER)) return 3;
	return 0;
}
