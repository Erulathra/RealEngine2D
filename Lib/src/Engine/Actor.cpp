#include "Engine/Actor.h"

#include <utility>

Actor::Actor(SDL_Texture *texture, Eigen::Vector2f Position): Texture(texture), Position(std::move(Position)) {

}

void Actor::Start() {


}

