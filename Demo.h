// This code expands on the tutorial code provided at:
// http://www.sfml-dev.org/tutorials/2.3/start-vc.php

#include <SFML/Graphics.hpp>

int SFMLDemo();

int SFMLDemo()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
	sf::CircleShape shape(100.f);
	sf::CircleShape shape2(20);
	shape.setFillColor(sf::Color::Green);
	shape2.setFillColor(sf::Color::Magenta);

	sf::RectangleShape paddle(sf::Vector2f(10, 50));
	paddle.setFillColor(sf::Color::Red);

	int i = 0;
	while (window.isOpen())
	{
		sf::Event event;

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
					paddle.setPosition(4, 4 + (--i));
				}
				if (event.key.code == sf::Keyboard::S) // move down
				{
					paddle.setPosition(4, 4 + (++i));
				}
			}
		}

		window.clear();

		/*	if (i > 200)
		{
		i = 0;
		}
		i += 2;
		shape2.setPosition(4 + i, 200);
		window.draw(shape);
		window.draw(shape2);*/
		window.draw(paddle); // draw the paddle in the new position

		window.display();


	}

	return 0;
}