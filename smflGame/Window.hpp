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
        
        State getState();
        
        void setState(State state);
        
        virtual void run();
        
    private:
        sf::RenderWindow *_window;
        sf::Font *_font;
        SMFLGame::Player * _player;
        State _state;
        
        virtual void _beforeDisplay() = 0; // must be override
        virtual void _startPressed() = 0;
    };
}


#endif /* Window_hpp */
