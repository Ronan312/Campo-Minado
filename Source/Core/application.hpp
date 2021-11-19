#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "Vendors/SDL/SDL.h"
#include "Game/grid.hpp"
#include "Inputs/mouse.hpp"

class Application {

    public:

        static std::unordered_map<std::string, SDL_Texture*> resources;

        Application();
        ~Application();

        void Initialize();
        void Shutdown();
        void Run();

        void HandleEvents();
        void Update();
        void Render();

        void MouseClick();

        static void LoadAssets(SDL_Renderer* render);
        
    private:
        bool           isRunning    = false;
        SDL_Window*    window       = nullptr;
        SDL_Renderer*  renderer     = nullptr;
        SDL_Event*     events       = nullptr;
        Grid*          grid         = nullptr;
        Mouse*         mouse        = nullptr;


};