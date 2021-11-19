#pragma once
#include <iostream>
#include <vector>
#include <cstdint>
#include "Vendors/SDL/SDL.h"
#include "Game/cell.hpp"

typedef std::vector<std::vector<Cell*>> GridCell;

class Grid {

    public:
        GridCell board;
        uint8_t width;
        uint8_t height;

        // Create the game board with a specific size and number of bombs 
        void InitializeBoard(uint8_t width, uint8_t height, uint8_t max_bomb);
        void GenerateCells();                       // Create a blank Cell
        void GenerateBombs(uint8_t max_bombs);      // Find some random tiles and set their content to be a bomb
        void CreateNumberTiles();                   // Create the numbered cells adjacent to the bombs. 
        void RevealBlankCell(int x, int y);         // Reveal Cell in coordinate if was blank

        void Render(SDL_Renderer* render);          // Render the entire game grid

    private:

        Cell* GetRandomCell();                      // Return a randomize Cell in Game Board


};