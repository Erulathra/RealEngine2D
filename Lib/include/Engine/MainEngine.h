#ifndef GRY2D_MAINENGINE_H
#define GRY2D_MAINENGINE_H

#include <memory>
#include <cstdint>
#include <utility>
#include <list>
#include "SDL2/SDL.h"
#include "Eigen/Core"

namespace RealisticEngine
{
    class Actor;

    class MainEngine
    {
    public:
        Eigen::Vector2f CameraLocation;
    private:
        std::shared_ptr<std::pair<uint16_t, uint16_t>> Resolution;
        std::list<std::shared_ptr<Actor>> ActorList;

        SDL_Window* Window;
        SDL_Renderer* Renderer;

    public:
        MainEngine();
        virtual ~MainEngine();

        bool Init();
        int GameLoop();

        void SpawnActor(std::shared_ptr<Actor> Actor);

        [[nodiscard]] SDL_Renderer* GetRenderer() const;
        const Eigen::Vector2f& GetCameraLocation() const;
        void SetCameraLocation(const Eigen::Vector2f& CameraLocation);
        [[nodiscard]] const std::shared_ptr<std::pair<uint16_t, uint16_t>>& GetResolution() const;
    };

} // RealisticEngine

#endif //GRY2D_MAINENGINE_H
