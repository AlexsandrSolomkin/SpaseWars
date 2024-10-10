#pragma once

#include <vector>

#include "Button.h"

namespace sf
{
	class RenderWindow;
}

struct VerticalButtonList
{
	std::vector<Button*> buttons;
	int selectedButtonIndex = -1;

	sf::Vector2f positionList;

	float buttonsOffset = 150;

	void init(const sf::Vector2f& POSITION);

	Button* addButton();
	Button* getButton(int index);

	void setSelectedButton(int index);
	int getSelectedButtonIndex();
	Button* getSelectedButton();

	void draw(sf::RenderWindow& window);
};