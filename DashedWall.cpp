#include "DashedWall.h"

// Constructor
	DashedWall::DashedWall(int x, int y) 
	{
		std::cout << "Inside DashedWall's Constructor!" << std::endl;
		mIsSolid = false;

		mSolidWall.setSize(sf::Vector2f(600,30));
	}
// Destructor
	DashedWall::~DashedWall()
	{
		std::cout << "Inside DashedWall's Destructor!" << std::endl;
	}

// Setters
	void DashedWall::setXPos(const int newX)
	{
		mXPos = newX;
	}

	void DashedWall::setyPos(const int newY)
	{
		mYPos = newY;
	}
	
	void DashedWall::setSolid(bool isSolid)
	{
		mIsSolid = isSolid;
	}

// Helper functions
	void DashedWall::createDashedArray()
	{
		int i;

		for (i = 0; i < 8; i++)
		{
			
			mDashedWall[i].setPosition(sf::Vector2f((mXPos + ((i*50)+(i*30))), mYPos));
			mDashedWall[i].setSize(sf::Vector2f(50, 30));
		}
	}

// Public Functions
	void DashedWall::drawWall(sf::RenderWindow &window)
	{
		int i;

		createDashedArray(); // Calls helper function

		for (i = 0; i < 8; i++)
		{
			window.draw(mDashedWall[i]);
		}

		
	}