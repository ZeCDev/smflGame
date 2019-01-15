//
//  Menu.cpp
//  smflGame
//
//  Created by Jose Teixeira on 13/01/19.
//  Copyright © 2019 ZeCDev. All rights reserved.
//

#include "Menu.hpp"
#include "ResourcePath.hpp"

#define BACKGROUD_FILE "backgroundMenu.png"

#define START_BUTTON_FILE "StartActive.png"
#define CREDITS_IN_BUTTON_FILE "CreditsInActive.png"
#define CREDITS_OUT_BUTTON_FILE "CreditsOutActive.png"

namespace SMFLGame
{
    Menu::Menu(sf::RenderWindow *window, SMFLGame::Player * player)
    :Window(window, player), _game(NULL), _backgroudTexture(NULL), _background(NULL), _startButtonTexture(NULL), _startButton(NULL), _creditsInButtonTexture(NULL), _creditsInButton(NULL), _creditsOutButtonTexture(NULL), _creditsOutButton(NULL)
    {
    }
    
    Menu::~Menu()
    {        
        delete _background;
        delete _backgroudTexture;
        
        delete _startButton;
        delete _startButtonTexture;
    }
    
    sf::Texture * Menu::_createTexture(std::string file)
    {
        sf::Texture * texture = new sf::Texture();
        if (!texture->loadFromFile(resourcePath() + file)) {
            throw std::runtime_error(std::string(NOT_FOUND_EXCEPTION) + file);
        }
        return texture;
    }
    
    sf::Sprite* Menu::_getBackground()
    {
        if(this->_background == NULL){
            //The texture should be saved in heap
            this->_backgroudTexture = _createTexture(BACKGROUD_FILE);
            this->_background = new sf::Sprite(*(this->_backgroudTexture));
        }
        return this->_background;
    }
    
    sf::Sprite* Menu::_getStartButton()
    {
        if(this->_startButton == NULL){
            //The texture should be saved in heap
            this->_startButtonTexture = _createTexture(START_BUTTON_FILE);
            this->_startButton = new sf::Sprite(*(this->_startButtonTexture));
            this->_startButton->setPosition(getWindow()->getSize().x/2 - 300, getWindow()->sf::Window::getSize().y/2 - 100);
            this->_startButton->setScale(0.4f,0.4f);
        }
        return this->_startButton;
    }
    
    sf::Sprite* Menu::_getCreditsInButton()
    {
        if(this->_creditsInButton == NULL){
            //The texture should be saved in heap
            this->_creditsInButtonTexture = _createTexture(CREDITS_IN_BUTTON_FILE);
            this->_creditsInButton = new sf::Sprite(*(this->_creditsInButtonTexture));
            this->_creditsInButton->setPosition(getWindow()->getSize().x/2 - 100, getWindow()->sf::Window::getSize().y/2 - 100);
            this->_creditsInButton->setScale(0.4f,0.4f);
        }
        return this->_creditsInButton;
    }
    
    sf::Sprite* Menu::_getCreditsOutButton()
    {
        if(this->_creditsOutButton == NULL){
            //The texture should be saved in heap
            this->_creditsOutButtonTexture = _createTexture(CREDITS_OUT_BUTTON_FILE);
            this->_creditsOutButton = new sf::Sprite(*(this->_creditsOutButtonTexture));
            this->_creditsOutButton->setPosition(getWindow()->getSize().x/2 + 100, getWindow()->sf::Window::getSize().y/2 - 100);
            this->_creditsOutButton->setScale(0.4f,0.4f);
        }
        return this->_creditsOutButton;
    }
    
    SMFLGame::Game* Menu::_getGame()
    {
        if(this->_game == NULL){
            this->_game = new SMFLGame::Game(getWindow(), getPlayer());
        }
        return this->_game;
    }
    
    void Menu::_drawSprites()
    {
        // Draw the background sprite
        getWindow()->draw(*_getBackground());
        getWindow()->draw(*_getStartButton());
        getWindow()->draw(*_getCreditsInButton());
        getWindow()->draw(*_getCreditsOutButton());
    }
    
    void Menu::_drawCounters()
    {
        sf::Text creditsIn("Credits in : " + std::to_string(getPlayer()->getCreditsInCounter()), *getFont(), 20);
        creditsIn.setFillColor(sf::Color::Black);
        creditsIn.setPosition(getWindow()->getSize().x - 150, getWindow()->getSize().y - 740);
        
        sf::Text creditsOut("Credits out : " + std::to_string(getPlayer()->getCreditsOutCounter()), *getFont(), 20);
        creditsOut.setFillColor(sf::Color::Black);
        creditsOut.setPosition(getWindow()->getSize().x - 150, getWindow()->getSize().y - 700);
        
        sf::Text played("Played: " + std::to_string(getPlayer()->getPlayedCounter()), *getFont(), 20);
        played.setFillColor(sf::Color::Black);
        played.setPosition(getWindow()->getSize().x - 150, getWindow()->getSize().y - 660);

        getWindow()->draw(creditsIn);
        getWindow()->draw(creditsOut);
        getWindow()->draw(played);
    }
    
    void Menu::display()
    {
        // Clear screen
        getWindow()->clear();
        
        _drawSprites();
        _drawCounters();
        
        // Update the window
        getWindow()->display();
    }
    
    void Menu::startPressed()
    {
        _getGame()->run();
    }
}
