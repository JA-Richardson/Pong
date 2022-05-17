#include "Bat.h"

Bat::Bat(float startPosX, float startPosY)
{
	m_pos.x = startPosX;
	m_pos.y = startPosY;

	m_bat.setSize(sf::Vector2f(50, 5));
	m_bat.setPosition(m_pos);
}

sf::FloatRect Bat::getPos()
{
	return m_bat.getGlobalBounds();
}

sf::RectangleShape Bat::getBat()
{
	return m_bat;
}

void Bat::moveLeft()
{
	m_moveLeft = true;
}

void Bat::moveRight()
{
	m_moveRight = true;
}

void Bat::stopLeft()
{
	m_moveLeft = false;
}

void Bat::stopRight()
{
	m_moveRight = false;
}

void Bat::update(sf::Time deltaTime)
{
	if (m_moveLeft)
	{
		m_pos.x -= m_speed * deltaTime.asSeconds();
	}
	if (m_moveRight)
	{
		m_pos.x += m_speed * deltaTime.asSeconds();
	}
	m_bat.setPosition(m_pos);
}
