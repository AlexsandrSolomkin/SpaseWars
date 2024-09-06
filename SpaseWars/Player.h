#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace sf
{
	class Event;
}

namespace sf
{
	class RenderWindow;
}

struct World;

struct Player
{
	sf::FloatRect rect = {0.f, 0.f, 80.f, 80.f};
	sf::Sprite sprite;

	sf::Vector2f direction;

	float speed = 200.f;

	World* world = nullptr;

	void init(World* world, const sf::Vector2f& POSITION);
	void handleInput(const sf::Event& EVENT);
	void update(float deltaSeconds);
	void draw(sf::RenderWindow& window);

	void shot();
	void checkCollision();
};