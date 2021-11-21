#include "Scenes/Game/game-scene.hpp"
#include <chrono>
#include "Core/random.hpp"
#include "Core/application.hpp"
#include "Scenes/scene-manager.hpp"
#include "Game/game-controller.hpp"
#include "Game/grid.hpp"
#include "Game/cell.hpp"
#include "Inputs/mouse.hpp"
#include "Scenes/Game/game-over-scene.hpp"

GameScene::GameScene(){

    // Get static instances
    mouse        = Application::mouse;
    sceneManager = Application::sceneManager;

};

void GameScene::InitializeBoard(){

    // Set Seed for Randomize tiles
    auto now = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    uint_fast32_t seed = static_cast<uint_fast32_t>(now);
    Random::Seed(seed);

    // Initialize Grid
    grid = new Grid(GameController::width, GameController::height, GameController::maxBombs);
    grid->InitializeBoard();

};

void GameScene::Update() {

    this->MouseClick();
    this->MousePutFlag();

    this->CheckWinCondition();

};

void GameScene::CheckWinCondition(){

    // Check two win conditions
    if (grid->CheckAllBombsMarkedAsWarning() || grid->CheckAllCellWasRevealed()){

        
        GoToGameOverScene();
    
    };

};

void GameScene::Render(SDL_Renderer* render) {

    SDL_SetRenderDrawColor(render, 88, 88, 88, 255);    // Draw a new color inside render

    grid->Render(render);

};

void GameScene::MouseClick(){

    // Check if mouse isnt locked and left button was pressed
    if (mouse->pressed[0] && !mouse->IsLocked()){

        // Get mouse position in grid
        SDL_Point* mousePos = mouse->GetMousePosition();
        int x = mousePos->x / 16;
        int y = mousePos->y / 16;

        // Check if Coordinates is in limits and ignore
        if ((x < 0 || x >= grid->GetWidth()) || (y < 0 || y >= grid->GetHeight())) return;

        // Get cell
        Cell* cell = grid->GetCell(x, y);

        // If have warning then cant click
        if (cell->haveWarning) return;

        grid->RevealCell(cell);

        // if was a blank cell reveal all blanks adjacent
        if (cell->flag == ECellFlag::None) grid->RevealBlankCell(x, y);

        // if was a bomb, call a game over function
        if (cell->flag == ECellFlag::Bomb){

            // Set cell as red bomb to indicate what bomb was pressed
            cell->flag = ECellFlag::BombClicked;

            this->GoToGameOverScene();

        };


    }

};
void GameScene::MousePutFlag(){

    // Check if mouse isnt locked and right button was pressed
    if (mouse->pressed[1] && !mouse->IsLocked()){

        // Get mouse position in grid
        SDL_Point* mousePos = mouse->GetMousePosition();
        int x = mousePos->x / 16;
        int y = mousePos->y / 16;

        // Check if Coordinates is in limits and ignore
        if ((x < 0 || x >= grid->GetWidth()) || (y < 0 || y >= grid->GetHeight())) return;

        // Set a flag in cell
        grid->SetWarningInCell(x, y);

    }

};

void GameScene::GoToGameOverScene(){

    // Show Cells in all grid and go to game over screen
    grid->RevealAllCell();
    sceneManager->gameOverScene->grid = this->grid;
    sceneManager->ChangeScene(EScene::GameOver);

};