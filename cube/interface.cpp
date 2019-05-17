
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#include "interface.h"
#include "obj.h"


char interf[WIDE][HIGH];
//刷新出场景
void freshInterface(struct obj* obj,struct brick* brick, int* brick_num) {
	int xx, yy,n;
	for (xx = 0; xx < WIDE; xx++) {
		for (yy = 0; yy < HIGH; yy++) {
			if (xx == 0 || xx == WIDE - 1) {
				interf[xx][yy] = '|';
			} else if (yy == 0 || yy == HIGH - 1) {
				interf[xx][yy] = '-';
			} else {
				interf[xx][yy] = ' ';
			}
		}
	}
	for (n = 0; n < 16; n++) {
		if (obj->map[n] == '@') {
			interf[obj->x + n % 4][obj->y + n / 4] = '@';
		}
	}
	for (n = 0; n < *brick_num; n++) {
		printf("%d  %x %x\n", *brick_num, (brick + n)->x, (brick + n)->y);
		interf[(brick + n)->x][(brick + n)->y] = '#';
	}
}

void draw(struct obj* obj, struct brick* bk,int* brick_num,int score,int game_step) {
	int xx, yy;

	//system("cls");
	printf("\n方块");
	printf("\nscore:%d", score);
	printf("\ninfo:%d,%d,%d", obj->x, obj->y, *brick_num);
	printf("\ngame_step:%d", game_step);
	printf("\n");
	freshInterface(obj,bk,brick_num );
	for (yy = 0; yy < HIGH; yy++) {
		for (xx = 0; xx < WIDE; xx++) {
			printf("%c",interf[xx][yy]);
		}
		printf("\n");
	}
}


void control(struct obj* obj, struct brick* brick, int brick_num) {
	if (_kbhit()) {//kbhit()是一个C和C++函数，用于非阻塞地响应键盘输入事件。其中文可译为“键盘敲击”(keyboard hit)。
		switch (_getch()) {
		case 'w':
		case 'W':
			break;
		case 'D':
		case 'd':
			obj_move(1, obj, brick, brick_num);
			break;
		case 'S':
		case 's':
			obj_move(2, obj, brick, brick_num);
			break;
		case 'A':
		case 'a':
			obj_move(0,obj,brick,brick_num);
			break;
		default:
			break;
		}
	}
}