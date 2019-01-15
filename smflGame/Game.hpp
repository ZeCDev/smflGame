//
//  Game.hpp
//  smflGame
//
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
        
        sf::CircleShape * _circle;
        
        sf::CircleShape * getCircle();
        
        void _startNewGame();
        void _pauseNewGame();
        void _resumeNewGame();
        
        void _startPressed();
        void _beforeDisplay();
        void _afterDisplay();
        
        void _updateObjectsPosition();
    };
}


#endif /* Game_hpp */
