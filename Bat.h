#pragma once
#include <SFML/Graphics.hpp>
class Bat
{
private:
	sf::Vector2f m_pos;

	sf::RectangleShape m_bat;
	float m_speed = 1000.f;
	bool m_moveLeft = false;
	bool m_moveRight = false;

public:
	Bat(float startPosX, float startPosY);

	sf::FloatRect getPos();
	sf::RectangleShape getBat();

	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(sf::Time deltaTime);
};

