#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <vector>
#include "Player.h"
#include "Asteroid.h"
#include "Background.h"

class Game
{
public:
    Game();
    void run();
private:
    void update();
    void render();
    void handleEvents();
    void handleInput(float &deltaTime);
    void moveAsteroids(float &deltaTime);
    void handleCollision();
    bool asteroidHasPassed(Asteroid &asteroid);
    bool playerCanMoveLeft();
    bool playerCanMoveRight();
    void startGame();
    
    enum GameState
    {
        StartScreen,
        GameScreen,
        DeathScreen
    };
    
    static int windowWidth;
    static int windowHeight;
    sf::RenderWindow window;
    GameState gameState;
    sf::Clock clock;
    sf::Font font;
    sf::Text startText;
    sf::Text deathText;
    Player player;
    std::vector<Asteroid> asteroids;
    Background background;
};

#endif