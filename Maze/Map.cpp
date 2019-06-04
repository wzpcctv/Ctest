
#include "Map.h"

Map::Map() {};
Map::Map(int size) {
	m_iMap = new int[size];
	for (int i = 0; i < size; i++) {
		m_iMap[i] = type::EMPTY;
	}
}

//传入xy获取index
int Map::getIndex(int x, int y) {
	return y * WIDE + x;
}

//传入xy获取格子的值
int Map::cubType(int x, int y) {
	return m_iMap[getIndex(x, y)];
}

//传入xy获取格子指针
int* Map::getCube(int x, int y) {
	return (m_iMap + getIndex(x, y));
}

//判断这格是否是空的
bool Map::isEmpty(int x, int y) {
	return (cubType(x, y) == type::EMPTY);
}

//判断格子的状态
bool Map::check(int x, int y, int type) {
	return (cubType(x, y) == type);
}

//设置格子状态
void Map::setCube(int x, int y, int type) {
	*getCube(x, y) = type;
}