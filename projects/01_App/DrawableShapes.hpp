#pragma once
#include<SFML/Graphics.hpp>
//#include "Window.hpp"

class Window;
class DrawableShapes {
public:
	DrawableShapes();
	virtual void draw(Window& window) = 0;
	sf::Vector2f getPosition();
protected: //kal�t�m i�in protected yap�yoruz.
	sf::Vector2f	m_position;
	bool			m_isDrawable;
};
