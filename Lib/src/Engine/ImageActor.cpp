#include <SDL_render.h>
#include "Engine/ImageActor.h"
#include "Engine/ImageActor.h"
#include "Engine/MainEngine.h"

SDL_Texture* RealisticEngine::ImageActor::GetTexture() const {
    return Texture;
}

void RealisticEngine::ImageActor::SetTexture(SDL_Texture* Texture) {
    ImageActor::Texture = Texture;
}

SDL_Rect* RealisticEngine::ImageActor::GetShape() const {
    return Shape;
}

void RealisticEngine::ImageActor::SetShape(SDL_Rect* Shape) {
    ImageActor::Shape = Shape;
}

RealisticEngine::ImageActor::ImageActor(const Eigen::Vector2f& Position, SDL_Texture* Texture, SDL_Rect* Shape) : Actor(
        Position), Texture(Texture), Shape(Shape) {}

void RealisticEngine::ImageActor::Update(double DeltaSeconds, double Seconds, std::vector<SDL_Event>& EventSet) {
    SDL_RenderCopy(Engine->GetRenderer(), Texture, nullptr, Shape );
}

void RealisticEngine::ImageActor::SetPosition(const Eigen::Vector2f& NewPosition) {
    Actor::SetPosition(NewPosition);

    Shape->x = static_cast<int>(NewPosition[0]) - Shape->w;
    Shape->y = static_cast<int>(NewPosition[1]) - Shape->h;
}
