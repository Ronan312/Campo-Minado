#include "Game/cell.hpp"

Cell::Cell(){

    // Set sprite frame
    this->frame.x = 0; this->frame.y = 0;
    this->frame.w = 16; this->frame.h = 16;

    position.x = 0; position.y = 0;
    position.w = 16; position.h = 16;

};

void Cell::Update(){

   

};

void Cell::Render(SDL_Renderer* render){

    if (wasClicked) this->frame.x = 16 + (16 * (int)flag);
    if (flag == ECellFlag::Number) this->frame.x = 48 + (16 * numBombsAdj);;

    SDL_RenderCopy(render, sprite, &frame, &position);   

};

void Cell::SetFlagByIntValue(int value){
    flag = (ECellFlag)value;    
};