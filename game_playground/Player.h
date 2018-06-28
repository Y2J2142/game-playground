#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Weapon.h"
class Player :  public Character
{
public:
	Weapon* weapon;
	std::vector<std::unique_ptr<Weapon>> weapons;


	Player() = delete;
	Player(sf::Vector2f, float movespeed, int health, std::string texturePath);
	~Player();

	void update(sf::RenderWindow& renderWindow, sf::RenderTarget & output, sf::Time time) override;
	void movementHandler(const sf::RenderWindow &);
};

