#include "Scenes/scene-manager.hpp"
#include "Scenes/Game/menu-scene.hpp"
#include "Scenes/Game/game-scene.hpp"
#include "Scenes/Game/game-over-scene.hpp"

void SceneManager::Initialize(){

    menuScene     = new MenuScene();
    gameScene     = new GameScene();
    gameOverScene = new GameOverScene();

};

void SceneManager::ChangeScene(EScene scene) {

    switch(scene) {

        case EScene::MainMenu: activeScene = menuScene;     break;
        case EScene::Game:     activeScene = gameScene;     break;
        case EScene::GameOver: activeScene = gameOverScene; break;
      
        default: activeScene = menuScene; break;

    };

};

void SceneManager::Update(){

    if (activeScene) activeScene->Update();

};

void SceneManager::Render(SDL_Renderer* render){

    if (activeScene) activeScene->Render(render);

};
