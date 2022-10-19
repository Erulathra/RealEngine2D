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

RealisticEngine::ImageActor::ImageActor(const Eigen::Vector2f& Position, SDL_Texture* Texture, SDL_Rect* Shape) : Actor(
        Position), Texture(Texture) {
    this->Shape = std::make_shared<SDL_Rect>();
    this->Shape->w = Shape->w;
    this->Shape->h = Shape->h;
}

void RealisticEngine::ImageActor::Update(double DeltaSeconds, double Seconds, std::vector<SDL_Event>& EventSet) {
    SDL_RenderCopy(Engine->GetRenderer(), Texture, nullptr, Shape.get() );
}

void RealisticEngine::ImageActor::SetPosition(const Eigen::Vector2f& NewPosition) {
    Actor::SetPosition(NewPosition);

    Shape->x = static_cast<int>(NewPosition[0] - Shape->w/2.f);
    Shape->y = static_cast<int>(NewPosition[1] - Shape->h/2.f);
}

void RealisticEngine::ImageActor::Start() {

}
