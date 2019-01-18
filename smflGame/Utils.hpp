//
//  Utils.hpp
//  smflGame
//
//  Created by Jose Teixeira on 17/01/19.
//  Copyright © 2019 ZeCDev. All rights reserved.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#define NOT_FOUND_EXCEPTION "Could not found the file "

namespace SMFLGame
{
    class Utils {
    public:
        
        /**
         Allocates a texture and load a image from file passed by parameter.
         @param file The name of the file on resourcesPath.
         @return The new allocated texture.
         */
        static sf::Texture * createTexture(std::string file);
        
        /**
         This function evaluates if a shape is outside the window.
         @param shape The shape to be evaluated.
         @param window The window to be evaluated.
         @return true if the shape position it's part of window
         otherwise return false.
         */
        static bool isOutOfBounds(sf::CircleShape shape, sf::RenderWindow *window);
        
        /**
         This function evaluates if a collision between two circles happened.
         @param a The circle to be compared.
         @param b The other circle to be compared.
         @return true if the collision is detected, otherwise return false.
         */
        static bool isCollisionDetected(sf::CircleShape a, sf::CircleShape b);
    };
}

#endif /* Utils_hpp */
