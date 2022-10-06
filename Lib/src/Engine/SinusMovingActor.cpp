#include "Engine/SinusMovingActor.h"
#include "Eigen/Core"

void RealisticEngine::SinusMovingActor::Start() {

}

void RealisticEngine::SinusMovingActor::Update(double DeltaSeconds, double Seconds) {
    Eigen::Vector2f NewPosition = GetPosition();

    NewPosition = Eigen::Vector2f((std::sin(Seconds/2)+1) * 260 + 40, (std::sin(Seconds * 2)+1) * 180 + 40);
    SetPosition(NewPosition);
}

RealisticEngine::SinusMovingActor::SinusMovingActor(SDL_Texture* Texture, SDL_Rect* Shape, const Eigen::Vector2f& Position)
: Actor(Texture, Shape, Position) {}
