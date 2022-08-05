#pragma once
#include "DrawableShapes.hpp"

class Arrow : public DrawableShapes {
public:
	virtual void start() override;
	virtual void update(const sf::Time& dt) override;
	virtual void draw(Window& window) override;
	void setFirstPosition(const sf::Vector2f& firstPosition);
	void setLastPosition(const sf::Vector2f& lastPosition);
	void setDirection(const sf::Vector2f& direction);
private:
	float				m_length;
	float				m_lineThickness;
	float				m_headOfArrowLength;
	sf::Vector2f		m_direction;
	sf::RectangleShape	m_line;
	sf::CircleShape		m_headOfArrow;
};