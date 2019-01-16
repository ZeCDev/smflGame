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
        
        /**
         If the _circle is NULL, this function allocate and initialize,
         _circle variable, otherwise return the CircleShape existent in
         _circle variable.
         @return The circle.
         */
        sf::CircleShape * _getCircle();
        
        /**
         @See superclass
         */
        void _startPressed();
        
        /**
         @See superclass
         */
        void _beforeDisplay();
        
        /**
         @See superclass
         */
        void _afterDisplay();
        
        void _setToBeginPositions();
        
        /**
         This function evaluate if a shape is outside the window.
         @param shape The shape to be evaluated.
         @return true if the shape position it's part of window
         otherwise return false.
         */
        bool _isOutOfBounds(sf::CircleShape shape);
        
        /**
         This function it's used to update the position of all
         the elements of that window.
         */
        void _updateObjectsPosition();
    };
}


#endif /* Game_hpp */
