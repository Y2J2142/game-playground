#include "TileMap.h"
#include <iostream>
#include <algorithm>
TileMap::TileMap()
{
	tileSize = sf::Vector2u(128, 128);
}


TileMap::~TileMap()
{
}


bool TileMap::load(const std::string & tileMapPath, std::vector<std::vector<int>> level)
{
	this->level.clear();
	this->level = level;
	if (!this->tileset.loadFromFile(tileMapPath)) return false;
	this->collisionLayer.resize(this->level.size());
	setCollisionLayer();
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

void TileMap::setCollisionLayer()
{
	collisionLayer.clear();
	
	for (auto i = 0; i < level.size(); ++i)
		collisionLayer.emplace_back(level[0].size());
	auto size = this->level[0].size();
	
	for (auto && c : collisionLayer)
		fill(std::begin(c), std::end(c), false);

	for(auto i = 0; i < collisionLayer.size(); ++i)
		for (auto j = 0; j < collisionLayer[0].size(); ++j)
		{
			for (const auto tile : TileMap::collisionTiles)
			{
				if (level[i][j] == tile)
					collisionLayer[i][j] = true;
			}
		}
}

void TileMap::restrictMovement(Character & character)
{
	auto[x, y] = character.tilePos;
	std::fill(std::begin(character.canMove), std::end(character.canMove), false);
	if (collisionLayer[x - 1][y])
		character.canMove[Character::Direction::LEFT] = false;
	else
		character.canMove[Character::Direction::LEFT] = true;
	if (collisionLayer[x + 1][y])
		character.canMove[Character::Direction::RIGHT]= false;
	else
		character.canMove[Character::Direction::RIGHT] = true;
	if (collisionLayer[x][y - 1])
		character.canMove[Character::Direction::UP] = false;
	else
		character.canMove[Character::Direction::UP] = true;
	if (collisionLayer[x][y + 1])
		character.canMove[Character::Direction::DOWN] = false;
	else
		character.canMove[Character::Direction::DOWN] = true;

}
//void TileMap::draw(sf::RenderTarget& renderTarget)const
//{
//	renderTarget.draw(vertexArray);
//}