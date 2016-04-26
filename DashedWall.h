#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "sfLine.h"

// The dashed wall class defaults to dashed, but will turn solid if mIsSolid is true.
class DashedWall : public sf::RectangleShape
{
public:
	DashedWall(int x = 0, int y = 0);
	~DashedWall();

	// Must pass in the sf::RenderWindow from main
	void drawWall(sf::RenderWindow &window);

	// Setters
	void setXPos (const int newX);
	void setyPos (const int newY);
	void setSolid(bool isSolid);

private:
	bool mIsSolid;
	int mXPos, mYPos;
	sf::RectangleShape mDashedWall[8];
	sf::RectangleShape mSolidWall;

	// Private memver functions
	void createDashedArray();
};
