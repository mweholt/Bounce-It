// This code expands on the tutorial code provided at:
// http://www.sfml-dev.org/tutorials/2.3/start-vc.php

#include <SFML/Graphics.hpp>
#include "Ball.h"


//blsah

int SFMLDemo();

int SFMLDemo()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

	sf::RectangleShape paddle(sf::Vector2f(10, 50));

	paddle.setFillColor(sf::Color::Red);
	
	Ball gameBall;

	int i = 0;
	while (window.isOpen())
	{
		sf::Event event;

		window.draw(gameBall);

		//window.draw(s);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				// move the paddle up and down depending on
				// which key is pressed
				if (event.key.code == sf::Keyboard::W) // move up
				{
					gameBall.setPosition(10.f, 10.f + (--i));
				}
				if (event.key.code == sf::Keyboard::S) // move down
				{
					gameBall.setPosition(10.f, 10.f + (++i));
				}
			}
		}

		window.clear();

\
		window.draw(gameBall); // draw the paddle in the new position\*
		
		

		window.display();


	}

	return 0;
}