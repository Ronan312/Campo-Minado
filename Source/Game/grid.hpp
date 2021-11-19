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

        void InitializeBoard(uint8_t width, uint8_t height, uint8_t max_bomb);
        void GenerateTiles();
        void GenerateBombs(uint8_t max_bombs);
        void CreateNumberTiles();
        void NoneGridVisible(int x, int y);

        void Render(SDL_Renderer* render);

        uint8_t width;
        uint8_t height;
    private:

        Cell* GetRandomTile();


};