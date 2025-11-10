#include "raylib.h"
#include <iostream>
#include <map>
int SCREEN_W = 800;
int SCREEN_H = 800;
Vector2 DrawCustomGrid(int posx, int posy, Color c)
{
	int G_X = 0;
	int G_Y = 0;
	Vector2 pos = {static_cast<float>(posx),static_cast<float>(posy)};
	for (size_t i = 0; i < 9; i++)
	{
		
			DrawLine(pos.x, pos.y + G_X, SCREEN_W - 200, pos.y + G_X, c);
			G_X += 50;
	
	}

	for (size_t i = 0; i < 9 ; i++)
	{
		
			DrawLine(pos.x + G_Y, pos.y, pos.x + G_Y, SCREEN_H - 200, c);
			G_Y += 50;
	
	}
	pos = {static_cast<float>(posx),static_cast<float>(posy)};
	return pos;
}
