#include <SFML/Graphics/RenderWindow.hpp>

#include "Projectile.h"
#include "Math.h"
#include "Asteroid.h"
#include "World.h"

void Projectile::init(const sf::Texture& TEXTURE, const sf::IntRect& TEXTURE_RECT, const sf::FloatRect& RECT, const sf::Vector2f& DIRECTION)
{
	this->rect = RECT;
	this->direction = DIRECTION;

	sprite.setTexture(TEXTURE);
	sprite.setTextureRect(TEXTURE_RECT);
	sprite.setOrigin(TEXTURE_RECT.width / 2, TEXTURE_RECT.height / 2);
	sprite.setScale(RECT.width / TEXTURE_RECT.width, RECT.height / TEXTURE_RECT.height);
}

void Projectile::update(World& world, float deltaSeconds)
{
	const sf::Vector2f VELOCITY = direction * speed;
	const sf::Vector2f MOVE_DELTA = VELOCITY * deltaSeconds;

	rect.left += MOVE_DELTA.x;
	rect.top += MOVE_DELTA.y;
}

void Projectile::draw(sf::RenderWindow& window)
{
	sprite.setPosition(Math::getRectCenter(rect));
	sprite.setRotation(Math::getAngelFromVector(direction) + 90);

	window.draw(sprite);
}

void Projectile::checkCollision(World& world)
{
	for (int i = 0; i < world.asteroids.size(); i++)
	{
		Asteroid* asteroid = world.asteroids[i];
		
		if (!asteroid->bIsDestroyed && asteroid->rect.intersects(rect))
		{
			asteroid->bIsDestroyed = true;
			bIsDestroyed = true;
			break;
		}
	}
}
