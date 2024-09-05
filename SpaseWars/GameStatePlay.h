#pragma once
#include "World.h"

struct GameStatePlay
{
	World world;

	void init();
	void update(float deltaSeconds);
	void draw(sf::RenderWindow& window);
};