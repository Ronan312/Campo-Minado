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

        void Render(SDL_Renderer* render);          // Render the entire game grid

        // Getters
        Cell*   GetCell(int x, int y);
        uint8_t GetWidth();
        uint8_t GetHeight();
        uint8_t GetMaxBombs();
        bool    CheckAllBombsMarkedAsWarning();     // Return true if bombs quantity is equal maximum quantity of bombs
        bool    CheckAllCellWasRevealed();          // Return true if quantity of cells revealed is equals total of cells in grid

        // Create the game board with a specific size and number of bombs 
        void InitializeBoard();
        
        void RevealCell(Cell* cell);                // Reveal Cell passed in function
        void RevealAllCell();                       // Reveal All Cell in board
        void RevealBlankCell(int x, int y);         // Reveal Cell in coordinate if was blank
        void SetWarningInCell(int x, int y);        // Put a Warning Flag on cell
       
    private:
    
        GridCell board;                             // Game Grid
        uint8_t  width          = 0;                // Width of cells
        uint8_t  height         = 0;                // Height of cells
        uint8_t  maxBombs       = 0;                // Maximum quantity bombs we have in grid 
        uint8_t  bombsQuantity  = 0;                // Quantity of bombs discovered by flag
        uint16_t cellTotal      = 0;                // Quantity of cells calculate by width * height
        uint16_t cellRevealed   = 0;                // Quantity of bombs revealed
        std::vector<Cell*> cellsMarkedAsWarning;    // Array of cells with a flag

        void GenerateCells();                       // Create a blank grid of Cells
        void GenerateBombs();                       // Find some random tiles and set their content to be a bomb
        void CreateNumberTiles();                   // Create the numbered cells adjacent to the bombs. 

        Cell* GetRandomCell();                      // Return a randomize Cell in Game Board

        void MarkCellAsWarning(Cell* cell);    
        void RemoveWarningFromCell(Cell* cell);
        void CountBombsWithWarningFlag();           // Loop through Array of cells with a flag and add to bombs quantity

        
};