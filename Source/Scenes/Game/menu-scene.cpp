#include "Scenes/Game/menu-scene.hpp"
#include <string>
#include "Vendors/SDL/SDL_ttf.h"
#include "Scenes/scene-manager.hpp"
#include "Inputs/mouse.hpp"
#include "Core/application.hpp"
#include "Core/Interface/button.hpp"
#include "Game/game-controller.hpp"
#include "Scenes/Game/game-scene.hpp"

MenuScene::MenuScene(){

    // Get Static instances
    mouse = Application::mouse;
    sceneManager = Application::sceneManager;

};

void MenuScene::Initialize(){

    // Create buttons instances
    btnNewGame      =   new Button(renderer);
    btnExit         =   new Button(renderer);
    btnGameStart    =   new Button(renderer);
    
    for(int i = 0; i < 3; i++){
        btnIncrease[i] = new Button(renderer);
        btnDecrease[i] = new Button(renderer);
    }

    InitializeMenuButtons();
    InitializeConfigButtons();

};
void MenuScene::Update() {

    // Update Scene based on their state
    // 0 = Main Menu
    // 1 = Game Options
    switch(state){

        case 0: 

            // Update start buttons
            btnNewGame->Update();
            btnExit->Update();

        break;
        case 1: 

            // Update config buttons
            for (int i = 0; i < 3; i++){
                btnIncrease[i]->Update();
                btnDecrease[i]->Update();
            }

            btnGameStart->Update();

        break;

    };

};
void MenuScene::Render(SDL_Renderer* render) {

    SDL_SetRenderDrawColor(render, 120, 88, 88, 255);    // Draw a new color inside render

    // Render Scene based on their state
    // 0 = Main Menu
    // 1 = Game Options
    switch(state){

        case 0: 

            // Render start buttons
            btnNewGame->Render(render);
            btnExit->Render(render);

        break;
        
        case 1: 

            // Render Text with variable values
            DinamicText(render, ("Grid Width: " + std::to_string(GameController::width)).c_str(), 192, 96);
            DinamicText(render, ("Grid Height: " + std::to_string(GameController::height)).c_str(), 192, 224);
            DinamicText(render, ("Grid Max Bombs: " + std::to_string(GameController::maxBombs)).c_str(), 192, 352);

            // Render config buttons 
            for (int i = 0; i < 3; i++){

                btnIncrease[i]->Render(render);
                btnDecrease[i]->Render(render);
                
            }
            btnGameStart->Render(render);

        break;

    };

};

void MenuScene::InitializeMenuButtons(){

    // New Game Button
    btnNewGame->SetPosition(400, 272, 880, 320);
    btnNewGame->SetCallback([&](){
        state = 1;
    });
    btnNewGame->SetText("New Game");
    btnNewGame->SetTextPosition(128, 8, 3);

    // Exit Game Button
    btnExit->SetPosition(400, 400, 880, 448);
    btnExit->SetCallback([&](){});
    btnExit->SetText("Exit Game");
    btnExit->SetTextPosition(144, 8, 3);

};

void MenuScene::InitializeConfigButtons(){

    // ===================================================================================================
    // Increase Width Grid
    btnIncrease[0]->SetPosition(800, 96, 832, 128);
    btnIncrease[0]->SetCallback([&](){

        if (GameController::width < 80) GameController::width++;
    
    });
    btnIncrease[0]->SetText("+");
    btnIncrease[0]->SetTextPosition(20, 2, 3);

    // Decrease Width Grid
    btnDecrease[0]->SetPosition(880, 96, 912, 128);
    btnDecrease[0]->SetCallback([&](){

        if (GameController::width > 0) GameController::width--;
    
    });
    btnDecrease[0]->SetText("-");
    btnDecrease[0]->SetTextPosition(24, 0, 3);
    
    // ===================================================================================================
    // Increase Height Grid
    btnIncrease[1]->SetPosition(800, 224, 832, 256);
    btnIncrease[1]->SetCallback([&](){

        if (GameController::height < 45) GameController::height++;
    
    });
    btnIncrease[1]->SetText("+");
    btnIncrease[1]->SetTextPosition(20, 2, 3);
    
    // Decrease Height Grid
    btnDecrease[1]->SetPosition(880, 224, 912, 256);
    btnDecrease[1]->SetCallback([&](){

        if (GameController::height > 0) GameController::height--;
    
    });
    btnDecrease[1]->SetText("-");
    btnDecrease[1]->SetTextPosition(24, 0, 3);
    
    // ===================================================================================================
    // Increase Max Bombs in Grid
    btnIncrease[2]->SetPosition(800, 352, 832, 384);
    btnIncrease[2]->SetCallback([&](){
    
        int gridSize = GameController::width * GameController::height;

        if (GameController::maxBombs < 255 && GameController::maxBombs < gridSize - 10)
            GameController::maxBombs++;
    
    });
    btnIncrease[2]->SetText("+");
    btnIncrease[2]->SetTextPosition(20, 2, 3);

    // Decrease Max Bombs in Grid
    btnDecrease[2]->SetPosition(880, 352, 912, 384);
    btnDecrease[2]->SetCallback([&](){

        if (GameController::maxBombs > 0) GameController::maxBombs--;
    
    });
    btnDecrease[2]->SetText("-");
    btnDecrease[2]->SetTextPosition(24, 0, 3);

    // ===================================================================================================
    // Start Game Button
    btnGameStart->SetPosition(400, 480, 880, 528);
    btnGameStart->SetCallback([&](){
        
        sceneManager->gameScene->InitializeBoard();
        sceneManager->ChangeScene(EScene::Game);

    });
    btnGameStart->SetText("Start Game");
    btnGameStart->SetTextPosition(32, 8, 3);

};

void MenuScene::DinamicText(SDL_Renderer* render, const char* text, int x, int y){

    // Save text in surface and convert to texture
    SDL_Surface* surf = TTF_RenderText_Solid(Application::font, text, {0, 0, 0, 255});      
    SDL_Texture* tex = SDL_CreateTextureFromSurface(render, surf);

    // Generate Frame and Position
    SDL_Rect textFrame, textPosition;

    // Set Texture Frame
    textFrame.x = textFrame.y = 0;
    SDL_QueryTexture(tex, NULL, NULL, &textFrame.w, &textFrame.h);

    // Set Position in game world
    textPosition.x = x;
    textPosition.y = y;
    textPosition.w = textFrame.w * 2;
    textPosition.h = textFrame.h * 2;

    // Render texture
    SDL_RenderCopy(render, tex, &textFrame, &textPosition);

    // Delete Surface and Texture
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(tex);

};