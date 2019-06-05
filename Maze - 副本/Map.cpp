
#include "Rod.h"
#include "Map.h"

Map::Map(){

}

Map::Map(int size) {
	m_iMap = new int[size];
	for (int i = 0; i < size; i++) {
		m_iMap[i] = type::WALL;
	}
	//��ʼ������
	inter = new Interface();
	//printf("��ʼ������ %x  %x", &inter, inter);
	newRod(1, 1, Direction::LEFT);

	fresh();
}


//����xy��ȡindex
int Map::getIndex(int x, int y) {
	return y * WIDE + x;
}

//����xy��ȡ���ӵ�ֵ
int Map::cubeType(int x, int y) {
	return m_iMap[getIndex(x, y)];
}

//����xy��ȡ���ӵ�ֵ
char Map::getCubeChar(int x, int y) {
	switch (m_iMap[getIndex(x, y)]) {
	case type::EMPTY:
		return ' ';
	case type::WALL:
		return '#';
	}
}

//����xy��ȡ����ָ��
int* Map::getCube(int x, int y) {
	return (m_iMap + getIndex(x, y));
}

//�ж�����Ƿ��ǿյ�
bool Map::isEmpty(int x, int y) {
	return (cubeType(x, y) == type::EMPTY);
}

//�жϸ��ӵ�״̬
bool Map::check(int x, int y, int type) {
	return (cubeType(x, y) == type);
}

//���ø���״̬
void Map::setCube(int x, int y, int type) {
	//printf("\n��������ַ %x  %x", &inter, inter);
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
	//��ʼ��һ����·��
	rod[rodNum] = Rod(this, x, y, dir);
	rodNum = 1;
}