#include <iostream>
#include "Robot.h"

Robot::Robot()
	:x_(0)
	, y_(0)
	, health_(0)
{

}

Robot::Robot(const int& x, const int& y, const int& health)
	:x_(x)
	, y_(y)
	, health_(health)
{
}

int Robot::getX() const
{
	return x_;
}

int Robot::getY() const
{
	return y_;
}

int Robot::getHealth() const
{
	return health_;
}

void Robot::moving(const int direction)
{
	switch (direction)
	{
	case left:
		--x_;
		break;
	case up:
		++y_;
		break;
	case right:
		++x_;
		break;
	case down:
		--y_;
		break;
	default:
		std::cout << "not correct direction!!!\n";
	}
}

void Robot::addingOrSubtracting(const int addHealth)
{
	this->health_ += addHealth;
}

Robot::~Robot()
{
}