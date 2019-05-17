// cube.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <time.h>
#include <windows.h>

#include "interface.h"
#include "obj.h"


int main()
{
	time_t myt = time(NULL);
	struct obj ob;
	struct brick b[(WIDE - 2) * (HIGH - 2)];

	printf("内存地址 %x \n", &b);
	int brick_num = 0;
	//printf("%p", ob); //数组名代表的本身是一个指针

	//游戏结束
	int game_over = 0;
	//游戏状态
	int game_step = 0;
	int score = 0;

	//随机种子
	//printf("%d", myt);
	srand(myt);
	int tm = 0;

	//printf("%d", 11 / 2);


	for (; game_over == 0;) {
		tm = tm + 1;
		switch (game_step) {
			case 0://创建一个方块
				game_step = 1;
				new_obj( &ob, 1,1);
				break;
			case 1://方块运动中
				break;
		}

		if (game_step != 2) {
			control(&ob,b,brick_num);
			if (tm % 10 == 0) {
				brick_down(&ob, b, &brick_num, &game_step);
			}
			draw(&ob, b, &brick_num, score, game_step);
			Sleep(10);
		}
		else {
			break;
		}
	}
	printf("game_over");
}
