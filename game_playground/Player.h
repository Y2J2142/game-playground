#pragma once
#include <SFML/Graphics.hpp>
class Player : public sf::Drawable
{
public:

	int health;
	float movespeed;
	sf::Vector2f pos;

	sf::Texture texture;
	sf::Sprite sprite;

	Player() = delete;
	Player(sf::Vector2f, float movespeed, int health, std::string texturePath);
	~Player();

	virtual void draw(sf::RenderTarget &, sf::RenderStates) const ;
	virtual void draw(sf::RenderTarget &) const;
};

