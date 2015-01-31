#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

class Player
{
public:
    Player();
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