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
	//传入xy获取index
	int getIndex(int x, int y);
	//传入xy获取格子的值
	int cubeType(int x, int y);
	//传入xy获取格子指针
	int* getCube(int x, int y);
	char getCubeChar(int x, int y);
	//判断这格是否是空的
	bool isEmpty(int x, int y);
	bool isWall(int x, int y);
	//判断格子的状态
	bool check(int x, int y, int type);
	//设置格子状态
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
	//输出
	Interface* inter;
	//挖路点
	Rod* rod[100];
	int rodNum = 0;
};