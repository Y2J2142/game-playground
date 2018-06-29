#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class TileMap : public sf::Drawable, public sf::Transformable
{
	sf::VertexArray vertexArray;
	sf::Texture tileset;
	sf::Vector2u tileSize;
	std::vector<std::vector<int>> level;

public:
	TileMap();
	~TileMap();

	bool load(const std::string & tileMapPath, std::vector<std::vector<int>> level);
	void draw(sf::RenderTarget&, sf::RenderStates)const;

};

