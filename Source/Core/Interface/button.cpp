#include "Core/Interface/button.hpp"
#include "Vendors/SDL/SDL_ttf.h"
#include "Core/Interface/nine-slice.hpp"
#include "Core/application.hpp"

Button::Button(SDL_Renderer* render){

    sprite = new NineSlice();
    mouse = Application::mouse;
    renderer = render;

};

void Button::SetText(const char *text, SDL_Color color){

    SDL_Surface* surf = TTF_RenderText_Solid(Application::font, text, color);
    texText = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);

    textFrame.x = textFrame.y = 0;
    SDL_QueryTexture(texText, NULL, NULL, &textFrame.w, &textFrame.h);

};

void Button::SetTextPosition(int x, int y, int scale){

    textPosition.x = collision.x + x;
    textPosition.y = collision.y + y;
    textPosition.w = textFrame.w * scale;
    textPosition.h = textFrame.h * scale;

};

void Button::SetPosition(int x, int y, int w, int h){

    sprite->SetPosition(x, y, w, h);
    collision.x = x;
    collision.y = y;
    collision.w = (w - x) + (sprite->GetScale() * 2);
    collision.h = (h - y) + (sprite->GetScale() * 2);

};

void Button::SetCallback(std::function<void()> callback){

    this->callback = callback;

};

void Button::Update(){

    if (mouse->CheckCollision(&collision) && mouse->pressed[0]){
        this->callback();
    };

};

void Button::Render(SDL_Renderer* render){

    sprite->Render(render);
    if (texText) SDL_RenderCopy(render, texText, &textFrame, &textPosition);

};