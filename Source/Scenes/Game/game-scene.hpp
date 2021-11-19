#pragma once
#include "Vendors/SDL/SDL.h"
#include "Scenes/scene-base.hpp"

// Forward Declaration
class Grid;
class GameController;
class Mouse;
class SceneManager;

class GameScene : public SceneBase {

    public:

        Grid* grid;
        GameController* controller;
        Mouse* mouse;
        SceneManager* sceneManager;

        GameScene();
        void InitializeBoard();
        void Update() override;
        void Render(SDL_Renderer* render) override;

    private:
        void MouseClick();
        void MousePutFlag();

};