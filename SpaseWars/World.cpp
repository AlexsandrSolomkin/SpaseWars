#include "World.h"
#include "Player.h"
#include "Projectile.h"
#include "Game.h"
#include "Asteroid.h"
#include "AsteroidSpawner.h"
#include "Math.h"

void World::init()
{
	player = new Player();
	player->init(this, sf::Vector2f(600, 400));

	asteroidSpawner = new AsteroidSpawner();
	asteroidSpawner->init();
}

void World::deinit()
{
	delete player;
	delete asteroidSpawner;

	for (int i = 0; i < projectiles.size(); ++i)
	{
		delete projectiles[i];
	}

	for (int i = 0; i < asteroids.size(); ++i)
	{
		delete asteroids[i];
	}
}

void World::handleInput(const sf::Event& EVENT)
{
	player->handleInput(EVENT);
}

void World::update(float deltaSeconds)
{
	asteroidSpawner->update(*this, deltaSeconds);
	player->update(deltaSeconds);

	for (int i = 0; i < projectiles.size(); ++i)
	{
		if (!projectiles[i]->bIsDestroyed)
		{
			projectiles[i]->update(*this, deltaSeconds);
		}
	}

	for (int i = 0; i < asteroids.size(); ++i)
	{
		if (!asteroids[i]->bIsDestroyed)
		{
			asteroids[i]->update(*this, deltaSeconds);
		}
	}

	for (int i = 0; i < projectiles.size(); ++i)
	{
		if (!projectiles[i]->bIsDestroyed)
		{
			projectiles[i]->checkCollision(*this);
		}
	}

	player->checkCollision();
}

void World::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < projectiles.size(); ++i)
	{
		if (!projectiles[i]->bIsDestroyed)
		{
			projectiles[i]->draw(window);
		}
	}

	for (int i = 0; i < asteroids.size(); ++i)
	{
		if (!asteroids[i]->bIsDestroyed)
		{
			asteroids[i]->draw(window);
		}
	}

	player->draw(window);
}

Projectile* World::createProjectile(const sf::Vector2f& POSITION, const sf::Vector2f& DIRECTION)
{
	Projectile* projectile = new Projectile();

	const sf::Vector2f PROJECTILE_SIZE(5, 20);
	sf::FloatRect rect(POSITION.x - PROJECTILE_SIZE.x / 2, POSITION.y - PROJECTILE_SIZE.y / 2, 5, 20);
	projectile->init(getGame().gameTextureShips, sf::IntRect(0, 0, 5, 20), rect, DIRECTION);
	
	projectiles.push_back(projectile);

	return projectile;
}

Asteroid* World::createAsteroid(const sf::Vector2f& POSITION, const sf::Vector2f& DIRECTION, float speed)
{
	Asteroid* asteroid = new Asteroid();

	const float ROTATION_SPEED = Math::randFloatRange(35.f, 80.f);

	asteroid->init(getGame().gameTexture¿steroids, sf::IntRect(15, 11, 56, 54), sf::FloatRect(POSITION.x, POSITION.y, 56, 54), DIRECTION, speed, ROTATION_SPEED);
	
	asteroids.push_back(asteroid);

	return asteroid;
}

void World::onPlayerDied()
{
	getGame().restartGame();
}
