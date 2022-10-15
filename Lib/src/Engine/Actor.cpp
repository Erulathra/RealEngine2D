#include "Engine/Actor.h"

#include <utility>
#include <Engine/MainEngine.h>

const Eigen::Vector2f& RealisticEngine::Actor::GetPosition() const {
    return Position;
}

void RealisticEngine::Actor::SetPosition(const Eigen::Vector2f& NewPosition) {
    Position = NewPosition;
}

RealisticEngine::Actor::Actor(Eigen::Vector2f Position)
: Position(Position) {

}

void RealisticEngine::Actor::SetEngine(RealisticEngine::MainEngine* NewEngine) {
    Engine = NewEngine;
}


