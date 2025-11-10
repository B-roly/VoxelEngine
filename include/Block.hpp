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
      float get_px();
      float get_py();
      float get_pz();
      float get_s();
      //setters
      void set_px(float npx);
      void set_py(float npy);
      void set_pz(float npz);
    void DrawCube(float px,float py,float pz,float s);
};
#endif