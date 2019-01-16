//
//  Game.cpp
//  smflGame
//
//  Copyright © 2019 ZeCDev. All rights reserved.
//

#include "Game.hpp"
#include <unistd.h>

namespace SMFLGame
{
    Game::Game(sf::RenderWindow *window, SMFLGame::Player * player)
    :Window(window, player), _circle(NULL)
    {
    }
    
    Game::~Game()
    {
    }
    
    sf::CircleShape * Game::_getCircle()
    {
        if(_circle == NULL){
            _circle = new sf::CircleShape(40);
            _circle->setFillColor(sf::Color(255, 0, 0));
            _circle->setPosition(100, 100);
        }
        return _circle;
    }
    
    void Game::_setToBeginPositions()
    {
        _getCircle()->setPosition(100, 100);
    }

    void Game::_beforeDisplay()
    {
        getWindow()->draw(*_getCircle());
    }
    
    void Game::_afterDisplay()
    {
        _updateObjectsPosition();
    }
    
    void Game::_startPressed()
    {
        //if is a new game, return true
        //otherwise return false and pause or start the game
        switch (getState())
        {
            case Idle:
                printf("Start a new game\n");
                setState(Running);
                break;
                
            case Running:
                printf("Game paused\n");
                setState(Stopped);
                break;
            
            case Stopped:
                printf("Resume game\n");
                setState(Running);
                break;
        }
    }
    
    bool Game::_isOutOfBounds(sf::CircleShape shape) {
        sf::Vector2f temp = shape.getPosition();
        int x = temp.x + 1;
        int y = temp.y + 1;
        if (x > getWindow()->getSize().x || x < 0) {
            return true;
        }
        if (y > getWindow()->getSize().y || y < 0) {
            return true;
        }
        return false;
    }
    
    void Game::_updateObjectsPosition()
    {
        if(getState() != Running){
            return;
        }
        
        _getCircle()->setPosition(_getCircle()->getPosition().x + 1, _getCircle()->getPosition().y);
        printf("circle moving x:%f y:%f\n", _getCircle()->getPosition().x, _getCircle()->getPosition().y);
        
        if(_isOutOfBounds(*_getCircle()))
        {
            printf("Is out of bounds\n");
            setState(Idle);
            //to start in begin position when its called again
            _setToBeginPositions();
        }
    }
}
