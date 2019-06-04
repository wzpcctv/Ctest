#pragma once

#ifndef MAP_H
#define MPA_H

#define WIDE 30
#define HIGH 30

class Map {
public:
	enum type { EMPTY,WALL };
	Map();
	Map(int size);

	//传入xy获取index
	int getIndex(int x, int y);

	//传入xy获取格子的值
	int cubType(int x, int y);

	//传入xy获取格子指针
	int* getCube(int x, int y);

	//判断这格是否是空的
	bool isEmpty(int x, int y);

	//判断格子的状态
	bool check(int x, int y, int type);

	//设置格子状态
	void setCube(int x, int y, int type);

private:
	int* m_iMap;
	int m_iNum;
};

#endif