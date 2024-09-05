#include "Game.h"

#include <SFML/Graphics/RenderWindow.hpp>

void Game::init(sf::RenderWindow* window)
{
	this->window = window;

	gameTextureShips.loadFromFile("Resources/Texture_space_ship.png");
	gameTexture└steroids.loadFromFile("Resources/└steroids_spritesheet_diffuse.png");

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
		gameStatePlay.init();
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

Game& getGame()
{
	static Game game;
	return game;
}
