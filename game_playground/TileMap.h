#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Character.h"

class TileMap : public sf::Drawable, public sf::Transformable
{
	sf::VertexArray vertexArray;
	sf::Texture tileset;
	sf::Vector2u tileSize;
	std::vector<std::vector<int>> level;
	std::vector<std::vector<bool>> collisionLayer;
	static constexpr int collisionTiles[] = { 1, 2, 4 };
public:
	TileMap();
	~TileMap();

	bool load(const std::string & tileMapPath, std::vector<std::vector<int>> level);
	void draw(sf::RenderTarget&, sf::RenderStates)const;
	void setCollisionLayer();
	void restrictMovement(Character &);
};

