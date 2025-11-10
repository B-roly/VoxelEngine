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
	 std::cout<<"py :"<<b.get_py()<<std::endl;
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{

		UpdateCamera(&cam3d, CAMERA_FREE);
		if (IsKeyPressed(KEY_Z)) cam3d.target = (Vector3){ 0.0f, 0.0f, 0.0f };
		  BeginDrawing();
		BeginMode3D(cam3d);
		int mpx = static_cast<float>(b.get_px());
		int mpy = static_cast<float>(b.get_py());
		int mpz = static_cast<float>(b.get_pz());
		for (size_t x = 0; x < 3; x++)
		{
			for (size_t y = 0; y < 3; y++)
			{
				for (size_t z = 0; z < 3; z++)
				{
					b.DrawCube(mpx+x,mpy+y,mpz+z,b.get_s());
					DrawCubeWires({(float)x,(float)y,(float)z},2,2,2,RED);
				}
				
			}
			
		}
		
        
		
		ClearBackground(BLACK);
		EndMode3D();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}