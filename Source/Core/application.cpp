#include "Core/application.hpp"
#include "Vendors/SDL/SDL.h"
#include "Vendors/SDL/SDL_image.h"
#include "Vendors/SDL/SDL_mixer.h"

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



    SDL_RenderPresent(this->renderer);                          // Show render in screen

};
