#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gaem");
	sf::Event event;
	Player player(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), 5, 100, "../sprites/Knight.png");
	sf::Texture mapTestText;
	mapTestText.loadFromFile("../tileset/map.jpg");
	sf::Sprite sprite;
	sprite.setTexture(mapTestText);
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		window.clear();
		window.draw(sprite);
		window.setView(sf::View(player.pos, static_cast<sf::Vector2f>(window.getSize())));
		player.draw(window);
		player.movementHandler(window);
		window.display();

	}

	return 0;
}

