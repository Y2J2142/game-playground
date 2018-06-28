#pragma once
#include "Player.h"
#define _USE_MATH_DEFINES 
#include <math.h>  
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
}


Player::~Player()
{
}



void Player::update(sf::RenderWindow & renderWindow, sf::RenderTarget & output, sf::Time time)
{
	movementHandler(renderWindow);
	if(weapon)
		this->weapon->update(renderWindow, output, *(this), time);
	draw(output);
	
}


void Player::movementHandler(const sf::RenderWindow & window)
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


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !isMoving)
	{
		dir = UP;
		isMoving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !isMoving)
	{
		dir = DOWN;
		isMoving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !isMoving)
	{
		dir = LEFT;
		isMoving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !isMoving)
	{
		dir = RIGHT;
		isMoving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isMoving)
		if (weapon)
			weapon->attack();

	

}