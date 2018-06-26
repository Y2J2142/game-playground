#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gaem");
	sf::Event event;
	Player player(sf::Vector2f(window.getSize().x/2, window.getSize().y/2), 5, 100, "../sprites/Knight.png");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{ 
		window.clear(sf::Color::Green);
		player.draw(window);
		player.movementHandler();
		window.display();
	
	}

    return 0;
}

