// learn_test1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <string>

#include "Loc.h"
#include "Line.h"

using namespace std;

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;
const int base_y = 1;

int debug_num = 0;
int overX = 8;
int overY = 0;
bool over = false;

void move(int x, int y) {
	COORD cd;
	cd.X = x;
	cd.Y = y + base_y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, cd);
}

void debug(string str) {
	move(0, 15 + debug_num);
	cout << str << endl;
	move(0, 0);
	debug_num += 1;
}

class Map {
public:
	Map(int* map, int x, int y) :m_pMap(map), m_iX(x), m_iY(y) {}
	int* getMap() {
		return m_pMap;
	}

	void drawMap() {
		cout << "Title" << endl;
		for (int y = 0; y < 10; y++) {
			for (int x = 0; x < 10; x++) {
				if (x==overX and y == overY){
					cout << "+";
				}
				else if(*(m_pMap + y * 10 + x) == 1) {
					cout << "#";
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}
	}

	boolean pas(int x, int y) {
		return (*(m_pMap + y * 10 + x) == 0);
	}
private:
	int* m_pMap;
	int m_iX, m_iY;
};

class Man {
public:
	Man(int x = 0,int y = 0,int dir = 0)
		: m_iX(x),m_iY(y),m_iDir(dir)
	{
		m_iX_last = x;
		m_iY_last = y;
		m_iLastDir = dir;
		fresh_image();
	}

	~Man() {}

	void set_map(Map* map) {
		m_Map = map;
	}

	void fresh() {
		move(m_iX_last, m_iY_last);
		cout << " " << endl;
		move(m_iX, m_iY);
		cout << image << endl;
		move(0, 0);
		m_iX_last = m_iX;
		m_iY_last = m_iY;
	}

	void AI() {
		if ((m_Map -> pas(m_iX+ move_xB,m_iY+ move_yB)) == false){
			if (m_Map->pas(m_iX + move_x, m_iY+move_y)) {
				//m_iX += move_x;
				//m_iY += move_y;
			}
			else {
				turn_dir(true);
				//m_iState = 1;
			}
		}
		else {
			turn_dir(false);
		}

		if (m_Map->pas(m_iX + move_x, m_iY + move_y)) {
			m_iX += move_x;
			m_iY += move_y;
		}

		if (m_iX == overX and m_iY == overY ) {
			over = true;
		}
		fresh();
	}

	void start() {
		move(m_iX, m_iY);

		while (over == false) {
			Sleep(100);
			AI();
			if (over) {
				break;
			}
		}

		move(0, 11);
		cout << "找到出口" << endl;
	}

	void turn_dir(bool right) {
		if (right) {
			m_iDir += 1;
			m_iDir %= 4;
		}else{
			if (m_iDir == 0) {
				m_iDir = 3;
			}
			else {
				m_iDir -= 1;
			}
		}

		switch (m_iDir) {
		case UP:
			move_x = 0;
			move_y = -1;
			move_xB = -1;
			move_yB = 0;
			break;
		case RIGHT:
			move_x = 1;
			move_y = 0;
			move_xB = 0;
			move_yB = -1;
			break;
		case DOWN:
			move_x = 0;
			move_y = 1;
			move_xB = 1;
			move_yB = 0;
			break;
		case LEFT:
			move_x = -1;
			move_y = 0;
			move_xB = 0;
			move_yB = 1;
			break;
		}
		
		fresh_image();
	}

	void fresh_image() {
		switch (m_iDir) {
		case UP:
			image = '0';
			break;
		case RIGHT:
			image = '1';
			break;
		case DOWN:
			image = '2';
			break;
		case LEFT:
			image = '3';
			break;
		}
	}
private:
	int m_iDir;
	int m_iX, m_iY;
	int m_iX_last, m_iY_last;
	int m_iLastDir;
	Map* m_Map;

	int move_x = 0;
	int move_y = -1;
	//判断边上的墙的坐标
	int move_xB = -1;
	int move_yB = 0;
	char image = '*';
};

int main(void)
{
	int int_map[10][10] = {
		{1,1,1,1,1,1,1,1,0,1,},
		{1,0,0,1,1,1,0,0,0,1,},
		{1,0,1,1,0,1,1,1,0,1,},
		{1,0,0,0,0,0,0,1,0,1,},
		{1,1,0,1,0,0,0,1,0,1,},
		{1,1,0,1,0,0,0,1,0,1,},
		{1,1,0,1,0,1,0,1,0,1,},
		{1,0,0,1,1,0,0,0,0,1,},
		{1,0,0,0,0,0,1,1,1,1,},
		{1,0,1,1,1,1,1,1,1,1,},
	};
	Map* map = new Map(&int_map[0][0],10,10);
	Man* man = new Man(1, 9, UP);


	man->set_map(map);
	map -> drawMap();
	man->start();
}

