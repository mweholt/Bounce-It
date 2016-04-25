#include "AppWrapper.h"

void AppWrapper::runGame()
{
	sf::RenderWindow window(sf::VideoMode(600, 1000), "Totally awesome!");


	while (window.isOpen())
	{
		sf::Event event;

		sf::Text text;
		//atext.setFont();
		text.setString("HelloWorld");
		text.setCharacterSize(20);
		text.setStyle(sf::Text::Bold);
		text.setColor(sf::Color::White);
		text.setPosition(0, 0);
		window.draw(text);
		window.clear(sf::Color::Green);
		window.display();

		window.clear();
	}
}
