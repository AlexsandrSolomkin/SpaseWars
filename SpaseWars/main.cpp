#include "SFML/Graphics.hpp"
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 1200), "Space Wars");

	Game& game = getGame();
	game.init(&window);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::sleep(sf::seconds(0.001f));

		const float CLOCK_DELTA_SECONDS = clock.getElapsedTime().asSeconds();
		clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				break;
			}
			game.handleInput(event);
		}
		game.update(CLOCK_DELTA_SECONDS);
		game.draw();
	}
	return 0;
}