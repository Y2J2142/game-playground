#pragma once
#include <SFML/Graphics.hpp>
#include "Weapon.h"
class Character : public sf::Drawable
{
protected:
	enum direction { UP, DOWN, LEFT, RIGHT };
public:

	int health;
	float movespeed;
	bool isMoving;
	float distanceTraveled;
	
	direction dir;

	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite sprite;
	Weapon* weapon;

	Character();
	~Character();
	virtual void update(sf::RenderWindow&, sf::RenderTarget&, sf::Time) =0;
	void move(direction dir);
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	void draw(sf::RenderTarget &) const;
};

