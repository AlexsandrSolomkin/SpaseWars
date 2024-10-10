#include "GameStateMenu.h"
#include "Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

void GameStateMenu::init()
{
	{
		buttonsNavigation.init(sf::Vector2f(getGame().window->getSize().x / 2, 100.f));

		for (int i = 0; i < static_cast<int>(GameMenuNavigationButtonType::Max); i++)
		{
			buttonsNavigation.addButton();
		}

		buttonsNavigation.getButton(static_cast<int>(GameMenuNavigationButtonType::Play))->setText("Play");
		buttonsNavigation.getButton(static_cast<int>(GameMenuNavigationButtonType::About))->setText("About");
		buttonsNavigation.getButton(static_cast<int>(GameMenuNavigationButtonType::Exit))->setText("Exit");

		buttonsNavigation.setSelectedButton(static_cast<int>(GameMenuNavigationButtonType::Play));
	}

	{
		buttonsGameModes.init(sf::Vector2f(getGame().window->getSize().x / 2, 600.f));

		for (int i = 0; i < static_cast<int>(GameMenuGameModeButtonType::Max); i++)
		{
			buttonsGameModes.addButton();
		}

		buttonsGameModes.getButton(static_cast<int>(GameMenuGameModeButtonType::SmallAsteroids))->setText("1. Small Asteroids");
		buttonsGameModes.getButton(static_cast<int>(GameMenuGameModeButtonType::BigAsteroids))->setText("2. Big Asteroids");

		updateGameModeButtons();
	}
}

void GameStateMenu::handleInput(const sf::Event& EVENT)
{
	if (EVENT.type == sf::Event::KeyPressed)
	{
		switch (EVENT.key.code)
		{
		case sf::Keyboard::W:
			buttonsNavigation.setSelectedButton(buttonsNavigation.getSelectedButtonIndex() - 1);
			break;
		case sf::Keyboard::S:
			buttonsNavigation.setSelectedButton(buttonsNavigation.getSelectedButtonIndex() + 1);
			break;
		case sf::Keyboard::Space:
			handleNavigationButtonPress();
			break;
		case sf::Keyboard::Num1:
			getGame().gameSetting.switchGameMode(GameMode::SmallAsteroids);
			updateGameModeButtons();
			break;
		case sf::Keyboard::Num2:
			getGame().gameSetting.switchGameMode(GameMode::BigAsteroids);
			updateGameModeButtons();
			break;
		}
	}
}

void GameStateMenu::handleNavigationButtonPress()
{
	if (buttonsNavigation.getSelectedButton() != nullptr)
	{
		GameMenuNavigationButtonType selectedButtonType = static_cast<GameMenuNavigationButtonType>(buttonsNavigation.getSelectedButtonIndex());

		switch (selectedButtonType)
		{
		case GameMenuNavigationButtonType::Play:
			getGame().setGameState(GameStateType::Play);
			break;
		case GameMenuNavigationButtonType::About:
			break;
		case GameMenuNavigationButtonType::Exit:
			getGame().window->close();
			break;
		default:
			break;
		}
	}
}

void GameStateMenu::updateGameModeButtons()
{
	GameSettings& gameSettings = getGame().gameSetting;

	for (int i = 0; i < static_cast<int>(GameMenuGameModeButtonType::Max); i++)
	{
		Button* button = buttonsGameModes.getButton(i);
		GameMenuGameModeButtonType buttonType = static_cast<GameMenuGameModeButtonType>(i);
		switch (buttonType)
		{
		case GameMenuGameModeButtonType::SmallAsteroids:
			{
				const bool bHasGameMode = gameSettings.hasGameMode(GameMode::SmallAsteroids);
				button->setSelected(bHasGameMode);
			}
			break;
		case GameMenuGameModeButtonType::BigAsteroids:
			{
				const bool bHasGameMode = gameSettings.hasGameMode(GameMode::BigAsteroids);
				button->setSelected(bHasGameMode);
			}
			break;
		}
	}
}

void GameStateMenu::draw(sf::RenderWindow& window)
{
	buttonsNavigation.draw(window);
	buttonsGameModes.draw(window);
}
