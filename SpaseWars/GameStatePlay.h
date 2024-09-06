#pragma once

#include "World.h"

struct GameStatePlay
{
	World world;

	void init();
	void deinit();
	void handleInput(const sf::Event& EVENT);
	void update(float deltaSeconds);
	void draw(sf::RenderWindow& window);
};