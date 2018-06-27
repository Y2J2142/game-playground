#pragma once
#include <SFML/Graphics.hpp>
class Weapon : sf::Drawable
{
protected:
	float damage;
	float range;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock attackSpeedTimer;
	
public:

	virtual void attack() = 0;
	virtual void draw(sf::RenderTarget &, sf::RenderStates) = 0;
	Weapon();
	virtual ~Weapon() = 0;

};

