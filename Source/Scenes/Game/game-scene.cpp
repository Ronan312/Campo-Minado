#include "Scenes/Game/game-scene.hpp"
#include <chrono>
#include "Core/random.hpp"
#include "Core/application.hpp"
#include "Scenes/scene-manager.hpp"
#include "Game/game-controller.hpp"
#include "Game/grid.hpp"
#include "Game/cell.hpp"
#include "Inputs/mouse.hpp"


GameScene::GameScene(){

    mouse        = Application::mouse;
    sceneManager = Application::sceneManager;

    controller = new GameController();

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

};

void GameScene::Render(SDL_Renderer* render) {

    SDL_SetRenderDrawColor(render, 88, 88, 88, 255);    // Draw a new color inside render

    grid->Render(render);

};

void GameScene::MouseClick(){

    if (mouse->pressed[0] && !mouse->IsLocked()){

        SDL_Point* mousePos = mouse->GetMousePosition();
        int x = mousePos->x / 16;
        int y = mousePos->y / 16;

        if ((x < 0 || x >= grid->GetWidth()) || (y < 0 || y >= grid->GetHeight())) return;

        Cell* cell = grid->GetCell(x, y);
        if (!cell->wasClicked) cell->wasClicked = true;

        if (cell->flag == ECellFlag::Bomb){

            mouse->SetLocked(true);
            std::cout << "Game Over" << std::endl;

        }

        if (cell->flag == ECellFlag::None) grid->RevealBlankCell(x, y);

    }

};
void GameScene::MousePutFlag(){



};
