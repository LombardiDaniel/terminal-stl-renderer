#include <iostream>
#include <chrono>
#include <Windows.h>

#include "headers/engine.h"
#include "headers/utils.h"

#define DEBUG                                   0


int main(int argc, char const *argv[]) {
    
    if (DEBUG)
        utils::Logger::setDebug();
    else
        utils::Logger::unsetDebug();


    // // The overlays were made with these dimensions in mind, do NOT change
    // int nScreenW = 120;
    // int nScreenH = 40;
    //
    // // MAIN()
    // // Engine engine = Engine(nScreenW, nScreenH, fFov, map);
    //
    // auto tp1 = std::chrono::system_clock::now();
	// auto tp2 = std::chrono::system_clock::now();
    //
    // // WaveQueue waveQueue(map);
    // // waveQueue.pop(engine.currentWave);
    //
    //
    // while (true) {
    //
    //     tp2 = std::chrono::system_clock::now();
	// 	std::chrono::duration<float> elapsedTime = tp2 - tp1;
    //
    //     engine.fElapsedTimeMilliSeconds = std::chrono::duration_cast<std::chrono::milliseconds>(tp2 - tp1).count();
    //
    //     if (engine.fElapsedTimeMilliSeconds <= 1000 / GAME_TICK_RATE)
    //         continue;
    //
    //     // Game-tick:
	// 	tp1 = tp2;
    //
    //     engine.updateMobs();
    //
    //     if (engine.currentWave.ended())
    //         waveQueue.pop(engine.currentWave);
    //
    //     engine.checkForDamage(player);
    //
    //     engine.captureInputs(player);
    //     player.score = waveQueue.getDificulty() - 1;
    //
    //     engine.render(player);
    //
    //     if (player.fHealth <= 0.f)
    //         break;
    // }
    //
    // engine.deathScreen(player.score);
    //
    // while (1) {}

    return 0;
}
