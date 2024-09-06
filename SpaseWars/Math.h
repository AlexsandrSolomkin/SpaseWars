#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace Math
{
	const float PI = 3.14159f;

	float getAngelFromVector(const sf::Vector2f& VECTOR);

	sf::Vector2f getNormalizedVector(const sf::Vector2f& VECTOR);
	sf::Vector2f getRectCenter(const sf::FloatRect& RECT);

	int randIntRange(int min, int max);
	float randFloatRange(float min, float max);
};