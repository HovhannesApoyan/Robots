#include <iostream>
#include <ctime>
#include "Arena.h"

Arena::Arena(const int size)
	:size_(size)
{
	initBoard();
}

void Arena::initBoard()
{
	robots_area.resize(this->size_, std::vector<int>(this->size_, 0));
	int area = pow(this->size_, 2);
	for (int i = 0; i < area / 4; ++i)
	{
		srand((unsigned)time(0));
		int x = rand() % this->size_;
		int y = rand() % this->size_;
		if (robots_area[x][y] == 0)
		{
			robots_area[x][y] = 1;
		}
		else
		{
			while (robots_area[x][y] != 0)
			{
				x = (rand() % this->size_);
				y = (rand() % this->size_);
			}
			robots_area[x][y] = 1;
		}
	}
	for (int i = area / 4; i < area / 2; ++i)
	{
		srand((unsigned)time(0));
		int x = rand() % this->size_;
		int y = rand() % this->size_;
		if (robots_area[x][y] == 0)
		{
			robots_area[x][y] = -1;
		}
		else
		{
			while (robots_area[x][y] != 0)
			{
				x = (rand() % this->size_);
				y = (rand() % this->size_);
			}
			robots_area[x][y] = -1;
		}
	}
}

void Arena::addRobot(Robot* robot)
{
	robots.push_back(robot);
	if (robots[robots.size() - 1]->getHealth() <= 0 || robots[robots.size() - 1]->getX() >= robots_area.size() || robots[robots.size() - 1]->getY() >= robots_area.size())
	{
		robots[robots.size() - 1] = nullptr;
	}
}

void Arena::display()const
{
	std::cout << "\t " << "x y health\n";
	for (int i = 0; i < robots.size(); ++i)
	{
		if (robots[i] != nullptr)
		{
			std::cout << "Robot_" << i + 1
				<< ": " << robots[i]->getX()
				<< " " << robots[i]->getY()
				<< " " << robots[i]->getHealth() << "\n";
		}
	}
}

void Arena::showBoard() const
{
	for (int i = 0; i < size_; i++) {
		for (int j = 0; j < robots_area[i].size(); j++)
			std::cout << robots_area[i][j] << " ";
		std::cout << std::endl;
	}
}

bool Arena::tick()
{
	srand((unsigned)time(0));
	int count = 0;
	for (int i = 0; i < robots.size(); ++i)
	{
		if (robots[i] != nullptr)
		{
			int x = robots[i]->getX();
			int y = robots[i]->getY();
			robots[i]->addingOrSubtracting(robots_area[x][y]);
			robots_area[x][y] = 0;
			if (robots[i]->getHealth() == 0)
			{
				robots[i] = nullptr;
				++count;
				continue;
			}

			int direction = (rand() % 4);
			robots[i]->moving(direction);
			x = robots[i]->getX();
			y = robots[i]->getY();
			if (x >= size_ || x < 0 || y >= size_ || y < 0 || robots[i]->getHealth() == 0)
			{
				robots[i] = nullptr;
				++count;
			}
			else if (robots_area[x][y] != 0)
			{
				robots[i]->addingOrSubtracting(robots_area[x][y]);
				robots_area[x][y] = 0;
				if (robots[i]->getHealth() == 0)
				{
					robots[i] = nullptr;
					++count;
				}
			}
		}
		else
		{
			++count;
		}
	}
	if (count == robots.size())
		return false;
	return true;
}
Arena::~Arena()
{

}