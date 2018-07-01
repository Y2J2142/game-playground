#pragma once
#include "Character.h"
class Enemy :
	public Character
{
public:
	Enemy() = delete;
	Enemy(sf::Vector2f, float movespeed, int health, std::string texturePath);
	~Enemy();
	void update(sf::RenderWindow& renderWindow, sf::RenderTarget & output, sf::Time time, const Character & target);
	void movementHandler();
	void movementHandler(const Character &);
};

