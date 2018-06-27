#pragma once
#include "Weapon.h"
#include <Thor/Animations.hpp>
class MeleeWeapon : public Weapon
{
public:

	

	MeleeWeapon() = delete;
	MeleeWeapon(const float damage, const float range, const unsigned int frameSize, const sf::Vector2i, std::string textureFilePath);
	~MeleeWeapon();
	void attack() override;

};

