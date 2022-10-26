#ifndef REALISTICENGINE_IMAGEMAP_H
#define REALISTICENGINE_IMAGEMAP_H

#include <vector>
#include <map>
#include <memory>
#include "ImageActor.h"

namespace RealisticEngine {
    class ImageMap : public Actor {
        std::vector<std::shared_ptr<ImageActor>> Tiles;
    public:
        ImageMap(const Eigen::Vector2f& Position);

    private:
        virtual void Start() override;
        virtual void Update(double DeltaSeconds, double Seconds, std::vector<SDL_Event>& EventSet) override;
    public:
        void LoadMap(std::string Path, std::map<char16_t, SDL_Texture*>& TileDictionary);

        virtual void SetPosition(const Eigen::Vector2f& NewPosition) override;
    };
}


#endif //REALISTICENGINE_IMAGEMAP_H
