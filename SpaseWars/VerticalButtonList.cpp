#include "VerticalButtonList.h"

void VerticalButtonList::init(const sf::Vector2f& POSITION)
{
	positionList = POSITION;
}

Button* VerticalButtonList::addButton()
{
	Button* button = new Button;

	buttons.push_back(button);

	button->init();

	const float BUTTON_Y_POS = positionList.y + buttons.size() * buttonsOffset;
	button->setPositionCenter({ positionList.x, BUTTON_Y_POS });

	return button;
}

Button* VerticalButtonList::getButton(int index)
{
	if (index >= 0 && index < buttons.size())
	{
		return buttons[index];
	}
	return nullptr;
}

void VerticalButtonList::setSelectedButton(int index)
{
	Button* newSelectedButton = getButton(index);
	if (newSelectedButton != nullptr)
	{
		Button* oldSelectedButton = getSelectedButton();
		if (oldSelectedButton != nullptr)
		{
			oldSelectedButton->setSelected(false);
		}

		newSelectedButton->setSelected(true);
		selectedButtonIndex = index;
	}
}

int VerticalButtonList::getSelectedButtonIndex()
{
	return selectedButtonIndex;
}

Button* VerticalButtonList::getSelectedButton()
{
	if (selectedButtonIndex >= 0 && selectedButtonIndex < buttons.size())
	{
		return buttons[selectedButtonIndex];
	}
	return nullptr;
}

void VerticalButtonList::draw(sf::RenderWindow& window)
{
	for (Button* button : buttons)
	{
		if (button != nullptr)
		{
			button->draw(window);
		}
	}
}
