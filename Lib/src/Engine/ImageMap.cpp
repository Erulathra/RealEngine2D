#include "Engine/ImageMap.h"
#include "Engine/Utils.h"

#include <fstream>
#include <map>
#include "Engine/MainEngine.h"
#include "Engine/ImageActor.h"

void RealisticEngine::ImageMap::LoadMap(std::string Path, std::map<char16_t, SDL_Texture*>& TileDictionary) {
    std::ifstream TileMap(Path);

    std::string FileLine;
    int LineNumber = 0, CharacterNumber = 0;

    SDL_Rect SpriteRect;
    SpriteRect.h = 32;
    SpriteRect.w = 32;

    while (std::getline(TileMap, FileLine)) {
        for (char Tile : FileLine) {
            auto TileActor = std::make_shared<ImageActor>(Eigen::Vector2f(0.f, 0.f),
                                                     TileDictionary[Tile], &SpriteRect);
            TileActor->SetEngine(Engine);
            TileActor->SetPosition(Eigen::Vector2f(32.f * CharacterNumber + 16.f, 32.f * LineNumber + 16.f));
            Tiles.push_back(TileActor);
            CharacterNumber++;
        }
        CharacterNumber = 0;
        LineNumber++;
    }

}

RealisticEngine::ImageMap::ImageMap(const Eigen::Vector2f& Position) : Actor(Position) {}

void RealisticEngine::ImageMap::Start() {
}

void RealisticEngine::ImageMap::Update(double DeltaSeconds, double Seconds, std::vector<SDL_Event>& EventSet) {
    for (auto Tile : Tiles) {
        Tile->Update(DeltaSeconds, Seconds, EventSet);
    }
}

void RealisticEngine::ImageMap::SetPosition(const Eigen::Vector2f& NewPosition)
{
    Actor::SetPosition(NewPosition);
    for (const auto & Item: Tiles)
    {
        Item->SetPosition(Item->GetPosition());
    }
}
