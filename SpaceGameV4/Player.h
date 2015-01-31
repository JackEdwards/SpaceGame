#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <vector>

class Player
{
public:
    Player();
    sf::Sprite& getSprite();
    float& getSpeed();
    static sf::Vector2u getSpriteSize();
    std::vector<sf::Texture>& getShipTextures();
    int& getCurrentFrame();
    
private:
    
    std::vector<sf::Texture> shipTextures;
    int currentFrame;
    sf::Sprite sprite;
    float speed;
    static sf::Vector2u spriteSize;
};

#endif