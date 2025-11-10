#include "Block.hpp"
Block::Block(): s(1.0),px(0),py(0),pz(0)
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
Block::Block(float ns,float npx,float npy,float npz)
{
    s = ns;
    px =npx;
    py = npy;
    pz = npz;
}
Block::~Block(){}
void Block :: DrawCube(float px,float py,float pz,float s)
{
    rlBegin(RL_QUADS);
    rlColor4f(1, 1, 1, 1);

    for (const auto& face : faces) {
        rlNormal3f(face.normal.x, face.normal.y, face.normal.z);

        for (const auto& v : face.vertices) {
            rlVertex3f(v.x, v.y, v.z);
        }
    }
    rlEnd();
}