//
//  Window.cpp
//  smflGame
//
//  Copyright © 2019 ZeCDev. All rights reserved.
//

#include "Window.hpp"
#include "ResourcePath.hpp"
#include <signal.h>

#define FONT_FILE "sansation.ttf"

namespace SMFLGame
{
    Window::Window(sf::RenderWindow *window, SMFLGame::Player * player)
    :_window(window), _player(player), _font(NULL), _state(Idle)
    {
    }
    
    Window::~Window()
    {
        //don't delete the window and player,
        //it should be managed by the main
    }
    
    SMFLGame::Player *Window::getPlayer()
    {
        return this->_player;
    }
    
    sf::RenderWindow *Window::getWindow()
    {
        return this->_window;
    }
    
    sf::Font* Window::getFont()
    {
        if(this->_font == NULL){
            // Create a graphical text to display
            this->_font = new sf::Font();
            if (!this->_font->loadFromFile(resourcePath() + FONT_FILE)) {
                throw std::runtime_error(std::string(NOT_FOUND_EXCEPTION) + FONT_FILE);
            }
        }
        return this->_font;
    }
    
    State Window::getState()
    {
        return this->_state;
    }
    
    void Window::setState(State state)
    {
        this->_state = state;
    }
    
    void Window::_mousePressed(sf::Vector2f vec)
    {
        //empty
    }
    
    void Window::creditsInPressed()
    {
        getPlayer()->addCredits(1);
    }
    
    void Window::creditsOutPressed()
    {
        getPlayer()->removeCredits(1);
    }
    
    void Window::run()
    {
        setState(Running);
        
        while(getState() != Idle)
        {
            // Process events
            sf::Event event;
            
            if (getWindow()->pollEvent(event))
            {
                // Close window: exit
                if (event.type == sf::Event::Closed) {
                    setState(Idle);
                    getWindow()->close();
                    std::exit(EXIT_SUCCESS);
                    return;
                }
                
                // Escape pressed: exit
                if (event.type == sf::Event::KeyPressed) {
                    
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Escape:
                            getWindow()->close();
                            break;
                            
                        case sf::Keyboard::S:
                            printf("Start pressed\n");
                            _startPressed();
                            break;
                            
                        case sf::Keyboard::I:
                            printf("Credits in pressed\n");
                            creditsInPressed();
                            break;
                            
                        case sf::Keyboard::O:
                            printf("Credits out pressed\n");
                            creditsOutPressed();
                            break;
                            
                        default:
                            break;
                    }
                }
                
                else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    while(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        //ignore repeated events
                    }
                    
                    // get the current mouse position in the window
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(*getWindow());
                    // convert it to world coordinates
                    sf::Vector2f worldPos = getWindow()->mapPixelToCoords(pixelPos);
                    
                    _mousePressed(worldPos);
                }
            }
            
            // Clear screen
            getWindow()->clear();
            
            this->_beforeDisplay();
            
            // Update the window
            getWindow()->display();
            
            this->_afterDisplay();
        }
    }
}
