#include "AppWrapper.h"

AppWrapper::AppWrapper() // Constructor
{
	createGameBox();
}

void AppWrapper::runGame()
{
	sf::RenderWindow window(sf::VideoMode(840, 1450), "Totally awesome game!");

	while (window.isOpen())
	{
		window.draw(mBox[0]);
		window.draw(mBox[1]);
		window.draw(mBox[2]);
		window.draw(mBox[3]);

		window.display();
	}
}

void AppWrapper::createGameBox()
{
	// Need to add this code. Creating a dashed line isn't super easy
}