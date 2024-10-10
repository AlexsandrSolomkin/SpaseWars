#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace sf
{
	class RenderWindow;
}

struct Button
{
	sf::Text text;
	sf::RectangleShape backgroundShape;

	sf::Color defaultButtonColor = sf::Color(126, 196, 65, 200);
	sf::Color selectedButtonColor = sf::Color(196, 65, 65, 200);

	bool bIsSelected = false;

	void init();

	void setText(const std::string& BUTTON_TEXT);

	void setPositionLeftTop(const sf::Vector2f& POSITION);
	void setPositionCenter(const sf::Vector2f& POSITION);

	void setSelected(bool bSelected);
	void draw(sf::RenderWindow& window);
};