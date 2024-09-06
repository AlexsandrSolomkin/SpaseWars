#include <SFML/Graphics/RenderWindow.hpp>

#include "Asteroid.h"
#include "Math.h"

void Asteroid::init(const sf::Texture& TEXTURE, const sf::IntRect& TEXTURE_RECT, const sf::FloatRect& RECT, const sf::Vector2f& DIRECTION, float movementSpeed, float rotationSpeed)
{
	this->rect = RECT;
	this->direction = DIRECTION;
	this->movementSpeed = movementSpeed;
	this->rotationSpeed = rotationSpeed;

	sprite.setTexture(TEXTURE);
	sprite.setTextureRect(TEXTURE_RECT);
	sprite.setOrigin(TEXTURE_RECT.width / 2, TEXTURE_RECT.height / 2);
	sprite.setScale(RECT.width / TEXTURE_RECT.width, RECT.height / TEXTURE_RECT.height);
}

void Asteroid::update(World& world, float deltaSeconds)
{
	const sf::Vector2f VELOCITY = direction * movementSpeed;
	const sf::Vector2f MOVE_DELTA = VELOCITY * deltaSeconds;

	rect.left += MOVE_DELTA.x;
	rect.top += MOVE_DELTA.y;

	spriteRotation += rotationSpeed * deltaSeconds;
}

void Asteroid::draw(sf::RenderWindow& window)
{
	sprite.setPosition(Math::getRectCenter(rect));
	sprite.setRotation(spriteRotation);

	window.draw(sprite);
}
