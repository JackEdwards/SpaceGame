#include "Background.h"

Background::Background()
{
    texture.loadFromFile(resourcePath() + "background.png");
    sprite.setTexture(texture);
}

sf::Sprite Background::getSprite()
{
    return sprite;
}