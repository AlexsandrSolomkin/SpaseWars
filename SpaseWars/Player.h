#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace sf
{
	class RenderWindow;
}

struct Player
{
	sf::FloatRect rect = {0.f, 0.f, 80.f, 80.f};
	sf::Sprite sprite;

	sf::Vector2f direction;

	float speed = 200.f;

	sf::Vector2f getCenter();

	void init(const sf::Vector2f& position);
	void update(float deltaSeconds);
	void draw(sf::RenderWindow& window);
};