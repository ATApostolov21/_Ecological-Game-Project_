#include "Header.h"
#include <stdlib.h>
#include <time.h>
short inGame(short map)
{
	int frameTime = 0;
	int randPosX = 0;
	int randPosY = 0;
	Texture2D mapDisplay = LoadTexture("../assets/map_1.png");
	while (true)
	{
		frameTime++;
		Color bgColor = { 0, 51, 102 };
		BeginDrawing();
		ClearBackground(bgColor);
		DrawTexture(mapDisplay, 0, 200, WHITE);
		DrawText(TextFormat("randPos: %d, %d", randPosX, randPosY), screenWidth / 2 - 200, 100, 40, WHITE);
		EndDrawing();
		if (frameTime >= 120)
		{
			randPosX = rand() % 1160 + 100;
			randPosY = rand() % 800 + 200;
			frameTime = 0;
		}
	}
	UnloadTexture(mapDisplay);
	return 0;
}