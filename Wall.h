#include <SFML/Graphics.hpp>
#include <iostream>

class Wall : sf::RectangleShape
{
	public:
		Wall(sf::Vector2f size);
		~Wall();

	private:
		bool mSolid;
};