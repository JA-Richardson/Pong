#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "Bat.h"
#include "Ball.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pong!");
    int score = 0;
    int lives = 3;

    Bat bat(1920 / 2, 1080 - 20);
    Ball ball(1920 / 2, 0);
    sf::Text hudScore;
    sf::Text hudLives;
    sf::Font font;
    font.loadFromFile("Font/Positive System.otf");
    hudScore.setFont(font);
    hudScore.setCharacterSize(75);
    hudScore.setPosition(20, 20);
    hudLives.setFont(font);
    hudLives.setCharacterSize(75);
    hudLives.setPosition(1600, 20);
    sf::Clock clock;

    while (window.isOpen())
    {
        //input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            bat.moveLeft();
        }
        else
        {
            bat.stopLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            bat.moveRight();
        }
        else
        {
            bat.stopRight();
        }
        //update
        sf::Time deltaTime = clock.restart();
        bat.update(deltaTime);
        ball.update(deltaTime);
        std::stringstream scoreString;
        std::stringstream livesString;
        scoreString << "Score " << score;
        livesString << "Lives " << lives;
        hudScore.setString(scoreString.str());
        hudLives.setString(livesString.str());
        if (ball.getPos().top > window.getSize().y)
        {
            ball.bounceBottom();
            lives--;
            if (lives < 1)
            {
                score = 0;
                lives = 3;
            }
        }
        if (ball.getPos().top < 0)
        {
            ball.bounceBatOrTop();
            score++;
        }
        if (ball.getPos().left < 0 || ball.getPos().left + ball.getPos().width > window.getSize().x)
        {
            ball.bounceSides();
        }
        if (ball.getPos().intersects(bat.getPos()))
        {
            ball.bounceBatOrTop();
        }
        //draw

        window.clear();
        window.draw(hudScore);
        window.draw(hudLives);
        window.draw(bat.getBat());
        window.draw(ball.getBall());
        window.display();
    }

    return 0;
}