#pragma once
#include <SFML/Graphics.hpp>
class Character : public sf::Drawable
{
public:

	int health;
	float movespeed;
	sf::Vector2f pos;

	sf::Texture texture;
	sf::Sprite sprite;


	Character();
	~Character();
	virtual void update(sf::RenderWindow&, sf::RenderTarget&, sf::Time) =0;

	virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
	virtual void draw(sf::RenderTarget &) const;
};

