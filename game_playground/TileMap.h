#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class TileMap : public sf::Drawable, public sf::Transformable
{
	sf::VertexArray vertexArray;
	sf::Texture tileset;


public:
	TileMap();
	~TileMap();

	bool load(const std::string & tileMapPath, sf::Vector2u tileSize, std::vector<std::vector<int>> level);
	void draw(sf::RenderTarget&, sf::RenderStates)const;
	//void draw(sf::RenderTarget&)const;

};

