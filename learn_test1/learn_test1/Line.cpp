#include <iostream>
#include <string>
#include "Line.h"

using namespace std;

Line::Line() {
	cout << "Line" << endl;
}

Line::Line(int x1, int y1, int x2, int y2)
//:locA(x1,y1),locB(x2,y2)
{
	int i;
	cout << "Line build" << endl;
	locA = Loc(x1, y1);
	locB = Loc(x2, y2);
	m_strA = new char[10];
}

Line::Line(const Line &_line) {
	cout << "Line copy" << endl;
	m_strA = new char[10];
	for (int i = 0; i < 10; i++) {
		m_strA[i] = _line.m_strA[i];
	}
}

Line::~Line() {
	cout << "~Line" << endl;
	delete []m_strA;
}

void Line::setA(int x, int y) {
	locA = Loc(x, y);
}
void Line::setB(int x, int y) {
	locB = Loc(x, y);
}

void Line::show() {
	for (int i = 0; i < 10; i++) {
		cout << m_strA[i];
	}
	cout << endl;
}