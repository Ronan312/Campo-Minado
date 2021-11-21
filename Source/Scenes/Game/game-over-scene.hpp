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
        SDL_Renderer* renderer;
        Grid* grid;

        GameOverScene();

        void Initialize();
        void Update() override;
        void Render(SDL_Renderer* render) override;
        void CreateText();

    private:
        SDL_Texture* textTex;
        SDL_Rect textFrame;
        SDL_Rect textPosition;


};