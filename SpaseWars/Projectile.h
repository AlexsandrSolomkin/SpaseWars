#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace sf
{
	class RenderWindow;
}

struct World;

struct Projectile
{
	sf::FloatRect rect;
	sf::Sprite sprite;
	sf::Vector2f direction;
	float speed = 400.f;

	bool bIsDestroyed = false;

	void init(const sf::Texture& TEXTURE, const sf::IntRect& TEXTURE_RECT, const sf::FloatRect& RECT, const sf::Vector2f& DIRECTION);
	void update(World& world, float deltaSeconds);
	void draw(sf::RenderWindow& window);

	void checkCollision(World& world);
};