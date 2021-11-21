#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "Vendors/SDL/SDL.h"
#include "Vendors/SDL/SDL_ttf.h"
#include "Inputs/mouse.hpp"
#include "Scenes/scene-manager.hpp"
#include "Core/Interface/button.hpp"

typedef std::unordered_map<std::string, SDL_Texture*> ResourceMap; 

class Application {

    public:

        static ResourceMap      resources;
        static Mouse*           mouse;
        static SceneManager*    sceneManager;
        static TTF_Font*        font;

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
        Uint32         fps          = 30;
        Uint32         minFrametime = 1000 / fps;
        Uint32         frametime    = 0;
        SDL_Window*    window       = nullptr;
        SDL_Renderer*  renderer     = nullptr;
        SDL_Event*     events       = nullptr;

        void InitializeFramework();
        void InitializeWindow();
        void InitializeScenes();


};