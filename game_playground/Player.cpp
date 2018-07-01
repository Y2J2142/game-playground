#pragma once
#include "Player.h"
#define _USE_MATH_DEFINES 
#include <math.h>  
#include <algorithm>
#include "MeleeWeapon.h"


Player::Player(sf::Vector2f pos, float movespeed, int health, std::string texturePath)
{
	dir = UP;
	isMoving = false;
	distanceTraveled = 0;
	this->pos = pos;
	this->movespeed = movespeed; 
	this->health = health;
	this->texture.loadFromFile(texturePath);
	this->sprite.setTexture(this->texture);
	auto [x, y] = this->texture.getSize();
	this->sprite.setOrigin(x / 2, y / 2);
	this->sprite.setScale(2.0f, 2.0f);
	this->sprite.setPosition(sf::Vector2f(this->pos));
	this->weapon = new MeleeWeapon(10, 10, 128, { -40, -10 }, "../sprites/sword_anim2.png");
	std::fill(std::begin(canMove), std::end(canMove), true);
	tilePos.x = (pos.x - 64) / 128;
	tilePos.y = (pos.y - 64) / 128;
}


Player::~Player()
{
}



void Player::movementHandler(const Character &)
{
	movementHandler();
}
void Player::update(sf::RenderWindow & renderWindow, sf::RenderTarget & output, sf::Time time)
{
	movementHandler();
	if(weapon)
		this->weapon->update(renderWindow, output, *(this), time);
	draw(output);
	
}


void Player::movementHandler()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !isMoving && canMove[UP])
	{
		dir = UP;
		isMoving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !isMoving && canMove[DOWN])
	{
		dir = DOWN;
		isMoving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !isMoving && canMove[LEFT])
	{
		dir = LEFT;
		isMoving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !isMoving && canMove[RIGHT])
	{
		dir = RIGHT;
		isMoving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isMoving)
		if (weapon)
			weapon->attack();

	move();

}