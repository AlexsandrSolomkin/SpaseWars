#include "World.h"
#include "Player.h"

void World::init()
{
	player = new Player();
	player->init(sf::Vector2f(600, 400));
}

void World::update(float deltaSeconds)
{
	player->update(deltaSeconds);
}

void World::draw(sf::RenderWindow& window)
{
	player->draw(window);
}
