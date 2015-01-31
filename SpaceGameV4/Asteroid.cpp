#include "Asteroid.h"

sf::Vector2u Asteroid::spriteSize = sf::Vector2u(64, 64);

Asteroid::Asteroid()
{
    texture.loadFromFile(resourcePath() + "asteroid-med.png");
    sprite.setTexture(texture);
    speed = 500.0f;
}

sf::Sprite& Asteroid::getSprite()
{
    return sprite;
}

float& Asteroid::getSpeed()
{
    return speed;
}

sf::Vector2u Asteroid::getSpriteSize()
{
    return spriteSize;
}