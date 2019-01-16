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

#define NOT_FOUND_EXCEPTION "Could not found the file "

namespace SMFLGame
{
    enum State {Idle, Running, Stopped};

    class Window {
    public:
        Window(sf::RenderWindow *window, SMFLGame::Player * player);
        virtual ~Window();
        
        /**
         This function return a player that it was received
         on the constructor
         @return The player.
         */
        SMFLGame::Player *getPlayer();
        
        /**
         Return the window of the game
         @return The _window variable
         */
        sf::RenderWindow *getWindow();
        
        /**
         If the _font is NULL, this function allocate and initialize,
         _font, otherwise return the font existent in _font.
         @return The font used in texts.
         */
        sf::Font *getFont();
        
        /**
         This function return the state of that window.
         Could be Idle, Running or Stopped.
         @return The state.
         */
        State getState();
        
        /**
         This function change the state of that window.
         @param state The state that this window will be change.
         */
        void setState(State state);
        
        /**
        This function start the activity of a new window.
        */
        void run();
        
        void creditsInPressed();
        
        void creditsOutPressed();
        
    private:
        sf::RenderWindow *_window;
        sf::Font *_font;
        SMFLGame::Player * _player;
        State _state;
        
        /**
         This function should be implemented on the derived class and
         will be called before the window change the display.
         */
        virtual void _beforeDisplay() = 0; // must be override
        
        /**
         This function should be implemented on the derived class and
         will be called after the window change the display.
         */
        virtual void _afterDisplay() = 0;
        
        /**
         This function should be implemented on the derived class and
         will be called when the player press the start button.
         */
        virtual void _startPressed() = 0;
        
        virtual void _mousePressed(sf::Vector2f vec);
    };
}


#endif /* Window_hpp */
