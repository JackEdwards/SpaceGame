#include "Game.h"

int Game::windowWidth = 640;
int Game::windowHeight = 640;


Game::Game() :
    window(sf::VideoMode(windowWidth, windowHeight), "Spaaaaaaace!", sf::Style::Close),
    asteroids(5),
    startText("Press enter to begin, or Q to quit.", font),
    deathText("You died!\nPress enter to R to the start menu.", font)
{
    srand(time(NULL));
    font.loadFromFile(resourcePath() + "sansation.ttf");
    startGame();
}

void Game::run()
{
    while (window.isOpen()) {
        update();
        render();
    }
}

void Game::update()
{
    handleEvents();
    float deltaTime = clock.restart().asSeconds();
    
    switch (gameState) {
        case StartScreen: {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                gameState = GameScreen;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();
            
            break;
        }
        case GameScreen: {
            handleInput(deltaTime);
            moveAsteroids(deltaTime);
            handleCollision();
            
            break;
        }
        case DeathScreen: {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                startGame();
            
            break;
        }
    }
}

void Game::render()
{
    window.clear();
    
    switch (gameState) {
        case StartScreen: {
            window.draw(startText);
            
            break;
        }
        case GameScreen: {
            window.draw(background.getSprite());
            for (Asteroid asteroid : asteroids)
                window.draw(asteroid.getSprite());
            window.draw(player.getSprite());
            
            break;
        }
        case DeathScreen: {
            window.draw(deathText);
            
            break;
        }
    }
    
    window.display();
}

void Game::handleEvents()
{
    sf::Event event;
    
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::handleInput(float &deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && playerCanMoveLeft())
        player.getSprite().move(-player.getSpeed() * deltaTime, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && playerCanMoveRight())
        player.getSprite().move(player.getSpeed() * deltaTime, 0.0f);
}

void Game::moveAsteroids(float &deltaTime)
{
    for (Asteroid& asteroid : asteroids) {
        asteroid.getSprite().move(0.0f, asteroid.getSpeed() * deltaTime);
        
        if (asteroidHasPassed(asteroid)) {
            sf::Vector2u spriteSize = Asteroid::getSpriteSize();
            
            int x = rand() % (windowWidth - spriteSize.x) + 1;
            int y = -spriteSize.y;
            asteroid.getSprite().setPosition(sf::Vector2f(x, y));
        }
    }
}

void Game::handleCollision()
{
    for (Asteroid asteroid : asteroids)
        if (player.getSprite().getGlobalBounds().intersects(asteroid.getSprite().getGlobalBounds()))
            gameState = DeathScreen;
}

bool Game::asteroidHasPassed(Asteroid &asteroid)
{
    if (asteroid.getSprite().getPosition().y > windowHeight)
        return true;
    return false;
}

bool Game::playerCanMoveLeft()
{
    if (player.getSprite().getPosition().x > 0)
        return true;
    return false;
}

bool Game::playerCanMoveRight()
{
    if (player.getSprite().getPosition().x + player.getSprite().getGlobalBounds().width < windowWidth)
        return true;
    return false;
}

void Game::startGame()
{
    gameState = StartScreen;
    
    player.getSprite().setPosition(windowWidth / 2, (windowHeight - Player::getSpriteSize().y) - 10);
    
    for (int i = 0; i < asteroids.size(); ++i)
        asteroids[i].getSprite().setPosition(rand() % (windowWidth - Asteroid::getSpriteSize().x) + 1, i * -200);
}
