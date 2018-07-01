#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TileMap.h"
#include <iostream>
int main()
{
	sf::Clock clock;
	std::vector<std::vector<int>> level =
	{
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 4, 0, 0, 1, 0, 0, 0, 2, 0, 4 },
		{ 4, 0, 1, 1, 1, 1, 0, 0, 0, 4 },
		{ 4, 0, 1, 0, 0, 1, 1, 1, 1, 4 },
		{ 4, 0, 1, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 1, 0, 2, 3, 3, 3, 3, 4 },
		{ 4, 0, 1, 0, 0, 3, 0, 0, 2, 4 },
		{ 4, 1, 1, 0, 3, 3, 2, 2, 2, 4 },
		{ 4, 1, 0, 0, 3, 0, 2, 2, 2, 4 },
		{ 4, 1, 0, 3, 3, 0, 0, 2, 0, 4 },
		{ 4, 1, 0, 3, 0, 0, 0, 0, 0, 4 },
		{ 4, 1, 0, 3, 1, 1, 1, 1, 0, 4 },
		{ 4, 1, 2, 3 ,1, 1, 1, 1, 0, 4 },
		{ 4, 1, 0, 3, 1, 1, 1, 1, 1, 4 },
		{ 4, 1, 0, 3, 0, 2, 1, 1, 1, 4 },
		{ 4, 1, 0, 3, 0, 0, 2, 1, 1, 4 },
		{ 4, 1, 0, 3, 0, 0, 0, 1, 1, 4 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 }
	};
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gaem");
	Player player(sf::Vector2f(192, 192), 5, 100, "../sprites/Knight.png");
	window.setFramerateLimit(60);
	TileMap map;
	if (!map.load("../tileset/tileset.png", level)) return 1;

	while (window.isOpen())
	{
		window.clear();
		window.setView(sf::View(player.pos, static_cast<sf::Vector2f>(window.getSize())));
		window.draw(map);
		map.restrictMovement(player);
		player.update(window, window, clock.restart());
		
		
		window.display();

	}

	return 0;
}

