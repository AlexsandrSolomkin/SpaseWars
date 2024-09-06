#include "GameStatePlay.h"

void GameStatePlay::init()
{
	world.init();
}

void GameStatePlay::deinit()
{
	world.deinit();
}

void GameStatePlay::handleInput(const sf::Event& EVENT)
{
	world.handleInput(EVENT);
}

void GameStatePlay::update(float deltaSeconds)
{
	world.update(deltaSeconds);
}

void GameStatePlay::draw(sf::RenderWindow& window)
{
	world.draw(window);
}
