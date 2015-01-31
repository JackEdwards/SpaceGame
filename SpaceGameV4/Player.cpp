#include "Player.h"

sf::Vector2u Player::spriteSize = sf::Vector2u(64, 64);

Player::Player()
{
    texture.loadFromFile(resourcePath() + "ship.png", sf::IntRect(0, 0, 64, 64));
    sprite.setTexture(texture);
    speed = 600.0f;
}

sf::Sprite& Player::getSprite()
{
    return sprite;
}

float& Player::getSpeed()
{
    return speed;
}

sf::Vector2u Player::getSpriteSize()
{
    return spriteSize;
}