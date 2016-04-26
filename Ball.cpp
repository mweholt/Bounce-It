#include "Ball.h"

// Constructor
Ball::Ball() : CircleShape(20.f)
{
	this->setFillColor(sf::Color::Red);
	this->setOutlineColor(sf::Color::Blue);
	this->setOutlineThickness(5);
}

// Destructor
Ball::~Ball()
{
	std::cout << "Inside Ball's destructor!" << std::endl;
}

