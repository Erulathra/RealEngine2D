#ifndef REALISTICENGINE_ACTOR_H
#define REALISTICENGINE_ACTOR_H

#include <SDL2/SDL.h>
#include <Eigen/Core>

class Actor {
private:
    SDL_Texture* Texture;
protected:
    Eigen::Vector2f Position;
public:
    explicit Actor(SDL_Texture *texture, Eigen::Vector2f Position);

    virtual void Start();
    virtual void Update(double DeltaSeconds, double Seconds) = 0;
};


#endif //REALISTICENGINE_ACTOR_H
