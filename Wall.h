#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <iostream>

class Wall : public sf::Shape
{
	public:
		Wall();
		~Wall();

		//Required functions for Shape derived class. DO NOT CALL.
		unsigned int getPointCount() const;
		sf::Vector2f getPoint(unsigned int index) const;


	private:
		bool mSolid;

		// Private function because only top and botton can be un-solid
		void setSolid(bool isSolid);
};