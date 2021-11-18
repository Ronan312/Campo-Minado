#include "Core/application.hpp"
#include <chrono>
#include <cstdint>
#include "Vendors/SDL/SDL.h"
#include "Vendors/SDL/SDL_image.h"
#include "Vendors/SDL/SDL_mixer.h"
#include "Core/random.hpp"

std::unordered_map<std::string, SDL_Texture*> Application::resources;

Application::Application(){};
Application::~Application(){};

void Application::Initialize(){

    // Initialize SDL Modules
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    Mix_Init(MIX_INIT_MP3);

    // Create a Application Window
    this->window = SDL_CreateWindow("Manifesto - Campo Minado",                         // Game title
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,     // Centralize Window on middle screen
                                    1280, 720, NULL);                                   // Screen Size and Extra Flags

    // Create a renderer surface
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    
    // Create a SDL Events
    this->events = new SDL_Event;

    // Load Assets
    Application::LoadAssets(this->renderer);

    // Initialize Game Loop
    this->isRunning = true;

    // Set Seed for Randomize tiles
    auto now = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    uint_fast32_t seed = static_cast<uint_fast32_t>(now);
    Random::Seed(seed);

    // Initialize Grid
    grid = new Grid();
    grid->InitializeBoard(78, 43, 200);

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
    while(this->isRunning){

        this->HandleEvents();
        this->Update();
        this->Render();

    };

};

void Application::HandleEvents(){

    // Loop throught framework events
    while(SDL_PollEvent(this->events)){
        
        // On Close button stop application looping
        if (this->events->type == SDL_QUIT) this->isRunning = false;

    };

};

void Application::Update(){};

void Application::Render(){

    SDL_RenderClear(this->renderer);                            // Clear content in render
    SDL_SetRenderDrawColor(this->renderer, 88, 88, 88, 255);    // Draw a new color inside render

    grid->Render(this->renderer);

    SDL_RenderPresent(this->renderer);                          // Show render in screen

};

void Application::LoadAssets(SDL_Renderer* render){

    // Load Game Bricks
    SDL_Surface* surfBrick = IMG_Load("./Assets/bricks.png");
    SDL_Texture* textBrick = SDL_CreateTextureFromSurface(render, surfBrick);
    Application::resources["Bricks"] = textBrick;

};