#ifndef REALISTICENGINE_ACTOR_H
#define REALISTICENGINE_ACTOR_H

#include <SDL2/SDL.h>
#include <Eigen/Core>

namespace RealisticEngine {
    class Actor {
    private:
        SDL_Texture* Texture;
        SDL_Rect* Shape;
        Eigen::Vector2f Position;

    public:
        explicit Actor(SDL_Texture* texture, SDL_Rect* Shape, Eigen::Vector2f Position);

        virtual void Start() = 0;
        virtual void Update(double DeltaSeconds, double Seconds) = 0;

        [[nodiscard]] SDL_Texture* GetTexture() const;
        [[nodiscard]] const Eigen::Vector2f& GetPosition() const;
        [[nodiscard]] SDL_Rect* GetShape() const;

    public:
        void SetPosition(const Eigen::Vector2f& NewPosition);
    };
}


#endif //REALISTICENGINE_ACTOR_H
