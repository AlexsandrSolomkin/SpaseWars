#pragma once

#include <SFML/Graphics/Texture.hpp>
#include "GameStatePlay.h"

namespace sf
{
	class RenderWindow;
}

enum class GameStateType
{
	None,
	Play
};

struct Game
{
	sf::RenderWindow* window = nullptr;

	sf::Texture gameTextureShips;
	sf::Texture gameTexture¿steroids;

	GameStateType gameStateType = GameStateType::None;
	GameStatePlay gameStatePlay;

	void init(sf::RenderWindow* window);
	void setGameState(GameStateType newGameStateType);
	void update(float deltaSeconds);
	void draw();
};

Game& getGame();