
#include <Windows.h>
#include "Map.h"

Map::Map(){

}

Map::Map(int size) {
	m_iMap = new int[size];
	for (int i = 0; i < size; i++) {
		m_iMap[i] = type::WALL;
	}
	//初始化界面
	inter = new Interface();
	//printf("初始化对象 %x  %x", &inter, inter);
	//newRod(1, 1, Direction::RIGHT);

	fresh();
	create(1,1,1);
}

int tm = 0;

void Map::create(int x,int y,int dir) {
	move(x, y, ' ');
	Sleep(100);
	tm = tm + 1;
	int dirNow = dir;
	if (rand() % 100 < 50) {
		dirNow += rand() % 4;
	}
	for (int i = 0; i < 4; i++) {
		if (cross(x, y, (dirNow +i)%4 )) {
			switch (dirNow) {
			case 0:
				create(x, y + 1, (dirNow + i) % 4);
				break;
			case 1:
				create(x+1, y , (dirNow + i) % 4);
				break;
			case 2:
				create(x, y -1, (dirNow + i) % 4);
				break;
			case 3:
				create(x-1, y, (dirNow + i) % 4);
				break;
			}
		}
		else {
			return;
		}
	}
	move(0, 22,tm);
}

//传入xy获取index
int Map::getIndex(int x, int y) {
	return y * WIDE + x;
}

//传入xy获取格子的值
int Map::cubeType(int x, int y) {
	return m_iMap[getIndex(x, y)];
}

//传入xy获取格子的值
char Map::getCubeChar(int x, int y) {
	switch (m_iMap[getIndex(x, y)]) {
	case type::EMPTY:
		return ' ';
	case type::WALL:
		return '#';
	}
}

//传入xy获取格子指针
int* Map::getCube(int x, int y) {
	return (m_iMap + getIndex(x, y));
}

//判断这格是否是空的
bool Map::isEmpty(int x, int y) {
	return (cubeType(x, y) == type::EMPTY);
}

//判断格子的状态
bool Map::check(int x, int y, int type) {
	return (cubeType(x, y) == type);
}

//设置格子状态
void Map::setCube(int x, int y, int type) {
	//printf("\n输出对象地址 %x  %x", &inter, inter);
	*(getCube(x, y)) = type;
	inter->fresh(this, x, y);
}

void Map::fresh()
{
	inter->fresh(this);
}

void Map::update() {
	for (int i = 0; i < rodNum; i++) {
		if (rod[i]->isOver()){
			rod[i] -> move(this);
		}
		else if (i != 0){
			delete rod[i];
			rod[i] = rod[rodNum];
			rodNum--;
		}
	}
	if (rand() % 100 < 30) {
		newRod(rod[0]->getX(), rod[0]->getY(),Direction::LEFT);
	}
	inter->move(0, 22, rodNum);
}

void Map::newRod(int x, int y, Direction dir) {
	//初始化一个挖路点
	rod[rodNum] = new Rod(this, x, y, dir);
	rodNum = 1;
}

int Map::cubeSide(int x, int y) {
	int i = 0;
	if (isEmpty(x + 0, y + 1)) {
		i = i + 1;
	}
	if (isEmpty(x + 1, y + 0)) {
		i = i + 1;
	}
	if (isEmpty(x + 0, y + -1)) {
		i = i + 1;
	}
	if (isEmpty(x + -1, y + 0)) {
		i = i + 1;
	}
	return i;
}

bool Map::cross(int x, int y,int dir) {
	if (dir == 0 and check(x + 0, y + 1, type::WALL) and check(x + 0, y + 2, type::WALL)) {
		return true;
	}
	if (dir == 1 and check(x + 1, y + 0, type::WALL) and check(x + 2, y + 0, type::WALL)) {
		return true;
	}
	if (dir == 2 and check(x + 0, y - 1, type::WALL) and check(x + 0, y - 2, type::WALL)) {
		return true;
	}
	if (dir == 3 and check(x - 1, y + 0, type::WALL) and check(x - 2, y + 0, type::WALL)) {
		return true;
	}
	return false;
}

bool Map::out(int x, int y) {
	return x == 0 or y == 0 or x == WIDE - 1 or y == HIGH - 1;
}

void Map::move(int x, int y, char ch) {
	inter->move(x, y, ch);
}

void Map::move(int x, int y, int ch) {
	inter->move(x, y, ch);
}