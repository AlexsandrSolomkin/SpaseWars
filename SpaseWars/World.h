#pragma once

namespace sf
{
	class RenderWindow;
}

struct Player;

struct World
{
	Player* player = nullptr;

	void init();
	void update(float deltaSeconds);
	void draw(sf::RenderWindow& window);
};