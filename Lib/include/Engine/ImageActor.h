#ifndef REALISTICENGINE_IMAGEACTOR_H
#define REALISTICENGINE_IMAGEACTOR_H

#include "Actor.h"

namespace RealisticEngine {

    class ImageActor : public Actor {
        SDL_Texture* Texture;
        SDL_Rect* Shape;
    public:
        ImageActor(const Eigen::Vector2f& Position, SDL_Texture* Texture, SDL_Rect* Shape);

        virtual void Start() override = 0;
        virtual void Update(double DeltaSeconds, double Seconds, std::vector<SDL_Event>& EventSet) override;
        virtual void SetPosition(const Eigen::Vector2f& NewPosition) override;

        SDL_Texture* GetTexture() const;
        void SetTexture(SDL_Texture* Texture);
        SDL_Rect* GetShape() const;
        void SetShape(SDL_Rect* Shape);
    };

}


#endif //REALISTICENGINE_IMAGEACTOR_H
