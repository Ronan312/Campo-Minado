#pragma once
#include "Vendors/SDL/SDL.h"

class Mouse {

    public:

        SDL_Point position;
        bool pressed[2] = { false };
        bool locked = false;
        void HandleEvents(SDL_Event* events);

    private:

};