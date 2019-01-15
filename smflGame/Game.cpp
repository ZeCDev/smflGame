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
    
    sf::CircleShape * Game::getCircle()
    {
        if(_circle == NULL){
            _circle = new sf::CircleShape(40);
            _circle->setFillColor(sf::Color(255, 0, 0));
            _circle->setPosition(100, 100);
        }
        return _circle;
    }

    void Game::_beforeDisplay()
    {
        getWindow()->draw(*getCircle());
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
                _startNewGame();
                setState(Running);
                break;
                
            case Running:
                _pauseNewGame();
                setState(Stopped);
                break;
            
            case Stopped:
                _resumeNewGame();
                setState(Running);
                break;
        }
    }
    
    void Game::_startNewGame()
    {
        printf("Start a new game\n");
    }
    
    void Game::_pauseNewGame()
    {
        printf("Game paused\n");
    }
    
    void Game::_resumeNewGame()
    {
        printf("Resume game\n");
    }
    
    void Game::_updateObjectsPosition()
    {
        if(getState() != Running){
            return;
        }
        getCircle()->setPosition(getCircle()->getPosition().x + 0.1, getCircle()->getPosition().y);
    }
}
