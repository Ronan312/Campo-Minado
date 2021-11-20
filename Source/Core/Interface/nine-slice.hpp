#pragma once
#include "Vendors/SDL/SDL.h"

class NineSlice {

    public:

        NineSlice();
        void SetPosition(int left, int top, int right, int bottom);
        void SetScale(int scale);
        int  GetScale();
        void Render(SDL_Renderer* render);

    private:
        int scale = 16;
        SDL_Texture* sprite;
        SDL_Rect frame[9];
        SDL_Rect position[9];

};
