#pragma once
#include "DrawableShapes.hpp"

class Stage :public DrawableShapes {

public:
	void setCircleOrigin(const sf::Vector2f& origin);
	void setCircleLastPosition(const sf::Vector2f& lastPosition);
	void isCircleFinished(bool isFinish);
	void drawGuiPanel();
	virtual void start() override;
	virtual void update(const sf::Time& dt) override;
	virtual void draw(Window& window) override;

private:
	bool			m_isChanged;
	sf::CircleShape m_circle;
};