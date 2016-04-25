#include "Wall.h"

// Constructor
Wall::Wall() 
{
	mSolid = true;
}

// Destructor
Wall::~Wall()
{
	std::cout << "Wall's destructor!" << std::endl;
}

// Changes whether the line is solid
void Wall::setSolid(bool isSolid)
{
	mSolid = isSolid;
}

// Do not call.
unsigned int Wall::getPointCount() const
{
	return 0;
}

// Do not call.
sf::Vector2f Wall::getPoint(unsigned int index) const
{
	return sf::Vector2f();
}