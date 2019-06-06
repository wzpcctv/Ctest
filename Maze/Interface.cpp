#include <windows.h>
#include <iostream>
#include "Interface.h"
#include "Map.h"

using namespace std;

Interface::Interface() 
{
	cout << "Title" << endl;
	base_y = 3;
}

Interface::~Interface() {

}

void Interface::move(int x, int y) {
	COORD cd;
	cd.X = x;
	cd.Y = y + base_y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, cd);
}

void Interface::move(int x, int y, char ch) {
	move(x, y);
	cout << ch;
	move(0, HIGH + 5);
}

void Interface::move(int x, int y, int ch) {
	move(x, y);
	cout << ch;
	move(0, HIGH + 5);
}

void Interface::fresh(Map* map) {
	for (int y = 0; y < HIGH; y++) {
		for (int x = 0; x < WIDE; x++) {
			move(x, y,map->getCubeChar(x,y));
		}
	}
}

void Interface::fresh(Map* map, int x, int y) {
	move(x, y, map -> getCubeChar(x, y));
}