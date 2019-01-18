//
//  Window.hpp
//  smflGame
//
//  Copyright © 2019 ZeCDev. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Utils.hpp"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

namespace SMFLGame
{
    enum State {Idle, Running, Stopped};

    class Window {
    public:
        Window(sf::RenderWindow *window, SMFLGame::Player * player);
        virtual ~Window();
        
        /**
         This function returns a player that it was received
         on the constructor
         @return The player.
         */
        SMFLGame::Player *getPlayer();
        
        /**
         This function returns the window of the game
         @return The _window variable
         */
        sf::RenderWindow *getWindow();
        
        /**
         If the _font is NULL, this function allocates and initializes,
         _font, otherwise return the font existent in _font.
         @return The font used in texts.
         */
        sf::Font *getFont();
        
        /**
         This function returns the state of that window.
         Could be Idle, Running or Stopped.
         @return The state.
         */
        State getState();
        
        /**
         This function changes the state of that window.
         @param state The state that this window will be change.
         */
        void setState(State state);
        
        /**
        This function starts the activity in the window.
        */
        void run();
        
    private:
        sf::RenderWindow *_window;
        sf::Font *_font;
        SMFLGame::Player * _player;
        State _state;
        
        /**
         This function should be implemented on the derived class and
         will be called before the window changes the display.
         */
        virtual void _beforeDisplay() = 0; // must be override
        
        /**
         This function should be implemented on the derived class and
         will be called after the window changes the display.
         */
        virtual void _afterDisplay() = 0;
        
        /**
         This function should be implemented on the derived class and
         will be called when the player presses the start button.
         */
        virtual void _startPressed() = 0;
        
        /**
         This function can be implemented on the derived class and
         will be called when the mouse is pressed.
         @param vec The position of the mouse on it's pressed.
         */
        virtual void _mousePressed(sf::Vector2f vec);
    };
}


#endif /* Window_hpp */
