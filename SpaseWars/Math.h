#pragma once

#include <SFML/System/Vector2.hpp>

namespace Math
{
	const float PI = 3.14159f;

	float getAngelFromVector(const sf::Vector2f& VECTOR);

	sf::Vector2f getNormalizedVector(const sf::Vector2f& VECTOR);
};