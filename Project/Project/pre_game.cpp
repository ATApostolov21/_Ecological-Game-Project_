#include "Header.h"
short preGame()
{
	
	while (true)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Press ENTER to start", 1260 / 2 - 200, 750 / 2 + 150, 40, WHITE);
		if (IsKeyPressed(KEY_ENTER))
		{
			break;
		}
		EndDrawing();
	}
	return 3;
}