//
//  Game.hpp
//  smflGame
//
//  Created by Jose Teixeira on 14/01/19.
//  Copyright © 2019 ZeCDev. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Window.hpp"

namespace SMFLGame
{    
    class Game : public Window {
    public:
        Game(sf::RenderWindow *window, SMFLGame::Player * player);
        virtual ~Game();
        
    private:
        
        void _startNewGame();
        
        void _pauseNewGame();
        
        void _resumeNewGame();
        
        void startPressed();
        
        void display();
    };
}


#endif /* Game_hpp */
