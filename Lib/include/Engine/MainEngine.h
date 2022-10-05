#ifndef GRY2D_MAINENGINE_H
#define GRY2D_MAINENGINE_H

#include <memory>
#include <cstdint>
#include <utility>
#include <SDL2/SDL.h>

namespace RealisticEngine {

    class MainEngine {
    private:
        class std::shared_ptr<std::pair<uint16_t, uint16_t>> Resolution;

    private:
        SDL_Window* Window;
        SDL_Renderer* Renderer;
        SDL_Surface* Background;

    public:
        explicit MainEngine();

        bool Init();
        int GameLoop();
    };

} // RealisticEngine

#endif //GRY2D_MAINENGINE_H
