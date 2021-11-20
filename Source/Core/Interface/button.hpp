#pragma once
#include <functional>
#include "Vendors/SDL/SDL.h"

// Forward Declaration
class NineSlice;
class Mouse;

class Button {

    public:
        SDL_Rect        collision;
        NineSlice*      sprite;
        Mouse*          mouse;
        SDL_Renderer*   renderer;
        SDL_Texture*    texText;

        Button(SDL_Renderer* render);

        void Update();
        void Render(SDL_Renderer* render);

        void SetText(const char *text, SDL_Color color = {0, 0, 0, 255});
        void SetTextPosition(int x, int y, int scale);
        void SetPosition(int x, int y, int w, int h);
        void SetCallback(std::function<void()> callback);

    private:
        std::function<void()> callback; 
        SDL_Rect        textFrame;
        SDL_Rect        textPosition;

};