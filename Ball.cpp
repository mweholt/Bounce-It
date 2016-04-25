#include "Ball.h"

Ball::Ball() : CircleShape(100.f)
{
	this->setFillColor(sf::Color::Red);
	this->setOutlineColor(sf::Color::Blue);
	this->setOutlineThickness(10);
}

Ball::~Ball()
{
	//ball destructor
}