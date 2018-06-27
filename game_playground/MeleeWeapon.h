#pragma once
#include "Weapon.h"
class MeleeWeapon : public Weapon
{
	float arc;
public:
	MeleeWeapon() = delete;
	MeleeWeapon(float damage, float range, float arc, std::string textureFilePath);
	~MeleeWeapon();
	void update(const Character &);
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	void attack() const override;

};

