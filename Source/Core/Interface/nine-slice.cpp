#include "Core/Interface/nine-slice.hpp"
#include "Core/application.hpp"

NineSlice::NineSlice(){

    // Set Texture
    sprite = Application::resources["UI"];

    /* Create a Frame box on sprite image
        ┌───┬───┬───┐
        │ 0 │ 1 │ 2 │
        ├───┼───┼───┤
        │ 3 │ 4 │ 5 │
        ├───┼───┼───┤
        │ 6 │ 7 │ 8 │
        └───────────┘
    */
    
    // Corners
    // Top Left
    frame[0].x = 0;
    frame[0].y = 0;
    frame[0].w = frame[0].h = 8;
    // Top Right
    frame[2].x = 16;
    frame[2].y = 0;
    frame[2].w = frame[2].h = 8;
    // Bottom Left
    frame[6].x = 0;
    frame[6].y = 16;
    frame[6].w = frame[6].h = 8;
    // Bottom Right
    frame[8].x = 16;
    frame[8].y = 16;
    frame[8].w = frame[8].h = 8;

    // Edges
    // Left
    frame[3].x = 0;
    frame[3].y = 8;
    frame[3].w = frame[3].h = 8;
    // Right
    frame[5].x = 16;
    frame[5].y = 8;
    frame[5].w = frame[5].h = 8;
    // Top
    frame[1].x = 8;
    frame[1].y = 0;
    frame[1].w = frame[1].h = 8;
    // Bottom
    frame[7].x = 8;
    frame[7].y = 16;
    frame[7].w = frame[7].h = 8;

    // Middle
    frame[4].x = 8;
    frame[4].y = 8;
    frame[4].w = frame[4].h = 8;

};

void NineSlice::SetPosition(int left, int top, int right, int bottom){

    int width  = right - left;
    int height = bottom - top;
    int columns = width / this->scale; 
    int rows = height / this->scale; 

    /* Set Position from box
        ┌───┬───┬───┐
        │ 0 │ 1 │ 2 │
        ├───┼───┼───┤
        │ 3 │ 4 │ 5 │
        ├───┼───┼───┤
        │ 6 │ 7 │ 8 │
        └───────────┘
    */

    // Set all Size on screen by scale
    for (int i = 0; i < 9; i++) 
        position[i].w = position[i].h = scale;

    // Top Left
    position[0].x = left;
    position[0].y = top;
    // Top Right
    position[2].x = right + scale;
    position[2].y = top;
    // bottom left
    position[6].x = left;
    position[6].y = bottom + scale;
    // bottom right
    position[8].x = right + scale;
    position[8].y = bottom + scale;

    // Left
    position[3].x = left;
    position[3].y = top + scale;
    position[3].h = rows * scale;
    // right
    position[5].x = right + scale;
    position[5].y = top + scale;
    position[5].h = rows * scale;
    // Top
    position[1].x = left + scale;
    position[1].y = top;
    position[1].w = columns * scale;
    // bottom
    position[7].x = left + scale;
    position[7].y = bottom + scale;
    position[7].w = columns * scale;

    // Center
    position[4].x = left + scale;
    position[4].y = top + scale;
    position[4].w = columns * scale;
    position[4].h = rows * scale;

};

int NineSlice::GetScale(){
    return this->scale;
}
void NineSlice::SetScale(int scale){
    this->scale = scale;
};
void NineSlice::Render(SDL_Renderer* render){

    for (int i = 0; i < 9; i++){

        SDL_RenderCopy(render, sprite, &frame[i], &position[i]);

    }

};