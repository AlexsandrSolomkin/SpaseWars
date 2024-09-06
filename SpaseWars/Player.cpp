#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Game.h"
#include "Math.h"
#include "Player.h"
#include "Asteroid.h"

void Player::init(World* world, const sf::Vector2f& POSITION)
{
	this->world = world;

	rect.left = POSITION.x;
	rect.top = POSITION.y;

	sprite.setTexture(getGame().gameTextureShips);

	const sf::Vector2f PLAYER_TEXTURE_SIZE = {155, 244};
	sprite.setTextureRect(sf::IntRect(2102, 388, PLAYER_TEXTURE_SIZE.x, PLAYER_TEXTURE_SIZE.y));

	sprite.setOrigin(PLAYER_TEXTURE_SIZE.x / 2, PLAYER_TEXTURE_SIZE.y / 2);

	const sf::Vector2f SPRITE_SCALE = {rect.width / PLAYER_TEXTURE_SIZE.x, rect.height / PLAYER_TEXTURE_SIZE.y};
	sprite.setScale(SPRITE_SCALE);
}

void Player::handleInput(const sf::Event& EVENT)
{
	if (EVENT.type == sf::Event::KeyPressed)
	{
		if (EVENT.key.code ==sf::Keyboard::Space)
		{
			shot();
		}
	}
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

	const sf::Vector2i MOUSE_POSITION = sf::Mouse::getPosition(*getGame().window);
	const sf::Vector2f PLAYER_CENTER = Math::getRectCenter(rect);

	direction = { MOUSE_POSITION.x - PLAYER_CENTER.x, MOUSE_POSITION.y - PLAYER_CENTER.y};
	direction = Math::getNormalizedVector(direction);
}

void Player::draw(sf::RenderWindow& window)
{
	sprite.setPosition(Math::getRectCenter(rect));
	sprite.setRotation(Math::getAngelFromVector(direction) + 90);

	window.draw(sprite);
}

void Player::shot()
{
	world->createProjectile(Math::getRectCenter(rect), direction);
}

void Player::checkCollision()
{
	for (int i = 0; i < world->asteroids.size(); i++)
	{
		Asteroid* asteroid = world->asteroids[i];

		if (!asteroid->bIsDestroyed && asteroid->rect.intersects(rect))
		{
			world->onPlayerDied();
			break;
		}
	}
}
