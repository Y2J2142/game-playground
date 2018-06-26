#include "Player.h"



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

}


Player::~Player()
{
}

void Player::draw(sf::RenderTarget & renderTarget, sf::RenderStates states) const
{
	renderTarget.draw(this->sprite, states);
}

void Player::draw(sf::RenderTarget & renderTarget) const
{
	renderTarget.draw(this->sprite);
}
