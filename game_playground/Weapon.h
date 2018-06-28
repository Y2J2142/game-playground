#pragma once
#include <SFML/Graphics.hpp>
#include <Thor/Animations.hpp>
#include "Character.h"
class Weapon : sf::Drawable
{
public:
	float damage;
	float range;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock attackSpeedTimer;
	thor::Animator<sf::Sprite, std::string> animator;
	thor::FrameAnimation attackAnimation;
	sf::Vector2i offset;
	


	virtual void attack() = 0;
	void update(sf::RenderWindow&, sf::RenderTarget&, const Character &, sf::Time);
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	void draw(sf::RenderTarget &) const;
	Weapon();
	~Weapon();

};

