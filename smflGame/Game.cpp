//
//  Game.cpp
//  smflGame
//
//  Copyright © 2019 ZeCDev. All rights reserved.
//

#include "Game.hpp"
#include <unistd.h>

#define BACKGROUD_FILE "Backgrounds/grass03_0.png"

#define MAX_CIRCLES 50

#define CIRCLE_RADIUS 30
#define WIN_CIRCLE_RADIUS 10

#define CIRCLE_MAIN_POSITION_X 40
#define CIRCLE_MAIN_POSITION_Y 50

#define LOST_MAX_ITERATIONS 2000

#define WIN_CREDITS 5

namespace SMFLGame
{
    Game::Game(sf::RenderWindow *window, SMFLGame::Player * player)
    :Window(window, player), _mainCircle(NULL), _mainCircleDirection(NULL), _winCircle(NULL), _background(NULL), _backgroudTexture(NULL), _iterations(0)
    {
    }
    
    Game::~Game()
    {
        delete _mainCircle;
        delete _mainCircleDirection;
        delete _background;
        delete _backgroudTexture;
    }
    
    sf::Sprite * Game::_getBackground()
    {
        if(this->_background == NULL){
            //The texture should be saved in heap
            this->_backgroudTexture = Utils::createTexture(BACKGROUD_FILE);
            this->_background = new sf::Sprite(*(this->_backgroudTexture));
        }
        return this->_background;
    }
    
    sf::CircleShape * Game::_getMainCircle()
    {
        if(_mainCircle == NULL){
            _mainCircle = new sf::CircleShape(CIRCLE_RADIUS);
            _mainCircle->setFillColor(sf::Color(255, 0, 0));
            
            srand (time(NULL));

            int randX = rand() % (WINDOW_WIDTH - 200);
            int randY = rand() % (WINDOW_HEIGHT - 200);
            _mainCircle->setPosition(randX, randY);
        }
        return _mainCircle;
    }
    
    sf::Vector2f * Game::_getMainCircleDirection()
    {
        if(_mainCircleDirection == NULL){
            _mainCircleDirection = new sf::Vector2f(1, 1);
        }
        return _mainCircleDirection;
    }
    
    sf::CircleShape * Game::_getWinCircle()
    {
        if(_winCircle == NULL){
            _winCircle = new sf::CircleShape(WIN_CIRCLE_RADIUS);
            _winCircle->setFillColor(sf::Color(255, 255, 0));
            _winCircle->setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
        }
        return _winCircle;
    }
    
    void Game::_setToBeginPositions()
    {
        _iterations = 0;
        delete _mainCircleDirection;
        delete _mainCircle;
        
        _mainCircle = NULL;
        _mainCircleDirection = NULL;
    }

    void Game::_beforeDisplay()
    {
        getWindow()->draw(*_getBackground());
        getWindow()->draw(*_getMainCircle());
        getWindow()->draw(*_getWinCircle());
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
    
    void Game::_updateCircles(sf::CircleShape * circle, sf::Vector2f * circleDirection)
    {
        const auto pos = circle->getPosition();
        const auto velocity = 1.1;
        
        sf::Vector2f new_pos(pos.x + circleDirection->x * velocity, pos.y + circleDirection->y * velocity);
        
        if (new_pos.x - CIRCLE_RADIUS < 0) {
            circleDirection->x *= -velocity;
            new_pos.x = 0 + CIRCLE_RADIUS;
        } else if (new_pos.x + CIRCLE_RADIUS >= WINDOW_WIDTH) {
            circleDirection->x *= -velocity;
            new_pos.x = WINDOW_WIDTH - CIRCLE_RADIUS;
        } else if (new_pos.y - CIRCLE_RADIUS < 0) {
            circleDirection->y *= -velocity;
            new_pos.y = 0 + CIRCLE_RADIUS;
        } else if (new_pos.y + CIRCLE_RADIUS >= WINDOW_HEIGHT) {
            circleDirection->y *= -velocity;
            new_pos.y = WINDOW_HEIGHT - CIRCLE_RADIUS;
        }
        
        circle->setPosition(new_pos);
    }
    
    void Game::_updateObjectsPosition()
    {
        if(getState() != Running){
            return;
        }
        
        _iterations++;
        
        _updateCircles(_getMainCircle(), _getMainCircleDirection());
        
        if(Utils::isCollisionDetected(*_getMainCircle(), *_getWinCircle())){
            printf("You win. %d credits added!\n", WIN_CREDITS);
            getPlayer()->addCredits(WIN_CREDITS);
            setState(Idle);
            //to start in begin position when its called again
            _setToBeginPositions();
        }
        else if(Utils::isOutOfBounds(*_getMainCircle(), getWindow()) || _iterations > LOST_MAX_ITERATIONS)
        {
            printf("You lost. Is out of bounds or max speed is reached\n");
            setState(Idle);
            //to start in begin position when its called again
            _setToBeginPositions();
        }
    }
}
