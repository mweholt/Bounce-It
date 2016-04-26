#include "AppWrapper.h"

// Constructor
AppWrapper::AppWrapper() 
{
	createGameBox();
}

// Main gameplay
void AppWrapper::runGame()
{
	// Create a window
	sf::RenderWindow window(sf::VideoMode(840, 1450), "Totally awesome game!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) // If something happens, go into the look
		{
			// Close window if X'd out
			if (event.type == sf::Event::Closed) window.close(); 
			
			else
			{
				printGameBox(window);
				window.display();
			}
		}
	}
}

// Creates the gamebox and sets positions
void AppWrapper::createGameBox()
{
	mSolidWall[0].setPosition(sf::Vector2f(100,100));
	mSolidWall[1].setPosition(sf::Vector2f(700,100));
	
	mDashedWall[0].setXPos(110);
	mDashedWall[0].setyPos(100);

	mDashedWall[1].setXPos(110);
	mDashedWall[1].setyPos(1270);
}

// Prints all 4 walls
void AppWrapper::printGameBox(sf::RenderWindow &window)
{
	window.draw(mSolidWall[0]);
	window.draw(mSolidWall[1]);
	mDashedWall[0].drawWall(window);
	mDashedWall[1].drawWall(window);
}