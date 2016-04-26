#include "DashedWall.h"

// Constructor
	DashedWall::DashedWall(int x, int y) 
	{
		std::cout << "Inside DashedWall's Constructor!" << std::endl;
		mIsSolid = true;

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
		createDashedArray(); // Calls helper function to update array
		mSolidWall.setPosition(sf::Vector2f(mXPos, mYPos));
	}

	void DashedWall::setyPos(const int newY)
	{
		mYPos = newY;
		createDashedArray(); // Calls helper function to update array
		mSolidWall.setPosition(sf::Vector2f(mXPos, mYPos));
	}
	
	void DashedWall::setSolid(bool isSolid)
	{
		mIsSolid = isSolid;

	}

	bool DashedWall::getSolid() const
	{
		return mIsSolid;
	}

// Helper functions
	void DashedWall::createDashedArray()
	{
		int i;

		// Runs through array and sets the sizes and position based on member variables
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

		if (!mIsSolid) // Checks if the wall is not solid
		{ 
			
			for (i = 0; i < 8; i++)
			{
				window.draw(mDashedWall[i]);
			}
		}
		else // If the wall IS solid
		{
			window.draw(mSolidWall);
		}
	}