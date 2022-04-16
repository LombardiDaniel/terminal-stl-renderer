#include "headers/engine.h"


Camera::Camera(float fFOV=90., float x=0., float y=0., float z=0., float a=0., unsigned nScreenW=120, unsigned nScreenH=40) {
    this->_logger = utils::Logger((char *) "Camera", (char *) "logs/engine.log", utils::Logger::Info);

    this->fFOV = fFOV;
    this->nScreenW = nScreenW;
    this->nScreenH = nScreenH;

    this->pos.x = x;
    this->pos.y = y;
    this->pos.z = z;
    this->pos.a = a;
}

// void Engine::render(Player& player) {
//
//     for (size_t x = 0; x < this->nScreenWidth; x++) {
//         float fRayAngle = (player.pos.a - this->fFOV / 2.f) + ((float) x / (float) this->nScreenWidth) * this->fFOV;
//
//         float fDistanceToWall = 0.0f;
//
//         // Unit-Vectors
//         float fEyeX = sinf(fRayAngle);
//         float fEyeY = cosf(fRayAngle);
//
//         bool bHitWall = false;
//         bool bHitMob = false;
//
//         while(!bHitWall && !bHitMob &&fDistanceToWall < this->fDepth) {
//             fDistanceToWall += F_RAY_STEP_SIZE;
//
//             int nTestX = (int)(player.pos.x + fEyeX * fDistanceToWall);
//             int nTestY = (int)(player.pos.y + fEyeY * fDistanceToWall);
//
//             // Ray out of bounds
//             if (nTestX < 0 || nTestX >= this->map.nMapWidth || nTestY < 0 || nTestY >= this->map.nMapHeight) {
//                 // bHitWall = true;
//                 fDistanceToWall = this->fDepth;
//             } else {
//                 // Ray inbounds
//                 if (this->map.smap[nTestY * this->map.nMapWidth + nTestX] == '#')
//                     bHitWall = true;
//                 else if (this->map.smobs[nTestY * this->map.nMapWidth + nTestX] == 'X')
//                     bHitMob = true;
//             }
//         }
//
//         // 3D illusion
//         int nCeiling = (float)(this->nScreenHeight / 2.0) - this->nScreenHeight / ((float)fDistanceToWall);
//         if (bHitMob && !bHitWall)
//             nCeiling -= 5;
//         int nFloor = this->nScreenHeight - nCeiling;
//
//         // Shading
//         for (int y = 0; y < (int) this->nScreenHeight; y++) {
//             if (y <= nCeiling)
//                 this->screen[y * this->nScreenWidth + x] = ' ';
//             else if (y > nCeiling && y <= nFloor) {
//                 if (bHitMob && !bHitWall)
//                     this->screen[y * nScreenWidth + x] = '$'; // Aqui ta renderizando mob AO INVES da parede, colocar o mob em cima da parede
//                 else if (!bHitMob && bHitWall) {
//                     if (fDistanceToWall <= this->fDepth / 4)            this->screen[y * nScreenWidth + x] = H_TEXTURE_WALL_CLOSE;
//                     else if (fDistanceToWall <= this->fDepth / 3)       this->screen[y * nScreenWidth + x] = H_TEXTURE_WALL_MEDIUM;
//                     else if (fDistanceToWall <= this->fDepth / 2)       this->screen[y * nScreenWidth + x] = H_TEXTURE_WALL_FAR;
//                     else                                                this->screen[y * nScreenWidth + x] = H_TEXTURE_WALL_VERY_FAR;
//                 }
//             } else {
//                 float b = 1.0f - (((float) y - this->nScreenHeight/2.0f) / ((float) this->nScreenHeight / 2.0f));
//                 if (b < 0.4)		                                    this->screen[y * nScreenWidth + x] = H_TEXTURE_FLOOR_CLOSE;
//                 else if (b < 0.45)	                                    this->screen[y * nScreenWidth + x] = H_TEXTURE_FLOOR_MEDIUM;
//                 else if (b < 0.7)	                                    this->screen[y * nScreenWidth + x] = H_TEXTURE_FLOOR_FAR;
//                 else if (b < 0.9)	                                    this->screen[y * nScreenWidth + x] = H_TEXTURE_FLOOR_VERY_FAR;
//                 else				                                    this->screen[y * nScreenWidth + x] = H_TEXTURE_EMPTY;
//             }
//         }
//     }
//
//     this->_overlayGun(player.getgun(), player.reloading(this->fElapsedTimeMilliSeconds));
//
//     int damageIndicator = -1;
//     // player.shooting() happens every tick, so it updates the player.timing.shooting var;
//     player.reloading(this->fElapsedTimeMilliSeconds);
//     if (player.shooting(this->fElapsedTimeMilliSeconds))
//         damageIndicator = player.damageIndicator;
//     this->_overlayHUD(player.getHUD(), damageIndicator, player.score);
//
//     this->_overlayMap(player.pos);
//     this->_outputFrame();
// }
