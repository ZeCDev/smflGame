//
//  Utils.cpp
//  smflGame
//
//  Copyright © 2019 ZeCDev. All rights reserved.
//

#include "Utils.hpp"
#include "ResourcePath.hpp"
#include <math.h>
#include <cmath>

namespace SMFLGame
{
    sf::Texture * Utils::createTexture(std::string file)
    {
        sf::Texture * texture = new sf::Texture();
        if (!texture->loadFromFile(resourcePath() + file)) {
            throw std::runtime_error(std::string(NOT_FOUND_EXCEPTION) + file);
        }
        return texture;
    }
    
    bool Utils::isOutOfBounds(sf::CircleShape shape, sf::RenderWindow *window) {
        if (shape.getPosition().x > window->getSize().x || shape.getPosition().x < 0) {
            return true;
        }
        if (shape.getPosition().y > window->getSize().y || shape.getPosition().y < 0) {
            return true;
        }
        return false;
    }
    
    bool Utils::isCollisionDetected(sf::CircleShape a, sf::CircleShape b) {
        int x1 = a.getPosition().x;
        int x2 = b.getPosition().x;
        int y1 = a.getPosition().y;
        int y2 = b.getPosition().y;
        
        if (sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1)) < (a.getRadius() + b.getRadius())){
            return true;
        }
        else {
            return false;
        }
    }
}
