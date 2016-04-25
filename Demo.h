// This code expands on the tutorial code provided at:
// http://www.sfml-dev.org/tutorials/2.3/start-vc.php

#include <SFML/Graphics.hpp>


//blsah

int SFMLDemo();

int SFMLDemo()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
	sf::CircleShape gameBall(100.f);
	gameBall.setFillColor(sf::Color::Green);
	gameBall.setOutlineColor(sf::Color::Blue);
	gameBall.setOutlineThickness(20);

	sf::RectangleShape paddle(sf::Vector2f(10, 50));
\

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
					gameBall.setPosition(4, 4 + (--i));
				}
				if (event.key.code == sf::Keyboard::S) // move down
				{
					gameBall.setPosition(4, 4 + (++i));
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