#pragma once
#include<SFML/Graphics.hpp>
namespace Math {
	const float PI = 3.1415926535f;

	float length(const sf::Vector2f& vec);
	float dot(const sf::Vector2f& left, const sf::Vector2f& right);
	float dotNormalize(const sf::Vector2f& left, const sf::Vector2f& right);
	sf::Vector2f normalize(const sf::Vector2f& vec);
	float radToDeg(float rad);
	float degToRad(float deg);
}