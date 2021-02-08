#pragma once

class Robot {
public:
	Robot();
	Robot(const int& x, const int& y, const int& health);
	int getX()const;
	int getY()const;
	int getHealth()const;
	enum {
		left,
		up,
		right,
		down,
	};
	virtual void moving(const int direction);
	void addingOrSubtracting(const int addHealth);
	virtual ~Robot();
private:
	int x_;
	int y_;
	int health_;
};