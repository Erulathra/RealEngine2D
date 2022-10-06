#include "SDL2/SDL.h"
#include "Engine/MainEngine.h"
#include "Engine/SinusMovingActor.h"
#include "Engine/Utils.h"
#include "Engine/DVDActor.h"

int main(int argc, char *argv[]) {
    srand(time(nullptr));
    RealisticEngine::MainEngine Engine;


    //RealisticEngine::SinusMovingActor ActorOne();

    if (Engine.Init()) {
        SDL_Texture* TextureOne = RealisticEngine::Utils::LoadTexture("Vimes.png", Engine.GetRenderer());
        SDL_Texture* TextureTwo = RealisticEngine::Utils::LoadTexture("dvd.png", Engine.GetRenderer());

        SDL_Rect SpriteRect;
        SpriteRect.h = 32;
        SpriteRect.w = 32;

        std::shared_ptr<RealisticEngine::Actor> Vimes =
                std::make_shared<RealisticEngine::SinusMovingActor>(TextureOne,
                                                                    &SpriteRect,
                                                                    Eigen::Vector2f(128.f,128.f));

        std::shared_ptr<RealisticEngine::Actor> DVD =
                std::make_shared<RealisticEngine::DVDActor>(TextureTwo,
                                                            &SpriteRect,
                                                            Eigen::Vector2f(64.0f, 28.0f));

        Engine.SpawnActor(Vimes);
        Engine.SpawnActor(DVD);
        Engine.GameLoop();

        SDL_DestroyTexture(TextureOne);
    }


    SDL_Quit();
    return 0;
}
