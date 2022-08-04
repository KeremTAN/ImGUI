#pragma once
#include "DrawableShapes.hpp"

class Stage :public DrawableShapes {

public:
	virtual void start() override;
	void setCircleOrigin(const sf::Vector2f& origin);
	void setCircleLastPosition(const sf::Vector2f& lastPosition);
	void isCircleFinished(bool isFinish);
	void drawGuiPanel();
	virtual void update(const sf::Time& dt) override;
	virtual void draw(Window& window) override;

private:
	bool				m_isChanged;
	bool				m_isHoveronPanel;
	float				m_angle;
	float				m_heightOfLine;

	sf::Vector2f		m_vecDiff;
	sf::Vector2f		m_firstPosition;
	sf::Vector2f		m_lastPosition;
	sf::CircleShape		m_circle;
	sf::CircleShape		m_point;
	sf::RectangleShape	m_line;
};