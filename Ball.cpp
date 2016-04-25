#include "Ball.h"

Ball::Ball() : CircleShape()
{
	CircleShape gameBall(50.f); //creating the circle shape called Ball
	gameBall.setFillColor(sf::Color::Red); //setting the ball color to red
}

Ball::~Ball()
{
	//ball destructor
}