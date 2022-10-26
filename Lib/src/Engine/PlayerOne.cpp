#include "Engine/PlayerOne.h"
#include "Engine/MainEngine.h"

#include <vector>
#include <Eigen/Core>
#include <cmath>
#include <iostream>

void RealisticEngine::PlayerOne::Start() {
    SetPosition(Eigen::Vector2f(128.f, 128.f));
}

void RealisticEngine::PlayerOne::Update(double DeltaSeconds, double Seconds, std::vector<SDL_Event>& EventSet) {
    ImageActor::Update(DeltaSeconds, Seconds, EventSet);

    HandleEvents(EventSet);

    Eigen::Vector2f MoveVector (
            ActualControlState.Right - ActualControlState.Left,
            ActualControlState.Down - ActualControlState.Up
           );

    float Acceleration = 10.f;
    float Speed = 300.f;

    Velocity[0] = std::lerp(Velocity[0], Speed * MoveVector[0], DeltaSeconds * Acceleration);
    Velocity[1] = std::lerp(Velocity[1], Speed * MoveVector[1], DeltaSeconds * Acceleration);

    SetPosition(GetPosition() + Velocity * DeltaSeconds);

    auto ResolutionVector = Eigen::Vector2f(Engine->GetResolution()->first, Engine->GetResolution()->second);

    Engine->SetCameraLocation(GetPosition());
}

void RealisticEngine::PlayerOne::HandleEvents(std::vector<SDL_Event>& EventSet) {
    for (auto Event: EventSet) {
        if (Event.type == SDL_KEYDOWN) {
            if (Event.key.keysym.sym == SDLK_LEFT) {
                ActualControlState.Left = 1.f;
            }
            if (Event.key.keysym.sym == SDLK_RIGHT) {
                ActualControlState.Right = 1.f;
            }

            if (Event.key.keysym.sym == SDLK_UP) {
                ActualControlState.Up = 1.f;
            }
            if (Event.key.keysym.sym == SDLK_DOWN) {
                ActualControlState.Down = 1.f;
            }
        }

        if (Event.type == SDL_KEYUP) {
            if (Event.key.keysym.sym == SDLK_LEFT) {
                ActualControlState.Left = 0.f;
            }
            if (Event.key.keysym.sym == SDLK_RIGHT) {
                ActualControlState.Right = 0.f;
            }

            if (Event.key.keysym.sym == SDLK_UP) {
                ActualControlState.Up = 0.f;
            }
            if (Event.key.keysym.sym == SDLK_DOWN) {
                ActualControlState.Down = 0.f;
            }
        }
    }
}

RealisticEngine::PlayerOne::PlayerOne(const Eigen::Vector2f& Position, SDL_Texture* Texture, SDL_Rect* Shape)
        : ImageActor(Position, Texture, Shape) {

}

