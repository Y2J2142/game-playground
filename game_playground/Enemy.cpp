#include "Enemy.h"
#include "MeleeWeapon.h"
#include  <iostream>

Enemy::Enemy(sf::Vector2f pos, float movespeed, int health, std::string texturePath)
{
	dir = UP;
	isMoving = false;
	distanceTraveled = 0;
	this->pos = pos;
	this->movespeed = movespeed;
	this->health = health;
	this->texture.loadFromFile(texturePath);
	this->sprite.setTexture(this->texture);
	auto[x, y] = this->texture.getSize();
	this->sprite.setOrigin(x / 2, y / 2);
	this->sprite.setScale(2.0f, 2.0f);
	this->sprite.setPosition(sf::Vector2f(this->pos));
	this->weapon = new MeleeWeapon(10, 10, 128, { -40, -10 }, "../sprites/sword_anim2.png");
	std::fill(std::begin(canMove), std::end(canMove), true);
	tilePos.x = (pos.x - 64) / 128;
	tilePos.y = (pos.y - 64) / 128;
}


Enemy::~Enemy()
{
}

void Enemy::update(sf::RenderWindow & renderWindow, sf::RenderTarget & output, sf::Time time, const Character & target)
{
	movementHandler(target);
	if (weapon)
		this->weapon->update(renderWindow, output, *(this), time);
	draw(output);
}

void Enemy::movementHandler()
{
}

void Enemy::movementHandler(const Character & target)
{
	auto[thisX, thisY] = this->pos;
	auto[targetX, targetY] = target.pos;

	if (targetX > thisX && canMove[RIGHT])
	{
		isMoving = true;
		dir = RIGHT;
		move();
	}
	else if (targetX < thisX && canMove[LEFT])
	{
		isMoving = true;
		dir = LEFT;
		move();
	}
	else if (targetY > thisY && canMove[DOWN])
	{
		isMoving = true;
		dir = DOWN;
		move();
	}
	else if (targetY < thisY && canMove[UP])
	{
		isMoving = true;
		dir = UP;
		move();
	}
}
