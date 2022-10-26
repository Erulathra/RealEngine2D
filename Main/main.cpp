#include "SDL2/SDL.h"
#include "Engine/MainEngine.h"
#include "Engine/PlayerOne.h"
#include "Engine/Utils.h"
#include "Engine/PlayerTwo.h"
#include "Engine/ImageMap.h"
#include <map>

int main(int argc, char *argv[]) {
    srand(time(nullptr));
    RealisticEngine::MainEngine Engine;

    if (Engine.Init()) {
        SDL_Texture* TextureSquare = RealisticEngine::Utils::LoadTexture("res/Images/Square.png", Engine.GetRenderer());
        SDL_Texture* TextureCircle = RealisticEngine::Utils::LoadTexture("res/Images/Circle.png", Engine.GetRenderer());

        std::map<char16_t, SDL_Texture*> TileDictionary;
        TileDictionary['#'] = RealisticEngine::Utils::LoadTexture("res/Images/Bricks.png", Engine.GetRenderer());
        TileDictionary['*'] = RealisticEngine::Utils::LoadTexture("res/Images/Floor.png", Engine.GetRenderer());
        TileDictionary['8'] = RealisticEngine::Utils::LoadTexture("res/Images/Circle.png", Engine.GetRenderer());

        SDL_Rect SpriteRect;
        SpriteRect.h = 32;
        SpriteRect.w = 32;

        std::shared_ptr<RealisticEngine::Actor> PlayerOne =
                std::make_shared<RealisticEngine::PlayerOne>(Eigen::Vector2f(64.f, 64.f), TextureSquare, &SpriteRect);
        //std::shared_ptr<RealisticEngine::Actor> PlayerTwo =
        //        std::make_shared<RealisticEngine::PlayerTwo>(Eigen::Vector2f(0.f, 0.f), TextureCircle, &SpriteRect);

        std::shared_ptr<RealisticEngine::ImageMap> IMap = std::make_shared<RealisticEngine::ImageMap>(Eigen::Vector2f
                (0.f, 0.f));


        //Engine.SpawnActor(PlayerTwo);
        Engine.SpawnActor(PlayerOne);
        Engine.SpawnActor(IMap);
        IMap->LoadMap("res/map", TileDictionary);
        Engine.GameLoop();
    }

    SDL_Quit();
    return 0;
}
