#include "Scenes/Game/game-over-scene.hpp"
#include "Scenes/scene-manager.hpp"
#include "Inputs/mouse.hpp"
#include "Game/grid.hpp"
#include "Core/application.hpp"
#include "Game/game-controller.hpp"

GameOverScene::GameOverScene(){

    // Get Application instances
    mouse = Application::mouse;
    sceneManager = Application::sceneManager;

};

void GameOverScene::Initialize(){

    // Initialize Text Texture
    CreateText();

};
void GameOverScene::Update() {};
void GameOverScene::Render(SDL_Renderer* render) {

    SDL_SetRenderDrawColor(render, 88, 88, 120, 255);    // Draw a new color inside render
    grid->Render(render);
    SDL_RenderCopy(render, textTex, &textFrame, &textPosition);

};

void GameOverScene::CreateText(){

    SDL_Surface* surf;
    // Create a diferent text based on win or lose
    if (GameController::winGame)
        surf = TTF_RenderText_Shaded(Application::font, "You Win!", {255, 255, 255, 255}, {0, 0, 0, 255});
    else
        surf = TTF_RenderText_Shaded(Application::font, "You Lose!", {255, 255, 255, 255}, {0, 0, 0, 255});


    // Convert surface to texture
    textTex = SDL_CreateTextureFromSurface(renderer, surf);

    // Set Texture Frame
    textFrame.x = textFrame.y = 0;
    SDL_QueryTexture(textTex, NULL, NULL, &textFrame.w, &textFrame.h);

    // Set Text in screen
    textPosition.x = static_cast<int>(1280.0f * 0.5f) - 260;
    textPosition.y = static_cast<int>(720.0f * 0.25f);
    textPosition.w = textFrame.w * 8;
    textPosition.h = textFrame.h * 8;

};