#ifndef REALISTICENGINE_PLAYERONE_H
#define REALISTICENGINE_PLAYERONE_H

#include "Actor.h"
#include "ImageActor.h"
#include <vector>

struct ControlState {
    float Left;
    float Right;
    float Up;
    float Down;
};

namespace RealisticEngine {

    class PlayerOne: public ImageActor {
    private:
        Eigen::Vector2f Velocity;

        ControlState ActualControlState{};
    public:
        PlayerOne(const Eigen::Vector2f& Position, SDL_Texture* Texture, SDL_Rect* Shape);
    public:

        void Start() override;
        void Update(double DeltaSeconds, double Seconds, std::vector<SDL_Event>& EventSet) override;
        void HandleEvents(std::vector<SDL_Event>& EventSet);
    };

}

#endif //REALISTICENGINE_PLAYERONE_H
