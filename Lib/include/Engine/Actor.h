//
// Created by erulathra on 06.10.22.
//

#ifndef REALISTICENGINE_ACTOR_H
#define REALISTICENGINE_ACTOR_H

#import <SDL2/SDL.h>
#import <Eigen/Geometry>

class Actor {
private:
    SDL_Texture* Texture;
public:
    explicit Actor(SDL_Texture *texture);
};


#endif //REALISTICENGINE_ACTOR_H
