#pragma once

#include "Loc.h"

class Line {
public:
	Line();
	Line(int x1,int y1,int x2,int y2);
	~Line();
	Line(const Line &l);
	void show();
	void setA(int x,int y);
	void setB(int x,int y);
private:
	Loc locA;
	Loc locB;
	char* m_strA;
};
