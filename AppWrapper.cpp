#include "AppWrapper.h"

// Constructor
AppWrapper::AppWrapper() 
{
	mNumPlayers = 1;
	mScore = 0;
	createGameBox();
}

// Main gameplay
void AppWrapper::runGame()
{
	bool hasWallTimePassed = true;
	bool isStart = true;

	std::srand(static_cast<unsigned int>(std::time(NULL)));

	// Create a window
	sf::RenderWindow window(sf::VideoMode(840, 1450), "PA9 Game!");
	window.setFramerateLimit(60); // Sets framerate to 60 to lower CPU usage

	// Set wall colors
	mSolidWall[0].setFillColor((sf::Color(52, 152, 219, 255)));
	mSolidWall[1].setFillColor((sf::Color(52, 152, 219, 255)));
	mDashedWall[0].setFillColor((sf::Color(52, 152, 219, 255)));

	// Create text for score title
	sf::Font font;
	font.loadFromFile("sansation.ttf");
	sf::Text scoreTitle("SCORE:", font);
	scoreTitle.setCharacterSize(100);
	scoreTitle.setStyle(sf::Text::Bold);
	scoreTitle.setColor(sf::Color(52, 152, 219, 100));
	scoreTitle.move(scoreTitle.getPosition().x + 235, 500);

	// Create text for score
	sf::Text score(std::to_string(mScore), font);
	score.setCharacterSize(200);
	score.setStyle(sf::Text::Bold);
	score.setColor(sf::Color(52, 152, 219, 100));
	score.move(score.getPosition().x + 345, 600);

	// Set ball color
	mBall.setFillColor(sf::Color(52, 152, 219, 255));
	mBall.setOutlineColor(sf::Color(231,76,60,255));

	// Clock to keep track of how long the lower wall is solid for
	sf::Clock wallTimer;

	// Restart point
	endGame:
	mBall.setPosition(420, 725); //setting initial game ball position to center of game board

	// Set a random angle that is still pointing upwards
	mBall.setAngle((std::rand() % 180) +180 * 2 * PI / 90);
	cout << "mBall angle is " << mBall.getAngle() << endl;

	window.clear((sf::Color(236, 240, 241, 255)));
	printMenu(window,isStart);

	while (window.isOpen())
	{
		window.clear((sf::Color(236, 240, 241, 255))); // Clears previous frame
		window.draw(scoreTitle);
		window.draw(score);

		sf::Event event;
		
		//Check if 3 seconds have passed by
		if (wallTimer.getElapsedTime().asSeconds() > 0.5)
		{
			hasWallTimePassed = true;
			//cout << "3 seconds has passed." << endl;
		}

		if (window.pollEvent(event)) // If something happens, go into the loop
		{
			// Close window if X'd out
			if (event.type == sf::Event::Closed) window.close();

			// If a key was pressed
			if (event.type == sf::Event::KeyPressed)
			{
				// If the key pressed was space
				if (event.key.code == sf::Keyboard::Space)
				{
					// Only allow line to be turned to solid if 3 seconds has passed
					if (hasWallTimePassed)
					{
						wallTimer.restart(); // Reset timer

						// Switch the bottom wall to solid or dashed
						mDashedWall[1].setSolid(true);
						//cout << "Setting wall to solid." << endl;

						hasWallTimePassed = false;
					}
				}
			}

		}

		// If 1.5 seconds has passed since bar turned solid then reset
		if (hasWallTimePassed)
		{
			mDashedWall[1].setSolid(false);
		}
		
		//ball movement
		mBall.move(cos(mBall.getAngle()) * mBall.getSpeed(), sin(mBall.getAngle()) * mBall.getSpeed());

		// Check for colisions
		switch (isColision())
		{
			case 1: // Left
				mBall.setAngle(PI - mBall.getAngle() + (std::rand() % 10) * PI / 180);
				cout << "Angle is: " << mBall.getAngle() << endl;
				break;
			case 2: // Right
				mBall.setAngle(PI - mBall.getAngle() + (std::rand() % 10) * PI / 180);
				cout << "Angle is: " << mBall.getAngle() << endl;
				break;
			case 4: // Bottom
				mBall.setAngle(-mBall.getAngle());
				cout << "Angle is: " << mBall.getAngle() << endl;
				mScore++;
				score.setString(std::to_string(mScore));

				//Update score formatting
				 if (mScore == 10) score.move(-30,0);

				mBall.setSpeed(mBall.getSpeed()+2);
				cout << "Score: " << mScore << endl;
				cout << "Speed: " << mBall.getSpeed() << endl;
				break;
			case 3: // Top
				mBall.setAngle(-mBall.getAngle());
				cout << "Angle is: " << mBall.getAngle() << endl;
				break;
			case -1:
				isStart = false;
				goto endGame;
			case 0:
			default:
				break;
		}

		

		// Updates the full game box and displays	
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

int AppWrapper::isColision()
{
	//checking if the ball has hit any of the gameboard walls
	if (mBall.getPosition().x < 130.f) //meaning the ball has touched the left wall
	{
		cout << "mBall has touched left wall" << endl;
		return 1;
	}
	if (mBall.getPosition().x > 670.f) //meaning the ball has touched the right wall
	{
		cout << "mBall has touched right wall" << endl;
		return 2;
	}
	if (mBall.getPosition().y < 130.f)//meaning the ball hit the top wall
	{
		cout << "mBall has touched the top wall" << endl;
		return 3;
	}
	if (mBall.getPosition().y > 1240.f)
	{
		cout << "mBall has touched the bottom wall." << endl;
		if (mDashedWall[1].getSolid() == false)
		{
			cout << "You Lose!" << endl;
			return -1;
		}
		return 4;
	}
}

void AppWrapper::printMenu(sf::RenderWindow &window, bool isStart)
{
	// Declare and load a font
	sf::Font font;
	font.loadFromFile("sansation.ttf");

	sf::Text title("Bounce It!", font);
	title.setCharacterSize(150);
	title.setStyle(sf::Text::Bold);
	title.setColor(sf::Color(52, 152, 219, 255));
	title.move(title.getPosition().x+70,500);

	if (isStart == true)
	{
		// First time playing
		sf::Text pressSpaceStart("Press SPACE to start.", font);
		pressSpaceStart.setCharacterSize(50);
		pressSpaceStart.setStyle(sf::Text::Bold);
		pressSpaceStart.setColor(sf::Color(231, 76, 60, 255));
		pressSpaceStart.move(pressSpaceStart.getPosition().x + 170, 800);
		window.draw(pressSpaceStart);
	}
	else
	{
		// Game was lost
		sf::Text pressSpaceRestart("Press SPACE to restart.", font);
		pressSpaceRestart.setCharacterSize(50);
		pressSpaceRestart.setStyle(sf::Text::Bold);
		pressSpaceRestart.setColor(sf::Color(231, 76, 60, 255));
		pressSpaceRestart.move(pressSpaceRestart.getPosition().x + 155, 800);
		window.draw(pressSpaceRestart);
	}

	window.draw(title);
	window.display();

	sf::Event event;

	// Wait until space is hit
	while (window.isOpen())
	{
		if (window.pollEvent(event))
		{
			// If a key was pressed
			if (event.type == sf::Event::KeyPressed)
			{
				// If the key pressed was space
				if (event.key.code == sf::Keyboard::Space)
				{
					break;
				}
			}
		}
	}
}