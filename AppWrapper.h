#pragma once

#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "Ball.h"

// Manages the game board and gameplay of the game
class AppWrapper
{
	
	public:
		void runGame();


	private:
		//Wall mBox[4];
		Ball mBall;
		int mScore;
};
