#include "Wall.h"

Wall::Wall(sf::Vector2f size) : RectangleShape(size)
{
	mSolid = false;
}

Wall::~Wall()
{
	std::cout << "Wall's destructor!" << std::endl;
}