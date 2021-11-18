#include "Game/grid.hpp"
#include "Definitions/cell.hpp"
#include "Core/application.hpp"
#include "Core/random.hpp"

void Grid::InitializeBoard(uint8_t width, uint8_t height, uint8_t max_bomb){

    this->width = width;
    this->height = height;

    GenerateTiles();

    GenerateBombs(max_bomb);

    CreateNumberTiles();

};

void Grid::GenerateTiles(){

    for (int i = 0; i < width; i++){
        
        std::vector<Cell*> column;
        for (int j = 0; j < height; j++){

            Cell* cell = new Cell();
            cell->sprite = Application::resources["Bricks"];
            cell->position.x = i * 16;
            cell->position.y = j * 16;
            cell->flag = ECellFlag::None;

            column.push_back(cell);

        }

        board.push_back(column);
    }

};

void Grid::GenerateBombs(uint8_t max_bombs){

    for (int i = 0; i < max_bombs; i++){
            
        Cell* cell = GetRandomTile();

        while (cell->flag == ECellFlag::Bomb){
            
            cell = GetRandomTile();

        } 

        cell->flag = ECellFlag::Bomb;

    }

};

void Grid::CreateNumberTiles(){

    int dir[8][2] = { {-1,  0}, {-1, -1}, { 0, -1}, 
                      { 1, -1},           { 1,  0}, 
                      { 1,  1}, { 0,  1}, {-1,  1}};

    // Loop inside Grid
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            
            // Get Active Cell
            Cell* cell = board[i][j];

            // Loop in 8 directions
            for (int l = 0; l < 8; l++){
                
                // Get adjacent position
                int x = i + dir[l][0];
                int y = j + dir[l][1];

                // Ignore if in limits
                if ((x < 0 || x >= width) || (y < 0 || y >= height)) continue;

                // Get if AdjCell is a bomb
                Cell* adjCell = board[x][y];
                if (adjCell->flag == ECellFlag::Bomb && cell->flag != ECellFlag::Bomb){

                    // Set Active Cell as Number
                    cell->flag = ECellFlag::Number;
                    cell->numBombsAdj++;
                
                }

            }

        };
    };

};

void Grid::Render(SDL_Renderer* render){

    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){

            Cell* cell = board[i][j];
            cell->Render(render);

        }
    }

};

Cell* Grid::GetRandomTile(){

    int x = Random::UniformInteger<int>(0, width-1);
    int y = Random::UniformInteger<int>(0, height-1);

    return board[x][y];

};