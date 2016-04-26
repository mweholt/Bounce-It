#include "SolidWall.h"

SolidWall::SolidWall() : RectangleShape(sf::Vector2f(30,1200))
{
	std::cout << "Inside SolidWall's Constructor!" << std::endl;
}


SolidWall::~SolidWall()
{
	std::cout << "Inside SolidWall's Destructor!" << std::endl;
}
