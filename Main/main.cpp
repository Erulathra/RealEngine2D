#include "SDL2/SDL.h"
#include "Engine/MainEngine.h"

int main(int argc, char *argv[]) {
    RealisticEngine::MainEngine Engine;
    if (Engine.Init()) {
        Engine.GameLoop();
    }

    SDL_Quit();
    return 0;
}
