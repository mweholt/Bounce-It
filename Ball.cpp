#include "Ball.h"

// Constructor
Ball::Ball() : CircleShape(10.f)
{
	this->setFillColor(sf::Color::Red);
	this->setOutlineColor(sf::Color::Blue);
	this->setOutlineThickness(5);

	mBallAngle = 400.f;
	mBallSpeed = 0.f;
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

