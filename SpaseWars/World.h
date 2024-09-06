#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace sf
{
	class Event;
	class RenderWindow;
}

struct Player;
struct Projectile;
struct Asteroid;
struct AsteroidSpawner;

struct World
{
	AsteroidSpawner* asteroidSpawner = nullptr;
	Player* player = nullptr;
	std::vector<Projectile*> projectiles;
	std::vector<Asteroid*> asteroids;

	void init();
	void deinit();
	void handleInput(const sf::Event& EVENT);
	void update(float deltaSeconds);
	void draw(sf::RenderWindow& window);

	Projectile* createProjectile(const sf::Vector2f& POSITION, const sf::Vector2f& DIRECTION);
	Asteroid* createAsteroid(const sf::Vector2f& POSITION, const sf::Vector2f& DIRECTION, float speed);

	void onPlayerDied();
};