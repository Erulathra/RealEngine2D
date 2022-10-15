#ifndef REALISTICENGINE_PLAYERTWO_H
#define REALISTICENGINE_PLAYERTWO_H

#include "ImageActor.h"

namespace RealisticEngine {

    class PlayerTwo : public ImageActor {
    public:
        PlayerTwo(const Eigen::Vector2f& Position, SDL_Texture* Texture, SDL_Rect* Shape);

        virtual void Start() override;
        virtual void Update(double DeltaSeconds, double Seconds, std::vector<SDL_Event>& EventSet) override;
    };

} // RealisticEngine

#endif //REALISTICENGINE_PLAYERTWO_H
