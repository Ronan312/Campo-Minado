#pragma once
#include "Vendors/SDL/SDL.h"

class Mouse {

    public:

        
        bool pressed[2] = { false };                    // Hold mouse buttons conditions

        void       HandleEvents(SDL_Event* events);     // Check Events in framework
        bool       CheckCollision(SDL_Rect* other);     // Check if mouse is colliding with a rectangle

        void       SetLocked(bool can_lock);            // Disable use of mouse
        bool       IsLocked();                          // Check if mouse is locked
        SDL_Point* GetMousePosition();                  // Return a X and Y coordinate from mouse on screen
        void       ResetMouseClick();                   // Reset array buttons to false

    private:
        SDL_Point position;
        bool locked = false;


};