#include "TileMap.h"
#include <iostream>
TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}


bool TileMap::load(const std::string & tileMapPath, sf::Vector2u tileSize, std::vector<std::vector<int>> level)
{
	if (!this->tileset.loadFromFile(tileMapPath)) return false;
	
	auto width = level.size();
	auto height = level[0].size();

	vertexArray.setPrimitiveType(sf::Quads);
	vertexArray.resize(width * height * 4);

	for(auto i = 0; i < width; ++i)
		for (auto j = 0; j < height; ++j)
		{
			
			const int tileNumber = level[i][j];
			const int tu = tileNumber % (this->tileset.getSize().x / tileSize.x);
			const int tv = tileNumber / (this->tileset.getSize().x / tileSize.x);
			sf::Vertex *quad = &vertexArray[(i + j * width) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
	return true;
}


void TileMap::draw(sf::RenderTarget & renderTarget, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &tileset;

	renderTarget.draw(vertexArray, states);
}

//void TileMap::draw(sf::RenderTarget& renderTarget)const
//{
//	renderTarget.draw(vertexArray);
//}