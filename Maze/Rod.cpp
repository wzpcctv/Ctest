
#include <stdlib.h>
#include "Direction.h"
#include "Rod.h"

#include "Direction.h"

#include "Map.h"

Rod::Rod(Map* map,int x, int y, Direction direction) : m_iX(x), m_iY(y), direction(direction) {
	map->setCube(x,y,Map::type::EMPTY);
};

void Rod::changeDirection() {
	switch (rand() % 4) {
	case 0:
		direction = Direction::UP;
		break;
	case 1:
		direction = Direction::RIGHT;
		break;
	case 2:
		direction = Direction::DOWN;
		break;
	case 3:
		direction = Direction::LEFT;
		break;
	}
}

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

	if (map->out(x+m_iX,y+m_iY) or rand()%100 < 50) {
		changeDirection();
	}
	bool suc = false;
	if (map->out(x+m_iX,y+m_iY) == false) {
		if (map->cubeSide(x + m_iX, y + m_iY) == 1 ){
			suc = true;
		}
		else if (map->cross(x + m_iX, y + m_iY, direction)) {
			suc = true;
			m_bOver = true;
		}
	}
	if (suc) {
		m_iX += x;
		m_iY += y;
		map->setCube(m_iX, m_iY, Map::type::EMPTY);

		switch (direction) {
		case Direction::UP:
			map->move(m_iX, m_iY, 0);
			break;
		case Direction::RIGHT:
			map->move(m_iX, m_iY, 1);
			break;
		case Direction::DOWN:
			map->move(m_iX, m_iY, 2);
			break;
		case Direction::LEFT:
			map->move(m_iX, m_iY, 3);
			break;
		}
	}
	else {
		changeDirection();
	}
	//map->move(m_iX, m_iY, ' ');
	//map->move(m_iX, m_iY, '1');
}

bool Rod::isOver() {
	return not m_bOver;
}

int Rod::getX() {
	return m_iX;
}
int Rod::getY() {
	return m_iY;
}