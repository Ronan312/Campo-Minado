#include "Game/grid.hpp"
#include "Definitions/cell-flag.hpp"
#include "Core/application.hpp"
#include "Core/random.hpp"

Grid::Grid(uint8_t width, uint8_t height, uint8_t max_bomb){

    this->width = width;
    this->height = height;
    this->maxBombs = max_bomb;

};

void Grid::InitializeBoard(){

    GenerateCells();

    GenerateBombs();

    CreateNumberTiles();

};

void Grid::GenerateCells(){

    // Loop in row
    for (int i = 0; i < width; i++){
        
        // hold the cells on vertical
        std::vector<Cell*> column;

        // Loop in column
        for (int j = 0; j < height; j++){

            Cell* cell = new Cell();                            // Create a new cell pointer

            cell->sprite = Application::resources["Bricks"];    // Pointer on loaded brick texture
            cell->position.x = i * 16;                          // Define object position in game world by row
            cell->position.y = j * 16;                          // Define object position in game world by column
            cell->flag = ECellFlag::None;                       // Initialize content as none;

            // Insert cells on vertical position
            column.push_back(cell);

        }

        // Insert cells on game board
        board.push_back(column);

    }

};

void Grid::GenerateBombs(){

    // Loop on maximum quantity of bombs in game board
    for (int i = 0; i < maxBombs; i++){
            
        // Pointer to random tile
        Cell* cell = GetRandomCell();

        // Performs a loop to generate a new cell, 
        // avoiding coinciding with a cell that already has a bomb inside
        while (cell->flag == ECellFlag::Bomb){
            
            cell = GetRandomCell();

        } 

        // Put a bomb flag in the cell
        cell->flag = ECellFlag::Bomb;

    }

};

void Grid::CreateNumberTiles(){

    // Array from 8 adjacent directions 
    int dir[8][2] = { {-1, -1}, {0, -1}, {1, -1},
                      {-1,  0},          {1,  0},
                      {-1,  1}, {0,  1}, {1,  1} };

    // Loop inside Game Board
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            
            // Get Active Cell
            Cell* cell = board[i][j];

            // Loop in 8 directions
            for (int l = 0; l < 8; l++){
                
                // Get adjacent position
                int x = i + dir[l][0];
                int y = j + dir[l][1];

                // Ignore if in grid limits
                if ((x < 0 || x >= width) || (y < 0 || y >= height)) continue;

                // Checks that AdjCell is a bomb and that the active cell is not a bomb
                Cell* adjCell = board[x][y];
                if (adjCell->flag == ECellFlag::Bomb && cell->flag != ECellFlag::Bomb){

                    // Set Active Cell as Number and increase number of bombs adjacent
                    cell->flag = ECellFlag::Number;
                    cell->numBombsAdj++;
                
                };

            };

        };

    };

};

void Grid::Render(SDL_Renderer* render){

    // Loop on Game Board
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){

            // Get Cell and call your Render Function
            Cell* cell = board[i][j];
            cell->Render(render);

        }
    }

};

Cell* Grid::GetRandomCell(){

    // Get a random position on grid size
    int x = Random::UniformInteger<int>(0, width-1);
    int y = Random::UniformInteger<int>(0, height-1);

    // Return a random Cell on grid
    return board[x][y];

};

void Grid::RevealBlankCell(int x, int y){

    // Array from 4 adjacent directions 
    int dir[4][2] = {           { 0, -1}, 
                      { -1,  0},         { 1,  0}, 
                                { 0,  1}         };

    // Get actual cell and reveal
    Cell* cell = board[x][y];
    cell->wasClicked = true;

    // Loop in 4 directions
    for (int i = 0; i < 4; i++){

        // Get Adjacent Position
        int xCell = x + dir[i][0]; 
        int yCell = y + dir[i][1];

        // Ignore if in grid limits
        if ((xCell < 0 || xCell >= width) || (yCell < 0 || yCell >= height)) continue;

        // Get adjacent cell pointer
        Cell* adjCell = board[xCell][yCell];

        // Check that adjcell does not have any content and has not yet been revealed 
        // to recursively traverse all other similar cells 
        if (adjCell->flag == ECellFlag::None && !adjCell->wasClicked) RevealBlankCell(xCell, yCell);

    };
    
};

Cell*   Grid::GetCell(int x, int y)     { return board[x][y];   };
uint8_t Grid::GetWidth()                { return width;         };
uint8_t Grid::GetHeight()               { return height;        };
uint8_t Grid::GetMaxBombs()             { return maxBombs;      };