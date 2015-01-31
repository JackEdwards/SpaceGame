#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

class Asteroid
{
public:
    Asteroid();
    sf::Sprite& getSprite();
    float& getSpeed();
    static sf::Vector2u getSpriteSize();
private:
    sf::Texture texture;
    sf::Sprite sprite;
    float speed;
    static sf::Vector2u spriteSize;
};

#endif