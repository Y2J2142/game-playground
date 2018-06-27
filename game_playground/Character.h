#pragma once
#include <SFML/Graphics.hpp>
class Character
{
public:

	int health;
	float movespeed;
	sf::Vector2f pos;

	sf::Texture texture;
	sf::Sprite sprite;


	Character();
	~Character();
};

