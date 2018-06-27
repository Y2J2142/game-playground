#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "MeleeWeapon.h"
class Player : public sf::Drawable, public Character
{
public:
	MeleeWeapon* weapon;
	std::vector<std::unique_ptr<Weapon>> weapons;


	Player() = delete;
	Player(sf::Vector2f, float movespeed, int health, std::string texturePath);
	~Player();

	virtual void draw(sf::RenderTarget &, sf::RenderStates) const ;
	virtual void draw(sf::RenderTarget &) const;
	virtual void update(sf::RenderWindow& renderWindow, sf::RenderTarget & output, sf::Time time) override;
	void movementHandler(const sf::RenderWindow &);
};

