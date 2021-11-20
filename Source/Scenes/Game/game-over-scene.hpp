#pragma once
#include "Vendors/SDL/SDL.h"
#include "Scenes/scene-base.hpp"

// Forward Declaration
class Mouse;
class SceneManager;
class Grid;

class GameOverScene : public SceneBase {

    public:
        Mouse* mouse;
        SceneManager* sceneManager;
        Grid* grid;

        void Update() override;
        void Render(SDL_Renderer* render) override;


};