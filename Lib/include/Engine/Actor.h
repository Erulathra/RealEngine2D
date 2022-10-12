#ifndef REALISTICENGINE_ACTOR_H
#define REALISTICENGINE_ACTOR_H

#include <SDL2/SDL.h>
#include <Eigen/Core>
#include <memory>
#include <vector>

namespace RealisticEngine {
    class Actor {
    private:
        Eigen::Vector2f Position;
    protected:
        class MainEngine* Engine;

    public:
        explicit Actor(Eigen::Vector2f Position);

        virtual void Start() = 0;
        virtual void Update(double DeltaSeconds, double Seconds, std::vector<SDL_Event>& EventSet) = 0;

        [[nodiscard]] const Eigen::Vector2f& GetPosition() const;
        virtual void SetPosition(const Eigen::Vector2f& NewPosition);

        void SetEngine(MainEngine* NewEngine);
    };
}


#endif //REALISTICENGINE_ACTOR_H
