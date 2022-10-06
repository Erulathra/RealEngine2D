#ifndef GRY2D_MAINENGINE_H
#define GRY2D_MAINENGINE_H

#include <memory>
#include <cstdint>
#include <utility>
#include <list>
#include "SDL2/SDL.h"

namespace RealisticEngine {
    class Actor;

    class MainEngine {
    private:
        std::shared_ptr<std::pair<uint16_t, uint16_t>> Resolution;
        std::list<std::shared_ptr<Actor>> ActorList;

    private:
        SDL_Window *Window;
        SDL_Renderer *Renderer;

    public:
        MainEngine();
        virtual ~MainEngine();

        bool Init();
        int GameLoop();

        void SpawnActor(std::shared_ptr<Actor> Actor);

        SDL_Renderer *GetRenderer() const;
    };

} // RealisticEngine

#endif //GRY2D_MAINENGINE_H
