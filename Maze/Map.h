#pragma once

#define WIDE 50
#define HIGH 40

#include "Rod.h"
#include "Interface.h"

class Map {
public:
	enum type { EMPTY,WALL };
	Map();
	Map(int size);
	void create(int x, int y);
	//����xy��ȡindex
	int getIndex(int x, int y);
	//����xy��ȡ���ӵ�ֵ
	int cubeType(int x, int y);
	//����xy��ȡ����ָ��
	int* getCube(int x, int y);
	char getCubeChar(int x, int y);
	//�ж�����Ƿ��ǿյ�
	bool isEmpty(int x, int y);
	bool isWall(int x, int y);
	//�жϸ��ӵ�״̬
	bool check(int x, int y, int type);
	//���ø���״̬
	void setCube(int x, int y, int type);
	void fresh();
	void update();
	void newRod(int x, int y, Direction dir);
	int cubeSide(int x, int y);
	int cubeSideB(int x, int y);
	bool cross(int x, int y, int dir);
	bool out(int x, int y);
	void move(int x, int y, char ch);
	void move(int x, int y, int ch);
private:
	int* m_iMap;
	int m_iWide;
	int m_iHigh;
	//���
	Interface* inter;
	//��·��
	Rod* rod[100];
	int rodNum = 0;
};