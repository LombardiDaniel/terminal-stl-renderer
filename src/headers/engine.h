#ifndef ENGINE_H
#define ENGINE_H

#include "utils.h"

struct Position {
    float x;
    float y;
    float z;
    float a;
};

class Camera {
private:
    utils::Logger _logger;

public:
    Camera(float fFOV, float x, float y, float z, float a, unsigned nScreenW, unsigned nScreenH);

    unsigned nScreenW;
    unsigned nScreenH;

    float fFOV;
    Position pos;
};

#endif
