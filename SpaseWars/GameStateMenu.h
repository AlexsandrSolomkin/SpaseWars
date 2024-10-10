#pragma once
#include "VerticalButtonList.h"

namespace sf
{
	class Event;
	class RenderWindow;
}

enum class GameMenuNavigationButtonType
{
	Play,
	About,
	Exit,
	Max
};

enum class GameMenuGameModeButtonType
{
	SmallAsteroids,
	BigAsteroids,
	Max
};

struct GameStateMenu
{
	VerticalButtonList buttonsNavigation;
	VerticalButtonList buttonsGameModes;

	void init();
	
	void handleInput(const sf::Event& EVENT);
	void handleNavigationButtonPress();

	void updateGameModeButtons();

	void draw(sf::RenderWindow& window);
};