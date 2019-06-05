#pragma once

//ÍÚÂ·Í·
#include "Direction.h"

class Map;

class Rod {
public:
	Rod();
	Rod(Map* map, int x, int y, Direction direction);
	void move(Map* map);
	void changeDirection();
	bool isOver();
	int getX();
	int getY();
private:
	int m_iX;
	int m_iY;
	Direction direction;
	int step = 0;
	bool m_bOver = false;
};