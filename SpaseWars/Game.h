#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "GameStatePlay.h"
#include "GameStateMenu.h"
#include "GameSettings.h"

namespace sf
{
	class RenderWindow;
}

enum class GameStateType
{
	None,
	Menu,
	Play
};

struct Game
{
	sf::RenderWindow* window = nullptr;

	sf::Texture gameTextureShips;
	sf::Texture gameTexture¿steroids;

	sf::Font defaultFont;

	GameSettings gameSetting;

	GameStateType gameStateType = GameStateType::None;
	GameStatePlay gameStatePlay;
	GameStateMenu gameStateMenu;

	void init(sf::RenderWindow* window);

	void setGameState(GameStateType newGameStateType);

	void handleInput(const sf::Event& EVENT);
	void update(float deltaSeconds);
	void draw();

	void restartGame();
};

Game& getGame();