#pragma once

#define WIDE 30
#define HIGH 20

#include "Rod.h"
#include "Interface.h"

class Map {
public:
	enum type { EMPTY,WALL };
	Map();
	Map(int size);
	//����xy��ȡindex
	int getIndex(int x, int y);
	//����xy��ȡ���ӵ�ֵ
	int cubeType(int x, int y);
	//����xy��ȡ����ָ��
	int* getCube(int x, int y);
	char getCubeChar(int x, int y);
	//�ж�����Ƿ��ǿյ�
	bool isEmpty(int x, int y);
	//�жϸ��ӵ�״̬
	bool check(int x, int y, int type);
	//���ø���״̬
	void setCube(int x, int y, int type);
	void fresh();
	void update();
	void newRod(int x, int y, Direction dir);
private:
	int* m_iMap;
	int m_iWide;
	int m_iHigh;
	//���
	Interface* inter;
	//��·��
	Rod rod[100];
	int rodNum = 0;
};