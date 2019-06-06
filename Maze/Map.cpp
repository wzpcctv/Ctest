
#include <Windows.h>
#include "Map.h"
#include <iostream>

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
	//newRod(1, 1, Direction::RIGHT);
	cout << "Hellow" << endl;
	fresh();
	create(1,1);

	move(0, HIGH + 3, 'END');
}

int tm = 0;

void Map::create(int x,int y) {
	setCube(x, y, type::EMPTY);
	Sleep(50);
	tm = tm + 1;

	int dirc[4][2] = {
		{1,0},
		{0,1},
		{0,-1},
		{-1,0}
	};

	for (int i = 0; i < 4; i++) {
		int temp;
		int rd = rand() % 4;
		temp = dirc[rd][0];
		dirc[rd][0] = dirc[i][0];
		dirc[i][0] = temp;
		temp = dirc[rd][1];
		dirc[rd][1] = dirc[i][1];
		dirc[i][1] = temp;
	}

	for (int n = 0; n < 4; n++) {
		int xb = x + dirc[n][0];
		int yb = y + dirc[n][1];

		if (cubeSide(xb, yb) >= 3 and cubeSideB(xb,yb)>2) {
			create(xb, yb);
		}
	}

	//if (rand() % 100 < 50) {
	//	dirNow += rand() % 4;
	//}
	//for (int i = 0; i < 4; i++) {
	//	if (cross(x, y, (dirNow +i)%4 )) {
	//		switch (dirNow) {
	//		case 0:
	//			create(x, y + 1, (dirNow + i) % 4);
	//			break;
	//		case 1:
	//			create(x+1, y , (dirNow + i) % 4);
	//			break;
	//		case 2:
	//			create(x, y -1, (dirNow + i) % 4);
	//			break;
	//		case 3:
	//			create(x-1, y, (dirNow + i) % 4);
	//			break;
	//		}
	//	}
	//	else {
	//		return;
	//	}
	//}
	//move(0, 22,tm);
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

bool Map::isWall(int x, int y) {
	return (cubeType(x, y) == type::WALL);
}

//�жϸ��ӵ�״̬
bool Map::check(int x, int y, int type) {
	if (out(x, y)) {
		return true;
	}
	return (cubeType(x, y) == type);
}

//���ø���״̬
void Map::setCube(int x, int y, int type) {
	//printf("\n��������ַ %x  %x", &inter, inter);
	*(getCube(x, y)) = type;
	inter->fresh(this, x, y);
	move(x, y, ' ');
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
	//��ʼ��һ����·��
	rod[rodNum] = new Rod(this, x, y, dir);
	rodNum = 1;
}

int Map::cubeSide(int x, int y) {
	if (out(x, y)) {
		return 0;
	}
	int i = 0;
	if (isWall(x + 0, y + 1)) {
		i = i + 1;
	}
	if (isWall(x + 1, y + 0)) {
		i = i + 1;
	}
	if (isWall(x + 0, y + -1)) {
		i = i + 1;
	}
	if (isWall(x + -1, y + 0)) {
		i = i + 1;
	}
	return i;
}

int Map::cubeSideB(int x, int y) {
	if (out(x, y)) {
		return 4;
	}
	int i = 0;
	if (isWall(x + 1, y + 1)) {
		i = i + 1;
	}
	if (isWall(x + -1, y + 1)) {
		i = i + 1;
	}
	if (isWall(x + 1, y + -1)) {
		i = i + 1;
	}
	if (isWall(x + -1, y + -1)) {
		i = i + 1;
	}
	return i;
}

bool Map::cross(int x, int y,int dir) {
	return true;
}

bool Map::out(int x, int y) {
	return x <= 0 or y <= 0 or x >= WIDE - 1 or y >= HIGH - 1;
}

void Map::move(int x, int y, char ch) {
	inter->move(x, y, ch);
}

void Map::move(int x, int y, int ch) {
	inter->move(x, y, ch);
}