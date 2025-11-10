#include "Block.hpp"
#include <iostream>
Block::Block(): s(1),px(0.0),py(0.0),pz(0.0)
{
       faces.push_back({
            {0, 0, 1},
            { {px -s, py +s, pz+s}, {px + s, py + -s, pz + -s}, 
            {px + s, py + -s, pz + s}, {px + s, py + -s, pz + s} }
        });

        // BACK
        faces.push_back({
            {0, 0, -1},
            { {px + s, py + s, pz + -s}, {px + -s, py + s, pz + -s}, {px + -s, py + -s, pz + -s}, 
            {px + s, py + -s, pz + -s} }
        });

        // LEFT
        faces.push_back({
            {-1, 0, 0},
            { {px + -s, py + s, pz + -s}, {px + -s, py + s, pz + s}, {px + -s, py + -s, pz + s}, 
            {px + -s, py + -s, pz + -s} }
        });

        // RIGHT
        faces.push_back({
            {1, 0, 0},
            { {px + s, py + s, pz + s}, {px + s, py + s, pz + -s}, {px + s, py + -s, pz + -s}
            , {px + s, py + -s, pz + s} }
        });

        // TOP
        faces.push_back({
            {0, 1, 0},
            { {px + s, py + s, pz + s}, {px + -s, py + s, pz + s},
             {px + -s, py + s, pz + -s}, {px + s, py + s, pz + -s}}
        });

        // BOTTOM
        faces.push_back({
            {0, -1, 0},
            { {px + -s, py + -s, pz + s}, {px + s, py + -s, pz + s},
             {px + s, py + -s, pz + -s}, {px + -s, py + -s, pz + -s} }
        });
    
}
Block::~Block(){}

float Block::get_s(){return s;}
float Block::get_px(){return px;}
float Block::get_py(){return py;}
float Block::get_pz(){return pz;}
void Block::set_px(float npx){px = npx ;}
void Block::set_py(float npy){py = npy;}
void Block::set_pz(float npz){pz = npz;}
void Block :: DrawCube(float px,float py,float pz,float s)
{
    rlBegin(RL_QUADS);
    rlColor4f(1, 1, 1, 1);

    for (const auto& face : faces) {
        rlNormal3f(face.normal.x, face.normal.y, face.normal.z);

        for (const auto& v : face.vertices) {
            rlVertex3f(px + v.x, py + v.y, pz + v.z);
        }
    }
    // std::cout<<px;
	// std::cout<<py;
    rlEnd();
}