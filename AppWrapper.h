#pragma once

#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "Ball.h"

class AppWrapper
{
	
	public:
		void runGame();


	private:
		Wall mBox[4];
		Ball mBall;
		int counter;
};
