#pragma once
#include "Vendors/SDL/SDL.h"

class Mouse {

    public:

        
        bool pressed[2] = { false };

        void       HandleEvents(SDL_Event* events);
        bool       CheckCollision(SDL_Rect* other);

        void       SetLocked(bool can_lock); 
        bool       IsLocked();
        SDL_Point* GetMousePosition();

    private:

        SDL_Point position;
        bool locked = false;


};