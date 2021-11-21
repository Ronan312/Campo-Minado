#pragma once
#include "Vendors/SDL/SDL.h"
#include "Definitions/scene-index.hpp"
#include "Scenes/scene-base.hpp"

// Forward Declaration
class MenuScene;
class GameScene;
class GameOverScene;

class SceneManager {

    public:
    
        MenuScene*      menuScene;      // Scene Instances
        GameScene*      gameScene;      // Scene Instances
        GameOverScene*  gameOverScene;  // Scene Instances
    
        void Initialize();
        void ChangeScene(EScene scene); // Change Active Scene

        void Update();
        void Render(SDL_Renderer* render);
    
    private:
        SceneBase*      activeScene;

};