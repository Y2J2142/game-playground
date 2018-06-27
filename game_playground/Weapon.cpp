#include "Weapon.h"



Weapon::Weapon()
{
}


Weapon::~Weapon()
{
}
void Weapon::draw(sf::RenderTarget & renderTarget, sf::RenderStates states) const
{
	renderTarget.draw(this->sprite, states);
}

void Weapon::draw(sf::RenderTarget & renderTarget) const
{
	renderTarget.draw(this->sprite);
}

void Weapon::update(sf::RenderWindow & window, sf::RenderTarget & output, const Character & holder, sf::Time time)
{
	animator.update(time);
	animator.animate(sprite);
	auto pos = holder.pos;
	auto rotation = holder.sprite.getRotation();

	sf::Transform t;
	t.rotate(rotation, pos).translate(static_cast<sf::Vector2f>(offset));
	auto newPos = t.transformPoint(pos);
	this->sprite.setPosition(newPos);
	this->sprite.setRotation(rotation);
	draw(output);
}