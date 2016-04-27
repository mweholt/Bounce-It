#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Ball : public sf::CircleShape
{
public:
	Ball(); //constructor
	~Ball(); //destructor

	void setSpeed(const float newSpeed);
	void setAngle(const float newAngle);
	float getSpeed() const;
	float getAngle() const;

private:
	float mBallSpeed;
	float mBallAngle;
};