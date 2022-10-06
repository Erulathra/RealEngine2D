//
// Created by erulathra on 06.10.22.
//

#include <SDL_image.h>
#include "Engine/Utils.h"

SDL_Texture *RealisticEngine::Utils::LoadTexture(std::string Path, SDL_Renderer *Renderer) {
    SDL_Texture *NewTexture = nullptr;

    SDL_Surface *LoadedSurface = IMG_Load(Path.c_str());
    if (LoadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", Path.c_str(), IMG_GetError());
    }

    NewTexture = SDL_CreateTextureFromSurface(Renderer, LoadedSurface);
    if (NewTexture == nullptr) {
        printf("Unable to create texture from %s! SDL Error: %s\n", Path.c_str(), SDL_GetError());
    }

    SDL_FreeSurface(LoadedSurface);

    return NewTexture;;
}
