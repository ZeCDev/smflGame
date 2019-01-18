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
        
        sf::Texture *_backgroudTexture;
        sf::Sprite *_background;
        
        sf::CircleShape * _mainCircle;
        sf::Vector2f * _mainCircleDirection;
        
        sf::CircleShape * _winCircle;
        
        int _iterations;
        
        /**
         If the _background is NULL, this function allocates and initializes,
         _backgroundTexture and _background variable, otherwise
         return the sprite existent in _background variable.
         @return The sprite used in background.
         */
        sf::Sprite *_getBackground();
        
        /**
         If the _mainCircle is NULL, this function allocates and initializes,
         _mainCircle variable, otherwise return the CircleShape existent in
         _mainCircle variable.
         @return The circle.
         */
        sf::CircleShape * _getMainCircle();
        
        /**
         If the _mainCircleDirection is NULL, this function allocates and initializes,
         _mainCircleDirection variable, otherwise return the Vector2f existent in
         _mainCircleDirection variable.
         @return The circle.
         */
        sf::Vector2f * _getMainCircleDirection();
        
        /**
         If the _winCircle is NULL, this function allocates and initializes,
         _winCircle variable, otherwise return the CircleShape existent in
         _winCircle variable.
         @return The circle.
         */
        sf::CircleShape * _getWinCircle();
        
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
        
        /**
         This function puts all objects in the initial position.
         */
        void _setToBeginPositions();
        
        /**
         This function it is used to update the position of all
         elements of that window.
         */
        void _updateObjectsPosition();
        
        /**
         This function updates the velocity and position of the circle.
         @param circle The circle to be updated.
         @param circleDirection The direction of that circle.
         */
        void _updateCircles(sf::CircleShape * circle, sf::Vector2f * circleDirection);
    };
}


#endif /* Game_hpp */
