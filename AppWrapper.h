#pragma once

#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "Ball.h"

// Manages the game board and gameplay of the game
class AppWrapper
{
	
	public:
		AppWrapper(); // Constructor calls createGameBox()

		void runGame();

	private:
		Wall mBox[4];
		Ball mBall;
		int mScore;

		void createGameBox();
};
