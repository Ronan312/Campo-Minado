#include "Core/application.hpp"
#include <chrono>
#include <cstdint>
#include "Vendors/SDL/SDL.h"
#include "Vendors/SDL/SDL_image.h"
#include "Vendors/SDL/SDL_mixer.h"
#include "Core/random.hpp"
#include "Game/cell.hpp"
#include "Scenes/Game/game-scene.hpp"

ResourceMap   Application::resources;
Mouse*        Application::mouse = new Mouse();
SceneManager* Application::sceneManager = new SceneManager();

Application::Application(){};
Application::~Application(){};

void Application::Initialize(){

    InitializeFramework();

    InitializeWindow();

    LoadAssets(this->renderer);

    sceneManager->Initialize();
    sceneManager->ChangeScene(EScene::Game);
    sceneManager->gameScene->InitializeBoard();

    // Initialize Game Loop
    this->isRunning = true;

};

void Application::Shutdown(){

    // Destroy Instances
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);

    // Shutdown SDL Modules
    SDL_Quit();

};

void Application::Run(){

    // Do Game Loop
    while(isRunning){

        HandleEvents();
        Update();
        Render();

    };

};

void Application::HandleEvents(){

    // Loop throught framework events
    while(SDL_PollEvent(this->events)){
        
        // On Close button stop application looping
        if (this->events->type == SDL_QUIT) this->isRunning = false;

        // Call mouse events
        mouse->HandleEvents(this->events);

    };

};

void Application::Update(){

    sceneManager->Update();

};

void Application::Render(){

    SDL_RenderClear(this->renderer);                            // Clear content in render
    // SDL_SetRenderDrawColor(this->renderer, 88, 88, 88, 255);    // Draw a new color inside render

    sceneManager->Render(this->renderer);

    SDL_RenderPresent(this->renderer);                          // Show render in screen

};

void Application::InitializeFramework(){

    // Initialize SDL Modules
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    Mix_Init(MIX_INIT_MP3);

};
void Application::InitializeWindow(){

    // Create a Application Window
    this->window = SDL_CreateWindow("Manifesto - Campo Minado",                         // Game title
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,     // Centralize Window on middle screen
                                    1280, 720, NULL);                                   // Screen Size and Extra Flags

    // Create a renderer surface
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    
    // Create a SDL Events
    this->events = new SDL_Event;

};

void Application::LoadAssets(SDL_Renderer* render){

    // Load Game Bricks
    SDL_Surface* surfBrick = IMG_Load("./Assets/bricks.png");
    SDL_Texture* textBrick = SDL_CreateTextureFromSurface(render, surfBrick);
    Application::resources["Bricks"] = textBrick;

};

void Application::MouseClick(){

    // if (mouse->pressed[0] && !mouse->locked){

    //     int x = mouse->position.x / 16;
    //     int y = mouse->position.y / 16;

    //     if ((x < 0 || x >= grid->GetWidth()) || (y < 0 || y >= grid->GetHeight())) return;

    //     Cell* cell = grid->GetCell(x, y);
    //     if (!cell->wasClicked) cell->wasClicked = true;

    //     if (cell->flag == ECellFlag::Bomb){

    //         mouse->locked = true;
    //         std::cout << "Game Over" << std::endl;

    //     }

    //     if (cell->flag == ECellFlag::None) grid->RevealBlankCell(x, y);

    // }

};