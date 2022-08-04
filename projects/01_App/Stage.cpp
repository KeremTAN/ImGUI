#include "Stage.hpp"
#include "Window.hpp"
#include "Math.h"
#include "imgui.h"
#include <imgui-SFML.h>

void Stage::start()
{
	m_point.setRadius(4);
	m_point.setOrigin(sf::Vector2f(4, 4));
	m_circle.setFillColor(sf::Color::Red);

	m_isChanged = false;
	m_circle.setRadius(100.0f);
	m_circle.setOrigin(sf::Vector2f(100, 100));
	m_circle.setFillColor(sf::Color::Blue);

	m_heightOfLine = 4.0f;
	m_line.setSize(sf::Vector2f(100, m_heightOfLine));
	m_line.setOrigin(sf::Vector2f(0, m_heightOfLine / 2.0f));
	m_line.setFillColor(sf::Color::Magenta);
}

void Stage::setCircleOrigin(const sf::Vector2f& origin)
{
	if (m_isHoveronPanel)
		return;
	m_circle.setPosition(origin);
	m_isChanged = true;
	m_circle.setRadius(2.0f);
	m_circle.setOrigin(sf::Vector2f(1.0f, 1.0f));

	m_firstPosition = origin;
	m_lastPosition = origin;
	m_line.setPosition(m_firstPosition);
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

	m_lastPosition = lastPosition;
}

void Stage::isCircleFinished(bool isFinish)
{
	m_isChanged = !isFinish;
}

void Stage::drawGuiPanel()
{
	auto origin = m_circle.getPosition();
	ImGui::Begin("Stage Panel");
	m_isHoveronPanel = false;
	if (ImGui::IsWindowHovered())
		m_isHoveronPanel = true;
	
	ImGui::Text("Origin(x,y) : (%0.1f,%0.1f)",origin.x, origin.y);
	ImGui::Text("Radius(r)   : (%0.1f)", abs(m_circle.getRadius()));
	ImGui::SliderFloat2("First Position", &m_firstPosition.x, 0, 1000);
	ImGui::SliderFloat2("Last Position", &m_lastPosition.x, 0, 1000);
	ImGui::SliderFloat("Angle", &m_angle, -360, 360);
	ImGui::SliderFloat2("Vector", &m_vecDiff.x, -1000, 1000);
	ImGui::Checkbox("Mouse hover on panel", &m_isHoveronPanel);
	ImGui::End();
}

void Stage::update(const sf::Time& dt)
{
	m_vecDiff = m_lastPosition - m_firstPosition;
	float length = Math::length(m_vecDiff);
	m_line.setSize(sf::Vector2f(length, m_heightOfLine));
	auto vecX = sf::Vector2f(1.0f, 0.0f);
	auto cosq = Math::dotNormalize(m_vecDiff, vecX);
	auto radAngle = acosf(cosq);
	m_angle = Math::radToDeg(radAngle);
	m_angle = m_vecDiff.y <= 0.0f ? 360.0f - m_angle : m_angle;

	m_line.setRotation(m_angle);
}

void Stage::draw(Window& window)
{
	drawGuiPanel();
	//window.draw(m_circle);

	m_point.setPosition(m_firstPosition);
	window.draw(m_point);
	m_point.setPosition(m_lastPosition);
	window.draw(m_point);
	window.draw(m_line);

}
