#include "Engine/PlayerOne.h"
#include "Engine/MainEngine.h"
#include "Engine/Actor.h"

#include <vector>
#include <Eigen/Core>

void RealisticEngine::PlayerOne::Start() {
    SetPosition(Eigen::Vector2f(128.f, 128.f));
}

void RealisticEngine::PlayerOne::Update(double DeltaSeconds, double Seconds, std::vector<SDL_Event>& EventSet) {
    ImageActor::Update(DeltaSeconds, Seconds, EventSet);

    HandleEvents(EventSet);

    Eigen::Vector2f MoveVector(
            ActualControlState.Right - ActualControlState.Left,
            ActualControlState.Down - ActualControlState.Up
           );

    SetPosition(GetPosition() + MoveVector * DeltaSeconds *  100);
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

