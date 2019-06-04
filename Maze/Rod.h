#pragma once

//ÍÚÂ·Í·
#ifndef ROD_H
#define ROD_H
#include "Direction.h"
class Rod {
public:
	Rod();
	Rod(int x, int y, int direction) : m_iX(x), m_iY(y), direction(direction) {

	};

	void move(Map* map);

private:
	int m_iX;
	int m_iY;
	int direction;
	int step = 0;
	enum moveX {
		UP = 0,
		RIGHT = 1,
		DOWN = 0,
		LEFT = -1,
	};
	enum moveY {
		UP = 1,
		RIGHT = 0,
		DOWN = -1,
		LEFT = 0,
	};
};

#endif