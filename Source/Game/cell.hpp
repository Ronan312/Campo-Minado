#pragma once
#include <iostream>
#include "Vendors/SDL/SDL.h"
#include "Definitions/cell-flag.hpp"

class Cell {

    public:

        Cell();

        int          numBombsAdj   = 0;             // Number of bombs adjacent if cell flag was a Number
        bool         wasClicked    = false;         // Check if this cell was revealed 
        ECellFlag    flag;                          // A Flag to hold cell content 
        SDL_Rect     frame;                         // A Frame on image texture
        SDL_Rect     position;                      // Object in Game World
        SDL_Texture* sprite;                        // Cell Sprite Pointer

        void Render(SDL_Renderer* render);          // Render Object in framework

};