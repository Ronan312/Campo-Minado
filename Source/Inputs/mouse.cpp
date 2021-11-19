#include "Inputs/mouse.hpp"
#include <iostream>

void Mouse::HandleEvents(SDL_Event* events){

    switch(events->type){

        case SDL_MOUSEMOTION: 
        
            position.x = events->motion.x;
            position.y = events->motion.y;

            if (locked) position.x = position.y = -1;
        
        break;
        case SDL_MOUSEBUTTONDOWN: 

            if (!locked) {

                if (events->button.button == SDL_BUTTON_LEFT)   this->pressed[0] = true;
                if (events->button.button == SDL_BUTTON_RIGHT)  this->pressed[1] = true;
            
            };
        
        break;

        case SDL_MOUSEBUTTONUP: 
        
            if (events->button.button == SDL_BUTTON_LEFT)   this->pressed[0] = false;
            if (events->button.button == SDL_BUTTON_RIGHT)  this->pressed[1] = false;
        
        break;

    }

};