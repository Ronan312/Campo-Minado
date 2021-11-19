#pragma once
#include "Vendors/SDL/SDL.h"

class SceneBase {

    public:

        virtual void Update() = 0;
        virtual void Render(SDL_Renderer* render) = 0;

};