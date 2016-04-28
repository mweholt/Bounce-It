#include "Ball.h"

// Constructor
Ball::Ball() : CircleShape(15.f)
{
	this->setFillColor(sf::Color::Red);
	this->setOutlineColor(sf::Color::Blue);
	this->setOutlineThickness(8);

	mBallAngle = 0;
	mBallSpeed = 10.f;
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

