#include "Button.h"
#include "Game.h"

#include <SFML/Graphics/RenderWindow.hpp>

void Button::init()
{
	text.setFont(getGame().defaultFont);
	text.setCharacterSize(32);
	
	backgroundShape.setSize(sf::Vector2f(300.f, 64.f));
	backgroundShape.setOrigin(backgroundShape.getLocalBounds().width / 2, backgroundShape.getLocalBounds().height / 2);

	setSelected(false);
}

void Button::setText(const std::string& BUTTON_TEXT)
{
	text.setString(BUTTON_TEXT);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}

void Button::setPositionLeftTop(const sf::Vector2f& POSITION)
{
	const sf::Vector2f centerPosition = POSITION + sf::Vector2f(backgroundShape.getLocalBounds().width / 2, backgroundShape.getLocalBounds().height / 2);
	setPositionCenter(centerPosition);
}

void Button::setPositionCenter(const sf::Vector2f& POSITION)
{
	text.setPosition(POSITION);
	backgroundShape.setPosition(POSITION);
}

void Button::setSelected(bool bSelected)
{
	bIsSelected = bSelected;
	if (bIsSelected)
	{
		backgroundShape.setFillColor(selectedButtonColor);
	}
	else
	{
		backgroundShape.setFillColor(defaultButtonColor);
	}
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(backgroundShape);
	window.draw(text);
}
