#pragma once

#include <SFML/Graphics.hpp>
#include "DashedWall.h"
#include "SolidWall.h"
#include "Ball.h"

// Manages the game board and gameplay of the game
class AppWrapper
{
	
	public:
		AppWrapper(); // Constructor calls createGameBox()

		void runGame();

	private:
		DashedWall mDashedWall[2];
		SolidWall mSolidWall[2];
		Ball mBall;

		int mScore;

		void createGameBox();
		void printGameBox(sf::RenderWindow &window);
};
