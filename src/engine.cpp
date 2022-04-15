#include "headers/engine.h"


Camera::Camera(float fFOV=90., float x=0., float y=0., float z=0., float a=0., unsigned nScreenW=120, unsigned nScreenH=40) {
    this->_logger = utils::Logger("cameraLogger", "logs/engine.log", utils::Logger::Info);

    this->fFOV = fFOV;
    this->nScreenW = nScreenW;
    this->nScreenH = nScreenH;

    this->pos.x = x;
    this->pos.y = y;
    this->pos.z = z;
    this->pos.a = a;
}
