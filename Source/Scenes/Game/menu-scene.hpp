#pragma once
#include <cstdint>
#include "Vendors/SDL/SDL.h"
#include "Scenes/scene-base.hpp"

// Forward Declaration
class Mouse;
class SceneManager;
class Button;

class MenuScene : public SceneBase {

    public:

        Mouse* mouse;
        SceneManager* sceneManager;
        SDL_Texture* newGameText;
        SDL_Renderer* renderer;

        MenuScene();
        void Initialize();
        void Update() override;
        void Render(SDL_Renderer* render) override;

    private:
        uint8_t state = 0;
        Button* btnNewGame;
        Button* btnExit;
        Button* btnGameStart;
        Button* btnIncrease[3];
        Button* btnDecrease[3];

        void InitializeMenuButtons();
        void InitializeConfigButtons();
        void DinamicText(SDL_Renderer* render, const char* text, int x, int y);

};
