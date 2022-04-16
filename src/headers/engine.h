#ifndef ENGINE_H
#define ENGINE_H

#include "utils.h"


// Loop frequency, defult = 64
#define GAME_DEFAULT_TICK_RATE          0b1000000

// Ray step size, increase to increase performance at the cost of quality
#define F_RAY_STEP_SIZE                 0.1

// ASCII Textures
#define H_TEXTURE_WALL_CLOSE            0xdb
#define H_TEXTURE_WALL_MEDIUM           0xb2
#define H_TEXTURE_WALL_FAR              0xb1
#define H_TEXTURE_WALL_VERY_FAR         0xb0
#define H_TEXTURE_FLOOR_CLOSE           0xf0
#define H_TEXTURE_FLOOR_MEDIUM          0xcd
#define H_TEXTURE_FLOOR_FAR             0xc4
#define H_TEXTURE_FLOOR_VERY_FAR        0xfa
#define H_TEXTURE_EMPTY                 0xff

// Commands
#define C_WALK_FORWARD                  0x57           // 'W'
#define C_WALK_BACKWARD                 0x53           // 'S'
#define C_WALK_LEFT                     0x41           // 'A'
#define C_WALK_RIGHT                    0x44           // 'D'
#define C_FOV_INCREASE                  0x51           // 'Q'
#define C_FOV_DECREASE                  0x45           // 'E'
#define C_LOOK_LEFT                     VK_LEFT        // 0x25
#define C_LOOK_UP                       VK_UP          // 0x26
#define C_LOOK_RIGHT                    VK_RIGHT       // 0x27
#define C_LOOK_DOWN                     VK_DOWN        // 0x28
#define C_SCREENSHOT                    VK_SPACE       // 0x20
#define C_LOOK_SENSI                    0.5            // default: 0.5


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

    void saveFrame();

    float fFOV;
    Position pos;
};


class Engine {
private:
    utils::Logger _logger;

    // Rendering related:
    char* screen;
	HANDLE hConsole;
	DWORD dwBytesWritten;

    void _outputFrame();

public:
    Engine(Camera &camera);

    Camera camera;
    float fElapsedTimeMilliSeconds;

    void render();
    void captureInputs();
};

#endif
