#include "Character.h"



Character::Character()
{
}


Character::~Character()
{
}


void Character::move(Direction dir)
{
	if (isMoving)
	{
		float currentMoveSpeed = movespeed;
		if (float distanceToTravel = 128.0f - distanceTraveled; distanceToTravel < movespeed)
			currentMoveSpeed = distanceToTravel;

		if (dir == UP && distanceTraveled < 128 && !weapon->animator.isPlayingAnimation())
		{
			pos.y -= currentMoveSpeed;
			sprite.setRotation(0.0f);
		}
		else if (dir == DOWN && distanceTraveled < 128 && !weapon->animator.isPlayingAnimation())
		{
			pos.y += currentMoveSpeed;
			sprite.setRotation(180.0f);
		}
		else if (dir == LEFT && distanceTraveled < 128 && !weapon->animator.isPlayingAnimation())
		{
			pos.x -= currentMoveSpeed;
			sprite.setRotation(270.0f);
		}
		else if (dir == RIGHT && distanceTraveled < 128 && !weapon->animator.isPlayingAnimation())
		{
			pos.x += currentMoveSpeed;
			sprite.setRotation(90.0f);
		}
		else
		{
			isMoving = false;
			distanceTraveled = 0;
		}

		distanceTraveled += currentMoveSpeed;
		sprite.setPosition(pos);
	}
		tilePos.x = (pos.x - 64) / 128;
		tilePos.y = (pos.y - 64) / 128;
}

void Character::draw(sf::RenderTarget & renderTarget, sf::RenderStates states) const
{
	renderTarget.draw(this->sprite, states);

}

void Character::draw(sf::RenderTarget & renderTarget) const
{
	renderTarget.draw(this->sprite);
}