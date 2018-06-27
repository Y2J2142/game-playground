#pragma once
#include "Weapon.h"
#include <Thor/Animations.hpp>
class MeleeWeapon : public Weapon
{
public:

	thor::Animator<sf::Sprite, std::string> animator;
	thor::FrameAnimation attackAnimation;
	sf::Vector2i offset;

	MeleeWeapon() = delete;
	MeleeWeapon(const float damage, const float range, const unsigned int frameSize, const sf::Vector2i, std::string textureFilePath);
	~MeleeWeapon();
	void update(sf::RenderWindow&, sf::RenderTarget&, const Character &, sf::Time) override;
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	void draw(sf::RenderTarget&) const override;
	void attack() override;

};

