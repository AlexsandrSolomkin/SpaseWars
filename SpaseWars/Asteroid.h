#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace sf
{
	class RenderWindow;
}

struct World;

struct Asteroid
{
	sf::FloatRect rect;
	sf::Sprite sprite;
	sf::Vector2f direction;
	float movementSpeed = 100.f;
	float rotationSpeed = 100.f;

	float spriteRotation = 0.f;

	bool bIsDestroyed = false;

	void init(const sf::Texture& TEXTURE, const sf::IntRect& TEXTURE_RECT, const sf::FloatRect& RECT, const sf::Vector2f& DIRECTION, float movementSpeed, float rotationSpeed);
	void update(World& world, float deltaSeconds);
	void draw(sf::RenderWindow& window);
};