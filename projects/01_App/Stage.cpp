#include "Stage.hpp"
#include "Window.hpp"
#include "imgui.h"
#include <imgui-SFML.h>

void Stage::setCircleOrigin(const sf::Vector2f& origin)
{
	m_circle.setPosition(origin);
	m_isChanged = true;
	m_circle.setRadius(2.0f);
	m_circle.setOrigin(sf::Vector2f(1.0f, 1.0f));
}

void Stage::setCircleLastPosition(const sf::Vector2f& lastPosition)
{
	if (m_isChanged==false)
		return;
	auto origin = m_circle.getPosition();
	auto difference = lastPosition - origin;
	float radius = difference.x > difference.y ? difference.x : difference.y;
	m_circle.setRadius(radius);
	m_circle.setOrigin(sf::Vector2f(radius, radius));
}

void Stage::isCircleFinished(bool isFinish)
{
	m_isChanged = !isFinish;
}

void Stage::drawGuiPanel()
{
	auto origin = m_circle.getPosition();
	ImGui::Begin("Stage Panel");
	ImGui::Text("Origin(x,y) : (%0.1f,%0.1f)",origin.x, origin.y);
	ImGui::Text("Radius(r)   : (%0.1f)", m_circle.getRadius());
	ImGui::End();
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
	drawGuiPanel();
	window.draw(m_circle);
}
