#include "Ball.h"

// Constructor
Ball::Ball() : CircleShape(15.f)
{
	this->setFillColor(sf::Color::Red);
	this->setOutlineColor(sf::Color::Blue);
	this->setOutlineThickness(5);

	mBallAngle = 0;
	mBallSpeed = 6.f;
}

// Destructor
Ball::~Ball()
{
	std::cout << "Inside Ball's destructor!" << std::endl;
}

void Ball::setSpeed(const float newSpeed)
{
	mBallSpeed = newSpeed;
}

void Ball::setAngle(const float newAngle)
{
	mBallAngle = newAngle;
}

float Ball::getSpeed() const
{
	return mBallSpeed;
}
float Ball::getAngle() const
{
	return mBallAngle;
}

