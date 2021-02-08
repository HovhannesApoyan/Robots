#pragma once
#include <vector>
#include "Robot.h"

class Arena {
public:
	Arena(const int size);
	void initBoard();
	void addRobot(Robot* robot);
	void display()const;
	void showBoard()const;
	bool tick();
	~Arena();
private:
	int size_;
	std::vector<std::vector<int>> robots_area;
	std::vector<Robot*> robots;
};