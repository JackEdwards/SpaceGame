#include "Player.h"

sf::Vector2u Player::spriteSize = sf::Vector2u(64, 64);

Player::Player() : shipTextures(3)
{
    for (int i = 0; i < shipTextures.size(); ++i)
        shipTextures[i].loadFromFile(resourcePath() + "ship.png", sf::IntRect(i * 64, 0, 64, 64));
    
    sprite.setTexture(shipTextures[0]);
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

std::vector<sf::Texture>& Player::getShipTextures()
{
    return shipTextures;
}