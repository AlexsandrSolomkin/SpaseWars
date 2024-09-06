#include <SFML/Graphics/RenderWindow.hpp>

#include "AsteroidSpawner.h"
#include "Math.h"
#include "World.h"
#include "Game.h"

void AsteroidSpawner::init()
{
	timeToSpawn = 1.f;
}

void AsteroidSpawner::update(World& world, float deltaSeconds)
{
	timeToSpawn -= deltaSeconds;
	if (timeToSpawn > 0.f)
	{
		return;
	}

	timeToSpawn = Math::randFloatRange(minSpawnTime, maxSpawnTime);

	const int SPAWN_COUNT = Math::randIntRange(minSpawnCount, maxSpawnCount);
	
	for (int i = 0; i < SPAWN_COUNT; i++)
	{
		const int SPEED = Math::randFloatRange(minAsteroidSpeed, maxAsteroidSpeed);
		
		const sf::Vector2f SPAWN_POSITION(Math::randFloatRange(30, getGame().window->getSize().x - 30), -64);
		world.createAsteroid(SPAWN_POSITION, sf::Vector2f(0, 1), SPEED);
	}
}
