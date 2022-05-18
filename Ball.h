#pragma once
#include <SFML/Graphics.hpp>
class Ball
{
private:
		sf::Vector2f m_pos;
		sf::RectangleShape m_ball;

		float m_speed = 300.f;
		float m_directionX = .2f;
		float m_directionY = .2f;
public:
	Ball(float startX, float startY);
	sf::FloatRect getPos();
	sf::RectangleShape getBall();
	float getXVel();
	void bounceSides();
	void bounceBatOrTop();
	void bounceBottom();
	void update(sf::Time deltaTime);
};

