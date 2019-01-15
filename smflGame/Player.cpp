//
//  Player.cpp
//  smflGame
//
//  Copyright © 2019 ZeCDev. All rights reserved.
//

#include "Player.hpp"
#define CREDITS_REQUIRED_TO_PLAY 1

namespace SMFLGame
{
    Player::Player()
    :_creditsInCounter(0), _creditsOutCounter(0), _playedCounter(0), _creditsAvailableCounter(0)
    {
    }
    
    Player::~Player()
    {
    }
    
    int Player::getCreditsInCounter()
    {
        return _creditsInCounter;
    }
    
    int Player::getCreditsOutCounter()
    {
        return _creditsOutCounter;
    }
    
    int Player::getCreditsAvailableCounter()
    {
        return _creditsAvailableCounter;
    }
    
    int Player::getPlayedCounter()
    {
        return _playedCounter;
    }
    
    void Player::addCredits(int num)
    {
        _creditsInCounter = _creditsInCounter + num;
        _creditsAvailableCounter = _creditsAvailableCounter + num;
    }
    
    void Player::removeCredits(int num)
    {
        if(num > _creditsAvailableCounter){
            //No credits available
            return;
        }
        _creditsOutCounter = _creditsOutCounter + num;
        _creditsAvailableCounter = _creditsAvailableCounter - num;
    }
    
    int Player::removeAllCredits()
    {
        int valueCopy = _creditsOutCounter;
        _creditsOutCounter = 0;
        
        return valueCopy;
    }
    
    void Player::addPlayed(int num)
    {
        if(this->_creditsAvailableCounter < CREDITS_REQUIRED_TO_PLAY * num){
            return;
        }
        
        _creditsAvailableCounter = _creditsAvailableCounter - CREDITS_REQUIRED_TO_PLAY * num;
        _playedCounter = _playedCounter + num;
    }
}
