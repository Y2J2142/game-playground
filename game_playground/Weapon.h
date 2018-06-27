#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
class Weapon : sf::Drawable
{
public:
	float damage;
	float range;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock attackSpeedTimer;
	


	virtual void attack() = 0;
	virtual void update(sf::RenderWindow&, sf::RenderTarget&, const Character &, sf::Time) = 0;
	virtual void draw(sf::RenderTarget &, sf::RenderStates) const = 0;
	virtual void draw(sf::RenderTarget &) const = 0;
	Weapon();
	virtual ~Weapon() = 0;

};

