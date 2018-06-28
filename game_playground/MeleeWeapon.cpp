#include "MeleeWeapon.h"



MeleeWeapon::MeleeWeapon(const float damage, const float range, const unsigned int frameSize, const sf::Vector2i offset, std::string textureFilePath)
{
	this->damage = damage;
	this->range = range;
	this->texture.loadFromFile(textureFilePath);
	sprite.setTexture(this->texture);
	sprite.setTextureRect(sf::IntRect(0, 0, frameSize, texture.getSize().y));
	this->offset = offset;
	auto[textureSizeX, textureSizeY] = texture.getSize();
	sprite.setOrigin(16, textureSizeY);

	animator.addAnimation("attack", [](sf::Sprite & sprite, float progress) 
	{
		//lagrange interpolation <3
		sprite.setScale(1, -4 * (progress*progress) + 4 * progress + 1);
	}, sf::seconds(1.0f));

}


MeleeWeapon::~MeleeWeapon()
{
}




void MeleeWeapon::attack()
{
	if (!animator.isPlayingAnimation())
		animator.playAnimation("attack");
}

