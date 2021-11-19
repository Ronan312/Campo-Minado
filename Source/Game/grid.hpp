#pragma once
#include <iostream>
#include <vector>
#include <cstdint>
#include "Vendors/SDL/SDL.h"
#include "Game/cell.hpp"

typedef std::vector<std::vector<Cell*>> GridCell;

class Grid {

    public:

        Grid(uint8_t width, uint8_t height, uint8_t max_bomb);

        // Create the game board with a specific size and number of bombs 
        void InitializeBoard();
        void GenerateCells();                       // Create a blank Cell
        void GenerateBombs();                       // Find some random tiles and set their content to be a bomb
        void CreateNumberTiles();                   // Create the numbered cells adjacent to the bombs. 
        void RevealCell(Cell* cell);                // Reveal Cell passed in function
        void RevealBlankCell(int x, int y);         // Reveal Cell in coordinate if was blank
        void PutWarningInCell(int x, int y);        // Put a Warning Flag on cell

        void Render(SDL_Renderer* render);          // Render the entire game grid

        Cell* GetCell(int x, int y);
        uint8_t GetWidth();
        uint8_t GetHeight();
        uint8_t GetMaxBombs();
        bool    CheckAllBombsWasMarkedAsWarning();
        bool    CheckAllCellWasRevealed();

    private:
    
        GridCell board;
        uint8_t  width          = 0;
        uint8_t  height         = 0;
        uint8_t  maxBombs       = 0;
        uint8_t  bombsQuantity  = 0;
        uint16_t cellTotal      = 0;
        uint16_t cellRevealed   = 0;
        std::vector<Cell*> cellsMarkedAsWarning;

        Cell* GetRandomCell();                      // Return a randomize Cell in Game Board

};