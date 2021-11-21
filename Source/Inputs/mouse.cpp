#include "Inputs/mouse.hpp"
#include <iostream>

void Mouse::HandleEvents(SDL_Event* events){

    // Check events from framework
    switch(events->type){

        // Get Mouse movement in screen
        case SDL_MOUSEMOTION: 

            // Set mouse position
            position.x = events->motion.x;
            position.y = events->motion.y;

            // if mouse is locked remove position from screen
            if (locked) position.x = position.y = -1;
        
        break;

        // Check if mouse button has pressed
        case SDL_MOUSEBUTTONDOWN: 

            if (!locked) {

                // Set mouse pressed in array as true
                if (events->button.button == SDL_BUTTON_LEFT)   this->pressed[0] = true;
                if (events->button.button == SDL_BUTTON_RIGHT)  this->pressed[1] = true;
            
            };
        
        break;

    }

};

void Mouse::ResetMouseClick(){

    // Set all buttons in array as false
    for (int i = 0; i < 2; i++){
        this->pressed[i] = false;
    }

};

bool Mouse::CheckCollision(SDL_Rect* other){

    // Check a Rect Collision with a Point (Following AABB principle) 
    if ((position.x >= other->x && position.x <= other->x + other->w) && 
        (position.y >= other->y && position.y <= other->y + other->h)) {

        return true;

    };

    return false;

};

void Mouse::SetLocked(bool can_lock) { locked = can_lock; };
bool Mouse::IsLocked()               { return locked;     };
SDL_Point* Mouse::GetMousePosition() { return &position;  };
