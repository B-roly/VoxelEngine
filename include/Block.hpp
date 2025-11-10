#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "raylib.h"
#include "rlgl.h"
#include <vector>
struct Vertex {
    float x, y, z;
};

struct Normal {
    float x, y, z;
};
struct Face {
    Normal normal;
    Vertex vertices[4];
};

class Block
{
    private:
      float s;
      float px;
      float py;
      float pz;
      std::vector<Face> faces;
    public:
      Block();
      Block(float ns,float npx,float npy,float npz);

      ~Block();
    void DrawCube(float px,float py,float pz,float s);
};
#endif