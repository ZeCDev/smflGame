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
    :Window(window, player)
    {
    }
    
    Game::~Game()
    {
    }

    void Game::_beforeDisplay()
    {        
        sf::CircleShape circleRed(80);
        sf::CircleShape circleGreen(80);
        sf::CircleShape circleBlue(80);
        
        circleRed.setFillColor(sf::Color(255, 0, 0));
        circleGreen.setFillColor(sf::Color(0, 255, 0));
        circleBlue.setFillColor(sf::Color(0, 0, 255));
        
        circleRed.setPosition(100, 100);
        
        float xGreen = 200;
        float yGreen = 200;
        
        float xBlue = 300;
        float yBlue = 300;
        
        circleGreen.setPosition(xGreen, yGreen);
        
        circleBlue.setPosition(xBlue, yBlue);
        
        getWindow()->draw(circleRed);
        getWindow()->draw(circleGreen);
        getWindow()->draw(circleBlue);
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
}
