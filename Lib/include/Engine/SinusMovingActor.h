#ifndef REALISTICENGINE_SINUSMOVINGACTOR_H
#define REALISTICENGINE_SINUSMOVINGACTOR_H


#include "Actor.h"

namespace RealisticEngine {

    class SinusMovingActor : public Actor {
    public:
        SinusMovingActor(SDL_Texture* Texture, SDL_Rect* Shape, const Eigen::Vector2f& Position);

        void Update(double DeltaSeconds, double Seconds) override;
        void Start() override;
    };

}

#endif //REALISTICENGINE_SINUSMOVINGACTOR_H
