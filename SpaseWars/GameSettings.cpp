#include "GameSettings.h"

bool GameSettings::hasGameMode(GameMode gameModeSetting)
{
	const int INT_GAME_MODE = static_cast<int>(gameMode);
	const int INT_GAME_MODE_SETTING = static_cast<int>(gameModeSetting);

	const bool B_HAS_MODE = INT_GAME_MODE & INT_GAME_MODE_SETTING;
	return B_HAS_MODE;
}

void GameSettings::switchGameMode(GameMode gameModeSetting)
{
	const int INT_GAME_MODE = static_cast<int>(gameMode);
	const int INT_GAME_MODE_SETTING = static_cast<int>(gameModeSetting);

	const int NEW_MODE = INT_GAME_MODE ^ INT_GAME_MODE_SETTING;
	gameMode = static_cast<GameMode>(NEW_MODE);
}
