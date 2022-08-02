#include "Stage.hpp"
#include "Window.hpp"

void Stage::setCircleOrigin(const sf::Vector2f& origin)
{
	m_circle.setPosition(origin);
}

void Stage::start()
{
	m_circle.setRadius(100.0f);
	m_circle.setOrigin(sf::Vector2f(100, 100));
	m_circle.setFillColor(sf::Color::Blue);
}

void Stage::update(const sf::Time& dt)
{
	//m_circle.move(sf::Vector2f(1, 1));
}

void Stage::draw(Window& window)
{
	window.draw(m_circle);
}
