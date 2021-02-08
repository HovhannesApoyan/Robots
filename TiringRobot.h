#pragma once
#include "Robot.h"

class TiringRobot : public Robot {
public:
	TiringRobot(const int& x, const int& y, const int& health);
	virtual void moving(const int direction)override;
	virtual ~TiringRobot();
};