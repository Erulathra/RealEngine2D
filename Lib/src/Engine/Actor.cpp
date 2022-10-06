#include "Engine/Actor.h"

#include <utility>

RealisticEngine::Actor::Actor(SDL_Texture* texture, SDL_Rect* Shape, Eigen::Vector2f Position)
: Texture(texture), Shape(Shape), Position(std::move(Position)) {

}

SDL_Texture* RealisticEngine::Actor::GetTexture() const {
    return Texture;
}

const Eigen::Vector2f& RealisticEngine::Actor::GetPosition() const {
    return Position;
}

SDL_Rect* RealisticEngine::Actor::GetShape() const {
    return Shape;
}

void RealisticEngine::Actor::SetPosition(const Eigen::Vector2f& NewPosition) {
    Position = NewPosition;
    Shape->x = static_cast<int>(NewPosition[0]);
    Shape->y = static_cast<int>(NewPosition[1]);
}


