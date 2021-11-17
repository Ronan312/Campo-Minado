#include <iostream>
// #define SDL_MAIN_HANDLED
#include "Vendors/SDL/SDL.h"

class Application {

    public:
        Application();
        ~Application();

        void Initialize();
        void Shutdown();
        void Run();

        void HandleEvents();
        void Update();
        void Render();
    
    private:
        bool           isRunning    = false;
        SDL_Window*    window       = nullptr;
        SDL_Renderer*  renderer     = nullptr;
        SDL_Event*     events       = nullptr;



};