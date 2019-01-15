//
//  Game.cpp
//  smflGame
//
//  Created by Jose Teixeira on 14/01/19.
//  Copyright © 2019 ZeCDev. All rights reserved.
//

#include "Game.hpp"
#include <unistd.h>

namespace SMFLGame
{
    Game::Game(sf::RenderWindow *window, SMFLGame::Player * player)
    :Window(window, player)
    {
    }
    
    Game::~Game()
    {
        //don't delete the window, it should be managed by the main

    }

    
    void Game::display()
    {
        getWindow()->clear();
        
        getWindow()->display();
    }
    
    void Game::startPressed()
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
        
    }
    
    void Game::_pauseNewGame()
    {
        
    }
    
    void Game::_resumeNewGame()
    {
        
    }
}
