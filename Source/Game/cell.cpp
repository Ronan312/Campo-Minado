#include "Game/cell.hpp"

Cell::Cell(){

    // Set sprite frame to initial brick
    frame.x = frame.y = 0;
    frame.w = frame.h = 16;

    // Set initial object position in game world
    position.x = position.y = 0;
    position.w = position.h = 16;


};

void Cell::Render(SDL_Renderer* render){

    this->frame.x = (haveWarning) ? 48 : 0;
    
    // if (haveWarning) this->frame.x = 48;

    // check if the cell has been revealed
    if (wasClicked) {
        
        // Defines the corresponding brick with the cell content
        this->frame.x = 16 + (16 * (int)flag);

        // If the content is a number, it defines the brick with the number of adjacent bombs
        if (flag == ECellFlag::Number) this->frame.x = 48 + (16 * numBombsAdj);
        
    }

    // Render in screen
    SDL_RenderCopy(render, sprite, &frame, &position);   

};