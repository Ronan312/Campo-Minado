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
    this->window = SDL_CreateWindow("Manifesto - Campo Minado", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, NULL);

    // Create a renderer surface
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

    // Create a SDL Events
    this->events = new SDL_Event;

};

void Application::Shutdown(){

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

void Application::Render(){};
