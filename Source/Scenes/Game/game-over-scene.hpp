#pragma once
#include "Vendors/SDL/SDL.h"
#include "Scenes/scene-base.hpp"

// Forward Declaration
class Mouse;
class SceneManager;

class GameOverScene : public SceneBase {

    public:
        Mouse* mouse;
        SceneManager* sceneManager;

        void Update() override;
        void Render(SDL_Renderer* render) override;


};