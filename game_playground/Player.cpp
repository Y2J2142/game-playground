#pragma once
#include "Player.h"
#define _USE_MATH_DEFINES 
#include <math.h>  
#include "MeleeWeapon.h"


Player::Player(sf::Vector2f pos, float movespeed, int health, std::string texturePath)
{
	this->pos = pos;
	this->movespeed = movespeed; 
	this->health = health;
	this->texture.loadFromFile(texturePath);
	this->sprite.setTexture(this->texture);
	auto [x, y] = this->texture.getSize();
	this->sprite.setOrigin(x / 2, y / 2);
	this->sprite.setScale(2.0f, 2.0f);
	this->sprite.setPosition(sf::Vector2f(this->pos));
	this->weapon = new MeleeWeapon(10, 10, 30, "../sprites/sword.png");
}


Player::~Player()
{
}

void Player::draw(sf::RenderTarget & renderTarget, sf::RenderStates states) const
{
	if (this->weapon == nullptr)
		return;
	renderTarget.draw(this->weapon->sprite, states);
	renderTarget.draw(this->sprite, states);
	
}

void Player::draw(sf::RenderTarget & renderTarget) const
{
	renderTarget.draw(this->sprite);
}


void Player::movementHandler(const sf::RenderWindow & window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))	pos.y -= movespeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))	pos.y += movespeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))	pos.x -= movespeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))	pos.x += movespeed;

	this->sprite.setPosition(pos);

	const auto mouseWindowPosition = sf::Mouse::getPosition(window);
	const auto mouseWorldPosition = window.mapPixelToCoords(mouseWindowPosition);
	const auto fromOrign = this->pos - mouseWorldPosition;

	const float rotation = atan2(fromOrign.x, fromOrign.y) * 180.0f / M_PI;
	this->sprite.setRotation(360.0f - rotation);
	
	this->weapon->update(*(this));

}