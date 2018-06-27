#pragma once
#include "Weapon.h"
#include <Thor/Animations.hpp>
class MeleeWeapon : public Weapon
{
public:
	float arc;
	thor::Animator<sf::Sprite, std::string> animator;
	thor::FrameAnimation attackAnimation;

	MeleeWeapon() = delete;
	MeleeWeapon(float damage, float range, float arc, std::string textureFilePath);
	~MeleeWeapon();
	void update(sf::RenderWindow&, sf::RenderTarget&, const Character &, sf::Time) override;
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	void draw(sf::RenderTarget&) const override;
	void attack() override;

};

