#include "MeleeWeapon.h"



MeleeWeapon::MeleeWeapon(float damage, float range, float arc, std::string textureFilePath)
{
	this->damage = damage;
	this->range = range;
	this->arc = arc;
	this->texture.loadFromFile(textureFilePath);
	sprite.setTexture(this->texture);
	sprite.setScale(2, 5);
	auto[textureSizeX, textureSizeY] = texture.getSize();
	sprite.setOrigin(textureSizeX/2, textureSizeY);


}


MeleeWeapon::~MeleeWeapon()
{
}


void MeleeWeapon::draw(sf::RenderTarget & renderTarget, sf::RenderStates states) const 
{
	renderTarget.draw(this->sprite, states);
}

void MeleeWeapon::attack() const
{
}

void MeleeWeapon::update(const Character & holder)
{
	auto pos = holder.pos;
	auto rotation = holder.sprite.getRotation();
	
	sf::Transform t;
	t.rotate(rotation, pos).translate(10, -10);
	auto newPos = t.transformPoint(pos);
	this->sprite.setPosition(newPos);
	this->sprite.setRotation(rotation);

}