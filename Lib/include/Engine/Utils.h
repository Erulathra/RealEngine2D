//
// Created by erulathra on 06.10.22.
//

#ifndef REALISTICENGINE_UTILS_H
#define REALISTICENGINE_UTILS_H

#include <string>
#include "SDL2/SDL.h"

namespace RealisticEngine {
    class Utils {
    public:
        static SDL_Texture* LoadTexture(std::string Path, SDL_Renderer* Renderer);
    };
}

#endif //REALISTICENGINE_UTILS_H
