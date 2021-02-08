#include <iostream>
#include "Arena.h"
#include "Robot.h"
#include "TiringRobot.h"

int main()
{
	int arena_size;
	do {
		std::cout << "input arena size: ";
		std::cin >> arena_size;
	} while (arena_size < 2 || arena_size > 10);
	std::cout << "\n";

	Arena arena(arena_size);
	arena.showBoard();
	Robot* r = &Robot(5, 5, 2);
	arena.addRobot(r);
	r = &Robot(3, 8, 4);
	arena.addRobot(r);
	r = &Robot(6, 4, 7);
	arena.addRobot(r);

	TiringRobot t1(4, 1, 5);
	r = &t1;
	arena.addRobot(r);
	TiringRobot t2(1, 6, 10);
	r = &t2;
	arena.addRobot(r);
	TiringRobot t3(-3, -8, 20);
	r = &t3;
	arena.addRobot(r);


	arena.display();
	while (arena.tick())
	{
		arena.display();
	}
	std::cout << "\n";
	arena.showBoard();
}