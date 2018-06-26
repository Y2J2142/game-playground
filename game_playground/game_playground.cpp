#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gaem");
	Player player(sf::Vector2i(window.getSize().x/2, window.getSize().y/2), 5, 100, "../sprites/Knight.png");
	while(window.isOpen())
	{ 
		window.clear(sf::Color::Green);
		player.draw(window);
		window.display();
	
	}

    return 0;
}

