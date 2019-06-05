
#include "Rod.h"
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
	newRod(1, 1, Direction::LEFT);

	fresh();
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
		rod[i].move(this);
	}
}

void Map::newRod(int x, int y, Direction dir) {
	//初始化一个挖路点
	rod[rodNum] = Rod(this, x, y, dir);
	rodNum = 1;
}