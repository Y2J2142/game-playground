#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Weapon.h"
class Player : public sf::Drawable, public Character
{

	Weapon* weapon;
	std::vector<std::unique_ptr<Weapon>> weapons;
public:

	Player() = delete;
	Player(sf::Vector2f, float movespeed, int health, std::string texturePath);
	~Player();

	virtual void draw(sf::RenderTarget &, sf::RenderStates) const ;
	virtual void draw(sf::RenderTarget &) const;

	void movementHandler(const sf::RenderWindow &);
};

