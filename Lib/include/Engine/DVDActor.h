//
// Created by erulathra on 07.10.22.
//

#ifndef REALISTICENGINE_DVDACTOR_H
#define REALISTICENGINE_DVDACTOR_H

#include "Actor.h"

namespace RealisticEngine {

    class DVDActor : public Actor {
    private:
        Eigen::Vector2f Speed;
    public:
        DVDActor(SDL_Texture* Texture, SDL_Rect* Shape, const Eigen::Vector2f& Position);

        virtual void Start() override;
        virtual void Update(double DeltaSeconds, double Seconds) override;
    private:
        void Bounce();
    };

}


#endif //REALISTICENGINE_DVDACTOR_H
