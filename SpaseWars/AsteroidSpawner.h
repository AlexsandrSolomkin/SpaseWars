#pragma once

struct World;

struct AsteroidSpawner
{
	float minSpawnTime = 1.0f;
	float maxSpawnTime = 3.0f;

	int minSpawnCount = 1;
	int maxSpawnCount = 3;

	float minAsteroidSpeed = 50.0f;
	float maxAsteroidSpeed = 100.0f;

	float timeToSpawn = 0.0f;

	void init();
	void update(World& world, float deltaSeconds);
};