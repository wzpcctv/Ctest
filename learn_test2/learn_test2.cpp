#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

template <typename A>
void dis(A a) {
	cout << a << endl;
}

int main(void)
{
	dis('A');
	dis(10);
	return 0;
}

