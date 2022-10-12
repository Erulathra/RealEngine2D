#include "SDL2/SDL.h"
#include "Engine/MainEngine.h"
#include "Engine/PlayerOne.h"
#include "Engine/Utils.h"

int main(int argc, char *argv[]) {
    srand(time(nullptr));
    RealisticEngine::MainEngine Engine;

    if (Engine.Init()) {
        SDL_Texture* TextureSquare = RealisticEngine::Utils::LoadTexture("res/Images/Square.png", Engine.GetRenderer());
        SDL_Texture* TextureCircle = RealisticEngine::Utils::LoadTexture("res/Images/Circle.png", Engine.GetRenderer());

        SDL_Rect SpriteRect;
        SpriteRect.h = 32;
        SpriteRect.w = 32;

        std::shared_ptr<RealisticEngine::Actor> PlayerOne =
                std::make_shared<RealisticEngine::PlayerOne>(Eigen::Vector2f(64.f, 64.f), TextureSquare, &SpriteRect);

        Engine.SpawnActor(PlayerOne);
        Engine.GameLoop();
    }

    SDL_Quit();
    return 0;
}
