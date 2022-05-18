#include "Ball.h"

Ball::Ball(float startX, float startY)
{
	m_pos.x = startX;
	m_pos.y = startY;

	m_ball.setSize(sf::Vector2f(10, 10));
	m_ball.setPosition(m_pos);
}

sf::FloatRect Ball::getPos()
{
	return m_ball.getGlobalBounds();
}

sf::RectangleShape Ball::getBall()
{
	return m_ball;
}

float Ball::getXVel()
{
	return m_directionX;
}

void Ball::bounceSides()
{
	m_directionX = -m_directionX;
}

void Ball::bounceBatOrTop()
{
	m_directionY = -m_directionY;
}

void Ball::bounceBottom()
{
	m_pos.y = 0;
	m_pos.x = 500;
	m_directionY = -m_directionY;
}

void Ball::update(sf::Time deltaTime)
{
	m_pos.x += m_directionX * m_speed * deltaTime.asSeconds();
	m_pos.y += m_directionY * m_speed * deltaTime.asSeconds();
	m_ball.setPosition(m_pos);
}
