#include "Game.h"

#include <SFML/Graphics/RenderWindow.hpp>

void Game::init(sf::RenderWindow* window)
{
	this->window = window;

	gameTextureShips.loadFromFile("Resources/Texture_space_ship.png");
	gameTextureÀsteroids.loadFromFile("Resources/Àsteroids_spritesheet_diffuse.png");

	setGameState(GameStateType::Play);
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
	case GameStateType::Play:
		gameStatePlay.deinit();
		gameStatePlay = GameStatePlay();
		gameStatePlay.init();
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
	}
}

void Game::update(float deltaSeconds)
{
	switch (gameStateType)
	{
	case GameStateType::Play:
		gameStatePlay.update(deltaSeconds);
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
