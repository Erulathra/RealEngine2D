
#include "Engine/MainEngine.h"
#include "SDL2/SDL.h"
#include "chrono"
#include <SDL_image.h>
#include <set>

#include "Engine/Actor.h"

namespace RealisticEngine {
    MainEngine::MainEngine() {
        Resolution = std::make_shared<std::pair<uint16_t, uint16_t>>(640, 480);
        CameraLocation = Eigen::Vector2f(0, 0);
    }

    bool RealisticEngine::MainEngine::Init() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
            return false;
        }

        Window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Resolution->first,
                                  Resolution->second, SDL_WINDOW_SHOWN);
        if (Window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            return false;
        }

        Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

        if ( !(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                return false;
        }

        return true;
    }

    int RealisticEngine::MainEngine::GameLoop() {
        SDL_Event Event;

        for (std::shared_ptr<RealisticEngine::Actor> Actor : ActorList) {
            Actor->Start();
        }

        std::chrono::duration<double> DeltaSecond{};
        auto StartTime = std::chrono::high_resolution_clock::now();
        auto LastFrameEndTime = StartTime;
        for (;;) {
            auto StartFrameTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> FrameStartSeconds = StartTime - StartFrameTime;

            std::vector<SDL_Event> EventSet;

            while (SDL_PollEvent(&Event)) {
                EventSet.push_back(Event);

                if (Event.type == SDL_QUIT) {
                    SDL_DestroyWindow(Window);
                    return 0;
                }
            }
            SDL_SetRenderDrawColor(Renderer, 30, 30, 46, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(Renderer);

            for (std::shared_ptr<Actor> Actor : ActorList) {
                Actor->Update(DeltaSecond.count(), FrameStartSeconds.count(), EventSet);
                //if (Actor->GetTexture())
                    //SDL_RenderCopy(Renderer, Actor->GetTexture(), nullptr, Actor->GetShape() );
            }

            SDL_RenderPresent(Renderer);
            DeltaSecond = std::chrono::high_resolution_clock::now() - LastFrameEndTime;
            LastFrameEndTime = std::chrono::high_resolution_clock::now();
        }
    }

    MainEngine::~MainEngine() {}

    void RealisticEngine::MainEngine::SpawnActor(std::shared_ptr<RealisticEngine::Actor> Actor) {
        ActorList.push_front(Actor);
        Actor->SetEngine(this);
    }

    SDL_Renderer *MainEngine::GetRenderer() const {
        return Renderer;
    }

    const std::shared_ptr<std::pair<uint16_t, uint16_t>>& MainEngine::GetResolution() const
    {
        return Resolution;
    }

    const Eigen::Vector2f& MainEngine::GetCameraLocation() const
    {
        return CameraLocation;
    }

    void MainEngine::SetCameraLocation(const Eigen::Vector2f& CameraLocation)
    {
        MainEngine::CameraLocation = CameraLocation;

        for (const auto & A: ActorList)
        {
            A->SetPosition(A->GetPosition());
        }
    };
} // RealisticEngine