#include "GameStatePlay.h"

void GameStatePlay::init()
{
	world.init();
}

void GameStatePlay::update(float deltaSeconds)
{
	world.update(deltaSeconds);
}

void GameStatePlay::draw(sf::RenderWindow& window)
{
	world.draw(window);
}
