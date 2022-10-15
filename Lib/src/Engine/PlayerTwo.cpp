#include "Engine/PlayerTwo.h"

namespace RealisticEngine {
    void PlayerTwo::Start() {

    }

    void PlayerTwo::Update(double DeltaSeconds, double Seconds, std::vector<SDL_Event>& EventSet) {
        ImageActor::Update(DeltaSeconds, Seconds, EventSet);
        for (auto Event: EventSet) {
            if (Event.type == SDL_MOUSEMOTION) {
                int MouseX, MouseY;
                SDL_GetMouseState(&MouseX, &MouseY);
                SetPosition(Eigen::Vector2f(MouseX, MouseY));
            }
        }
    }

    PlayerTwo::PlayerTwo(const Eigen::Vector2f& Position, SDL_Texture* Texture, SDL_Rect* Shape)
    : ImageActor(Position, Texture, Shape) {}
} // RealisticEngine