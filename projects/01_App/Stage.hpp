#pragma once
#include "DrawableShapes.hpp"

class Stage :public DrawableShapes {

public:
	void setCircleOrigin(const sf::Vector2f& origin);
	virtual void start() override;
	virtual void update(const sf::Time& dt) override;
	virtual void draw(Window& window) override;

private:
	sf::CircleShape m_circle;
};