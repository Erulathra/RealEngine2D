#include "Engine/DVDActor.h"

void RealisticEngine::DVDActor::Start() {
    Speed = Eigen::Vector2f(140.f, 140.f);
}

void RealisticEngine::DVDActor::Update(double DeltaSeconds, double Seconds) {
    Eigen::Vector2f NewPosition = GetPosition();

    NewPosition += Speed * DeltaSeconds;
    if (NewPosition[0] > 640.f-32.f || NewPosition[0] < 0.f) {
        Speed[0] = -Speed[0];
        Bounce();
    }
    if (NewPosition[1] > 480.f-26.f || NewPosition[1] < 0.f) {
        Speed[1] = -Speed[1];
        Bounce();
    }

    SetPosition(NewPosition);
}

RealisticEngine::DVDActor::DVDActor(SDL_Texture* Texture, SDL_Rect* Shape, const Eigen::Vector2f& Position)
: Actor(Texture, Shape, Position) {}

void RealisticEngine::DVDActor::Bounce() {
    uint8_t Red = 0;
    uint8_t Green = 0;
    uint8_t Blue = 0;

    while (Red + Green + Blue == 0) {
        Red = rand()%2 * 0xFF;
        Green = rand()%2 * 0xFF;
        Blue = rand()%2 * 0xFF;
    }

    SDL_SetTextureColorMod(GetTexture(), Red, Green, Blue);
}
