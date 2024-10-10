#include "Game.h"

#include <SFML/Graphics/RenderWindow.hpp>

void Game::init(sf::RenderWindow* window)
{
	this->window = window;

	gameTextureShips.loadFromFile("Resources/Texture_space_ship.png");
	gameTextureÀsteroids.loadFromFile("Resources/Àsteroids_spritesheet_diffuse.png");

	defaultFont.loadFromFile("Resources/Fonts/Roboto-Regular.ttf");

	setGameState(GameStateType::Menu);
}

void Game::setGameState(GameStateType newGameStateType)
{
	if (gameStateType == newGameStateType)
	{
		return;
	}

	gameStateType = newGameStateType;

	switch (gameStateType)
	{
	case GameStateType::None:
		break;
	case GameStateType::Play:
		gameStatePlay.deinit();
		gameStatePlay = GameStatePlay();
		gameStatePlay.init();
		break;
	case GameStateType::Menu:
		gameStateMenu.init();
		break;
	}
}

void Game::handleInput(const sf::Event& EVENT)
{
	switch (gameStateType)
	{
	case GameStateType::Play:
		gameStatePlay.handleInput(EVENT);
		break;
	case GameStateType::Menu:
		gameStateMenu.handleInput(EVENT);
		break;
	}
}

void Game::update(float deltaSeconds)
{
	switch (gameStateType)
	{
	case GameStateType::Play:
		gameStatePlay.update(deltaSeconds);
		break;
	case GameStateType::Menu:
		break;
	}
}

void Game::draw()
{
	window->clear();

	switch (gameStateType)
	{
	case GameStateType::Play:
		gameStatePlay.draw(*window);
		break;
	case GameStateType::Menu:
		gameStateMenu.draw(*window);
		break;
	}

	window->display();
}

void Game::restartGame()
{
	setGameState(GameStateType::None);
	setGameState(GameStateType::Play);
}

Game& getGame()
{
	static Game game;
	return game;
}
