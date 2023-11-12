#pragma once
#include <raylib.h>
#include <iostream>
const float screenWidth = 1440;
const float screenHeight = 850;

void main();
short preGame();
short inGame(float charSpeed, int gameTime, short map, const short trash);
