#include "Asteroid.h"

sf::Vector2u Asteroid::spriteSize = sf::Vector2u(64, 64);
float Asteroid::speed = 300.0f;

Asteroid::Asteroid()
{
    texture.loadFromFile(resourcePath() + "asteroid-med.png");
    sprite.setTexture(texture);
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