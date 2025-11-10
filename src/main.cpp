#include "raylib.h"
#include "rlgl.h"
#include <iostream>
#include <map>
#include <chrono>
#include "../include/Block.hpp"
#include <thread>
#include <vector>



int main(void)
{
	Camera3D cam3d = {0};
	cam3d.position = (Vector3){10.0,10.0,10.0};
	cam3d.target = (Vector3){0,0,0};
	cam3d.up = (Vector3){0,1.0,0};
	cam3d.fovy = 45.0;
	cam3d.projection = CAMERA_PERSPECTIVE;
	Vector3 pos{0,0,0};
	InitWindow(800, 800, "PG");
    Block b;
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		  BeginDrawing();
		BeginMode3D(cam3d);
        // for (size_t i = 0; i < 32; i++)
        // {
        //     for (size_t j = 0; j < 32; j++)
        //     {
        //         for (size_t k = 0; k < 32; k++)
        //         {
                    b.DrawCube(0,10,0,1.0);
        //         }
                
        //     }
            
        // }
        
		
		DrawCubeWires({0,0,0},10,10,10,BLACK);
		ClearBackground(BLACK);
		EndMode3D();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}