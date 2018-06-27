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
	for (int i = 0; i < (textureSizeX / frameSize); ++i)
	{
		attackAnimation.addFrame(1.0f, sf::IntRect(i * frameSize, 0, frameSize, textureSizeY));
	}
	attackAnimation.addFrame(1.0f, sf::IntRect(0, 0, frameSize, textureSizeY));
	attackAnimation(sprite, 0.0f);
	animator.addAnimation("attack", attackAnimation, sf::seconds(0.05f));

}


MeleeWeapon::~MeleeWeapon()
{
}




void MeleeWeapon::attack()
{
	if (!animator.isPlayingAnimation())
		animator.playAnimation("attack");
}

