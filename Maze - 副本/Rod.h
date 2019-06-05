#pragma once

//ÍÚÂ·Í·
#include "Direction.h"
#include "Map.h"

class Rod {
public:
	Rod();
	Rod(Map* map, int x, int y, int direction);

	void move(Map* map);

private:
	int m_iX;
	int m_iY;
	int direction;
	int step = 0;
};