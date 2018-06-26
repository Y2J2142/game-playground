#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TileMap.h"
#include <iostream>
int main()
{
	constexpr const int level[] =
	{
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1
	};
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gaem");
	sf::Event event;
	Player player(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), 5, 100, "../sprites/Knight.png");
	window.setFramerateLimit(60);
	TileMap map;
	if (!map.load("../tileset/tileset.png", sf::Vector2u(32, 32), level, 16, 8)) return 1;

	while (window.isOpen())
	{
		window.clear();
		window.setView(sf::View(player.pos, static_cast<sf::Vector2f>(window.getSize())));
		window.draw(map);
		window.draw(player);	
		player.movementHandler(window);
		window.display();

	}

	return 0;
}

