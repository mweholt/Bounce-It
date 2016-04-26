#include "AppWrapper.h"

// Constructor
AppWrapper::AppWrapper() 
{
	mNumPlayers = 1;
	mScore = 0;
	createGameBox();
	mBall.setPosition(420, 725); //setting initial game ball position to center of game board
}

// Main gameplay
void AppWrapper::runGame()
{
	// Create a window
	sf::RenderWindow window(sf::VideoMode(840, 1450), "PA9 Game!");
	window.setFramerateLimit(60); // Sets framerate to 60 to lower CPU usage

	while (window.isOpen())
	{
		window.clear(); // Clears previous frame

		sf::Event event;
		while (window.pollEvent(event)) // If something happens, go into the look
		{

			// Close window if X'd out
			if (event.type == sf::Event::Closed) window.close();

			// If a key was pressed
			if (event.type == sf::Event::KeyPressed)
			{
				// If the key pressed was space
				if (event.key.code == sf::Keyboard::Space)
				{
					// Switch the bottom wall to solid or dashed
					if (mDashedWall[1].getSolid() == true) 
					{
						mDashedWall[1].setSolid(false);
						cout << "Changing bottom line to dashed." << endl;
					}
					else 
					{
						mDashedWall[1].setSolid(true);
						cout << "Changing bottom line to solid." << endl;
					}
				}
			}
		}
		// Updates the full game box and displays	
		// ball movement
		mBall.setPosition(mBall.getPosition().x + 1, mBall.getPosition().y); //moving the gameball by 1 in the x direction
		window.draw(mBall);

		printGameBox(window);
		window.display();
		
	}
}

// Creates the gamebox and sets positions
void AppWrapper::createGameBox()
{
	// Left and right sides
	mSolidWall[0].setPosition(sf::Vector2f(100,100));
	mSolidWall[1].setPosition(sf::Vector2f(700,100));
	
	// Top side
	mDashedWall[0].setXPos(110);
	mDashedWall[0].setyPos(100);

	// Right side
	mDashedWall[1].setXPos(110);
	mDashedWall[1].setyPos(1270);

	// Sets top to solid if player is only one
	if (mNumPlayers == 1) mDashedWall[0].setSolid(true);
}

// Prints all 4 walls
void AppWrapper::printGameBox(sf::RenderWindow &window)
{
	// Left and right sides
	window.draw(mSolidWall[0]);
	window.draw(mSolidWall[1]);

	// Top and bottom sides
	mDashedWall[0].drawWall(window);
	mDashedWall[1].drawWall(window);
}