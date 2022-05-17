#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "Bat.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Pong!");
    int score = 0;
    int lives = 3;

    Bat bat(1920 / 2, 1080 - 20);
    sf::Text hud;
    sf::Font font;
    font.loadFromFile("Font/Positive System.otf");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setPosition(20, 20);

    while (window.isOpen())
    {
        //input

        //update

        //draw

        window.clear();
       
        window.display();
    }

    return 0;
}