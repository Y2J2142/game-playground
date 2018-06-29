#pragma once
#include <SFML/Graphics.hpp>
#include "Weapon.h"
class Character : public sf::Drawable
{
protected:
	enum Direction { UP, DOWN, LEFT, RIGHT };
public:

	int health;
	float movespeed;
	bool isMoving;
	float distanceTraveled;
	
	Direction dir;

	sf::Vector2f pos;
	sf::Vector2i tilePos;
	sf::Texture texture;
	sf::Sprite sprite;
	Weapon* weapon;

	Character();
	~Character();
	virtual void movementHandler() = 0;
	virtual void movementHandler(const Character &) = 0;
	void move(Direction dir);
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	void draw(sf::RenderTarget &) const;
};

