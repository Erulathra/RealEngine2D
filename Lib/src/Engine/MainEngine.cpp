//
// Created by erulathra on 05.10.22.
//

#include "Engine/MainEngine.h"
#include "SDL2/SDL.h"
#include <memory>
#include <utility>
#include <iostream>

namespace RealisticEngine {
    MainEngine::MainEngine() {
        Resolution = std::make_shared<std::pair<uint16_t, uint16_t>>(640, 480);
    }

    bool RealisticEngine::MainEngine::Init() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
            return false;
        }

        Window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Resolution->first,
                                  Resolution->second, SDL_WINDOW_SHOWN);
        if (Window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            return false;
        }

        Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
        SDL_SetRenderDrawColor(Renderer, 30, 30, 46, SDL_ALPHA_OPAQUE);
        return true;
    }

    int MainEngine::GameLoop() {
        SDL_Event event;
        for (;;) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    SDL_DestroyWindow(Window);
                    return 0;
                }
            }

            SDL_RenderClear(Renderer);
            SDL_RenderPresent(Renderer);
        }
    }
} // RealisticEngine