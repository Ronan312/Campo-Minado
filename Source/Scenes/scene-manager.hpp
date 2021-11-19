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
    
        MenuScene*      menuScene;
        GameScene*      gameScene;
        GameOverScene*  gameOverScene;
    
        void Initialize();
        void ChangeScene(EScene scene);

        void Update();
        void Render(SDL_Renderer* render);
    
    private:
        SceneBase*      activeScene;

};