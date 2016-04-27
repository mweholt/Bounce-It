#include "DashedWall.h"

// Constructor
	DashedWall::DashedWall(int x, int y) 
	{
		std::cout << "Inside DashedWall's Constructor!" << std::endl;
		mIsSolid = false; // Defaults to a solid wall

		// The solid wall only needs one line, so might as well do it here
		mSolidWall.setSize(sf::Vector2f(600,30)); 
		mSolidWall.setFillColor((sf::Color(52, 152, 219, 255)));
	}
// Destructor
	DashedWall::~DashedWall()
	{
		std::cout << "Inside DashedWall's Destructor!" << std::endl;
	}

// Setters
	void DashedWall::setXPos(const int newX)
	{
		mXPos = newX; // Updates private member variable
		createDashedArray(); // Calls helper function to update dashed array
		mSolidWall.setPosition(sf::Vector2f(mXPos, mYPos)); // Updates solid line
	}

	void DashedWall::setyPos(const int newY)
	{
		mYPos = newY;
		createDashedArray(); // Calls helper function to update dashed array
		mSolidWall.setPosition(sf::Vector2f(mXPos, mYPos)); // Updates solid line
	}
	
	void DashedWall::setSolid(bool isSolid)
	{
		// Sets the member variable
		mIsSolid = isSolid;
	}

	bool DashedWall::getSolid() const
	{
		// Returns member variable
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
			mDashedWall[i].setFillColor(sf::Color(52, 152, 219, 255));
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
				// Draws each dashed line
				window.draw(mDashedWall[i]);
			}
		}
		else // If the wall IS solid
		{
			window.draw(mSolidWall);
		}
	}