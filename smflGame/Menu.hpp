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
         If the _background is NULL, this function allocates and initializes,
         _backgroundTexture and _background variable, otherwise
         return the sprite existent in _background variable.
         @return The sprite used in background.
         */
        sf::Sprite *_getBackground();
        
        /**
         If the _startButton is NULL, this function allocates and initializes,
         _startButtonTexture and _startButton variable, otherwise
         return the sprite existent in _startButton variable.
         @return The sprite used in startButton.
         */
        sf::Sprite *_getStartButton();
        
        /**
         If the _creditsInButton is NULL, this function allocates and initializes,
         _creditsInButtonTexture and _creditsInButton variable, otherwise
         return the sprite existent in _creditsInButton variable.
         @return The sprite used in creditsInButton.
         */
        sf::Sprite *_getCreditsInButton();
        
        /**
         If the _creditsOutButton is NULL, this function allocates and initializes,
         _creditsOutButtonTexture and _creditsOutButton variable, otherwise
         return the sprite existent in creditsOutButton variable.
         @return The sprite used in creditsInButton.
         */
        sf::Sprite *_getCreditsOutButton();
        
        /**
         This function draws all menu sprites on the window.
         */
        void _drawSprites();
        
        /**
         This function draws all the text counters on the window.
         */
        void _drawCounters();
        
        /**
         If the _game is NULL, this function allocates and initializes,
         _game variable, otherwise return the Game existent in
         game variable.
         @return The game window.
         */
        SMFLGame::Game *_getGame();
        
        /**
         This function evaluates if a sprite is clicked.
         @param sprite The sprite to be evaluated.
         @param vec The point to be compared.
         @return true if the sprite position it's part of vec
         otherwise return false.
         */
        bool _isClicked(sf::Sprite* sprite, sf::Vector2f vec);
        
        /**
         @See superclass
         */
        void _beforeDisplay();
        
        /**
         @See superclass
         */
        void _afterDisplay();
        
        /**
         @See superclass
         */
        void _startPressed();
        
        /**
         @See superclass
         */
        void _mousePressed(sf::Vector2f vec);
    };
}

#endif /* Menu_hpp */
