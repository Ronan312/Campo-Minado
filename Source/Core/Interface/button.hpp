#pragma once
#include <functional>
#include "Vendors/SDL/SDL.h"

// Forward Declaration
class NineSlice;
class Mouse;

class Button {

    public:
        SDL_Rect        collision;          // Button Collision
        NineSlice*      sprite;             // Nine Slice Sprite
        Mouse*          mouse;
        SDL_Renderer*   renderer;           // Render instance
        SDL_Texture*    texText;

        Button(SDL_Renderer* render);

        void Update();
        void Render(SDL_Renderer* render);

        void SetText(const char *text, SDL_Color color = {0, 0, 0, 255});
        void SetTextPosition(int x, int y, int scale);
        void SetPosition(int x, int y, int w, int h);
        void SetCallback(std::function<void()> callback);       // Set Function to be called when button be pressed

    private:
        std::function<void()> callback;
        SDL_Rect        textFrame;
        SDL_Rect        textPosition;

};