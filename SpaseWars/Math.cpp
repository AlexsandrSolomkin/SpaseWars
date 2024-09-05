#include "Math.h"
#include <cmath>

float Math::getAngelFromVector(const sf::Vector2f& VECTOR)
{
	float angelRadians = atan2(VECTOR.y, VECTOR.x);
	float angelDegrees = angelRadians * (180.f / PI);
	return angelDegrees;
}

sf::Vector2f Math::getNormalizedVector(const sf::Vector2f& VECTOR)
{
	const float LENGTH = sqrt(VECTOR.x * VECTOR.x + VECTOR.y * VECTOR.y);

	if (LENGTH != 0)
	{
		return sf::Vector2f(VECTOR.x / LENGTH, VECTOR.y / LENGTH);
	}
	else
	{
		return VECTOR;
	}
}
