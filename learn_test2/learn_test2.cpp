// learn_test2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iostream>
using namespace std;


class Base {
public:
	virtual void draw() {
		cout << "draw - Base" << endl;
	}
};

class A : public Base {
	void draw() {
		cout << "draw - A" << endl;
	}
};

class B : public Base {
	void draw() {
		cout << "draw - B" << endl;
	}
};

int main()
{

	Base *b1 = new A();
	Base *b2 = new B();

	b1->draw();
	b2->draw();

	delete b1;
	delete b2;
	b1 = NULL;
	b2 = NULL;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
