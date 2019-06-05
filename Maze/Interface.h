#pragma once

#include <string.h>
#include <string>


using namespace std;

class Map;


class Interface {
public:
	Interface();
	~Interface();
	void move(int x,int y);
	void move(int x, int y, char ch);
	void move(int x, int y, int ch);
	void fresh(Map* map);
	void fresh(Map* map, int x, int y);
private:
	int base_y = 3;
};