//
//  Menu.hpp
//  smflGame
//
//  Copyright © 2019 ZeCDev. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "Game.hpp"

namespace SMFLGame
{
    class Menu : public Window {
    public:
        Menu(sf::RenderWindow *window, SMFLGame::Player * player);
        virtual ~Menu();
        
    private:        
        sf::Texture *_backgroudTexture;
        sf::Sprite *_background;
        
        sf::Texture *_startButtonTexture;
        sf::Sprite *_startButton;
        
        sf::Texture *_creditsInButtonTexture;
        sf::Sprite *_creditsInButton;
        
        sf::Texture *_creditsOutButtonTexture;
        sf::Sprite *_creditsOutButton;
        
        SMFLGame::Game * _game;
        
        /**
         Allocate a texture and load a image from file passed by parameter.
         
         @param file The name of the file on resourcesPath.
         @return The new allocated texture.
         */
        sf::Texture * _createTexture(std::string file);
        
        /**
         If the _background is NULL, this function allocate and initialize,
         _backgroundTexture and _background variable, otherwise
         return the sprite existent in _background variable.
         
         @return The sprite used in background.
         */
        sf::Sprite *_getBackground();
        
        sf::Sprite *_getStartButton();
        
        sf::Sprite *_getCreditsInButton();
        
        sf::Sprite *_getCreditsOutButton();
        
        void _drawSprites();
        
        void _drawCounters();
        
        SMFLGame::Game *_getGame();
        
        void _beforeDisplay();
        void _afterDisplay();
        void _startPressed();
    };
}

#endif /* Menu_hpp */
