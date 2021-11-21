#include "Scenes/scene-manager.hpp"
#include "Scenes/Game/menu-scene.hpp"
#include "Scenes/Game/game-scene.hpp"
#include "Scenes/Game/game-over-scene.hpp"

void SceneManager::Initialize(){

    // Initialize Scenes Pointers
    menuScene     = new MenuScene();
    gameScene     = new GameScene();
    gameOverScene = new GameOverScene();

};

void SceneManager::ChangeScene(EScene scene) {

    // Set Scene Active by Enum
    switch(scene) {

        case EScene::MainMenu: activeScene = menuScene;     break;
        case EScene::Game:     activeScene = gameScene;     break;
        case EScene::GameOver: activeScene = gameOverScene; break;
      
        default: activeScene = menuScene; break;

    };

};

void SceneManager::Update(){

    // If we have a active scene call update function
    if (activeScene) activeScene->Update();

};

void SceneManager::Render(SDL_Renderer* render){

    // If we have a active scene call render function
    if (activeScene) activeScene->Render(render);

};
