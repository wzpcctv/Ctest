
#include <stdlib.h>
#include "Direction.h"
#include "Rod.h"
#include "Map.h"
#include "Direction.h"

Rod::Rod(Map* map,int x, int y, int direction) : m_iX(x), m_iY(y), direction(direction) {
	map->setCube(x,y,Map::type::EMPTY);
};

void Rod::move(Map* map){
	int x = 0;
	int y = 0;
	switch (direction) {
	case Direction::UP:
		x = 0;
		y = 1;
		break;
	case Direction::RIGHT:
		x = 1;
		y = 0;
		break;
	case Direction::DOWN:
		x = 0;
		y = -1;
		break;
	case Direction::LEFT:
		x = -1;
		y = 0;
		break;
	}

	if (rand() % 10 < 5) {
		direction = rand() % 4;
	}

	if (map->check(x + m_iX, y + m_iY, Map::type::WALL)) {
		m_iX += x;
		m_iY += y;
	}

	//map->setCube(m_iX, m_iY, Map::type::EMPTY);
}