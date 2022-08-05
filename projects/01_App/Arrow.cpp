#include "Arrow.hpp"
#include "Window.hpp"
#include "Math.h"

void Arrow::start()
{
	m_length = 100;
	m_lineThickness = 8.0f;
	m_headOfArrowLength = m_lineThickness * 2.0f;
	m_line.setSize(sf::Vector2f(m_length- m_headOfArrowLength, m_lineThickness));
	m_line.setOrigin(sf::Vector2f(0.0f, m_lineThickness/2));
	m_line.setFillColor(sf::Color::Yellow);
	m_line.setPosition(sf::Vector2f(100.0f, 100.0f));

	m_headOfArrow.setPointCount(3.0f);
	m_headOfArrow.setRadius(m_headOfArrowLength);
	m_headOfArrow.setOrigin(sf::Vector2f(m_headOfArrowLength, m_headOfArrowLength));
	m_headOfArrow.setPosition(m_line.getPosition()+sf::Vector2f(m_length- m_headOfArrowLength, 0.0f));
	m_headOfArrow.setFillColor(sf::Color::Yellow);
	m_headOfArrow.setRotation(90.0f);
}

void Arrow::update(const sf::Time& dt)
{
}

void Arrow::draw(Window& window)
{
	window.draw(m_line);
	window.draw(m_headOfArrow);
}

void Arrow::setFirstPosition(const sf::Vector2f& firstPosition)
{
	m_line.setPosition(firstPosition);
}

void Arrow::setLastPosition(const sf::Vector2f& lastPosition)
{
	auto direction = lastPosition - m_line.getPosition();
	setDirection(direction);
}

void Arrow::setDirection(const sf::Vector2f& direction)
{
	m_direction = direction;
	float length = Math::length(m_direction);
	m_line.setSize(sf::Vector2f(length-m_headOfArrowLength, m_lineThickness));

	auto vecX = sf::Vector2f(1.0f, 0.0f);
	auto cosq = Math::dotNormalize(m_direction, vecX);
	auto radAngle = acosf(cosq);
	float angle = Math::radToDeg(radAngle);

	angle = m_direction.y <= 0.0f ? 360.0f - angle : angle;

	float ratio = 1-(m_headOfArrowLength / length);

	m_line.setRotation(angle);
	m_headOfArrow.setPosition(m_line.getPosition()+m_direction*ratio);
	m_headOfArrow.setRotation(90.0f + angle);
}
