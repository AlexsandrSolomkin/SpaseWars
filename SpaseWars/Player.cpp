#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

#include "Player.h"
#include "Game.h"
#include "Math.h"

sf::Vector2f Player::getCenter()
{
	return {rect.left + rect.width / 2, rect.top + rect.height / 2 };
}

void Player::init(const sf::Vector2f& position)
{
	rect.left = position.x;
	rect.top = position.y;

	sprite.setTexture(getGame().gameTextureShips);

	const sf::Vector2f PLAYER_TEXTURE_SIZE = {155, 244};
	sprite.setTextureRect(sf::IntRect(2102, 388, PLAYER_TEXTURE_SIZE.x, PLAYER_TEXTURE_SIZE.y));

	sprite.setOrigin(PLAYER_TEXTURE_SIZE.x / 2, PLAYER_TEXTURE_SIZE.y / 2);

	const sf::Vector2f spriteScale = {rect.width / PLAYER_TEXTURE_SIZE.x, rect.height / PLAYER_TEXTURE_SIZE.y};
	sprite.setScale(spriteScale);

}

void Player::update(float deltaSeconds)
{
	sf::Vector2f velocity;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		velocity.y -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		velocity.y += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		velocity.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		velocity.x += speed;
	}

	velocity *= deltaSeconds;

	rect.left += velocity.x;
	rect.top += velocity.y;

	const sf::Vector2i mousePosition = sf::Mouse::getPosition(*getGame().window);

	direction = { mousePosition.x - getCenter().x, mousePosition.y - getCenter().y};
	direction = Math::getNormalizedVector(direction);
}

void Player::draw(sf::RenderWindow& window)
{
	sprite.setPosition(getCenter());

	sprite.setRotation(Math::getAngelFromVector(direction) + 90);
	window.draw(sprite);
}
