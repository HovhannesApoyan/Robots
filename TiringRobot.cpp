#include <iostream>
#include "TiringRobot.h"

TiringRobot::TiringRobot(const int& x, const int& y, const int& health)
	: Robot(x, y, health)
{
}
void TiringRobot::moving(const int direction)
{
	Robot::moving(direction);
	addingOrSubtracting(-1);
}
TiringRobot::~TiringRobot()
{
}