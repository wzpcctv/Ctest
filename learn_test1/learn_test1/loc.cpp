#include <iostream>
#include "Loc.h"
#include <String>

using namespace std;
Loc::Loc()
	:Loc(0,0)
{
	cout << "loc - base" << endl;
}
Loc::Loc(int x,int y)
:x(x),y(y){
	cout << "Loc" << x<< ","<<y << endl;
}

Loc::~Loc() {
	cout << "~Loc" << x << "," << y << endl;
}