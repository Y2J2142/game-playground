#include "Character.h"



Character::Character()
{
}


Character::~Character()
{
}


void Character::draw(sf::RenderTarget & renderTarget, sf::RenderStates states) const
{
	renderTarget.draw(this->sprite, states);

}

void Character::draw(sf::RenderTarget & renderTarget) const
{
	renderTarget.draw(this->sprite);
}