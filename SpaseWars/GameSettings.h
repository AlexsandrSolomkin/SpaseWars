#pragma once

enum class GameMode
{
	SmallAsteroids = 1 << 0,
	BigAsteroids = 1 << 1,
	Max
};

struct GameSettings
{
	GameMode gameMode = GameMode::SmallAsteroids;

	bool hasGameMode(GameMode gameModeSetting);
	void switchGameMode(GameMode gameModeSetting);
};