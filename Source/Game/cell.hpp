#pragma once
#include <iostream>
#include "Vendors/SDL/SDL.h"
#include "Definitions/cell.hpp"

class Cell {

    public:

        Cell();

        SDL_Texture* sprite;
        
        int       numBombsAdj   = 0;
        bool      wasClicked    = true;
        ECellFlag flag;
        SDL_Rect  frame;
        SDL_Rect  position;


        void Update();
        void Render(SDL_Renderer* render);

        void SetFlagByIntValue(int value);
    
    private:
        


};