#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

class Background
{
public:
    Background();
    sf::Sprite getSprite();
private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif