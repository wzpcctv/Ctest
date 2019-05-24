#pragma once

class Loc {
public:
	Loc();
	Loc(int x, int y);
	~Loc();
	int getX();
	int getY();
	void setX(int n);
	void setY(int n);
private:
	int x;
	int y;
};