
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "interface.h"
#include "snake.h"

char interf[WIDE][HIGH];
//蛇，食物xy，蛇的长度（？）
void newinterface(struct snake* snake, int fx, int fy, int s) {
	int x, y;
	for (int xx = 0; xx < WIDE; xx++) {
		//画出地图
		for (int yy = 0; yy < HIGH; yy++) {

			if (xx == 0 || xx == WIDE - 1)
				interf[xx][yy] = '|';
			else if (yy == 0 || yy == HIGH - 1)
				interf[xx][yy] = '-';
			else if (xx == fx && yy == fy)
				interf[xx][yy] = '$';
			else
				interf[xx][yy] = ' ';
		}
	}

	//蛇身，每个身体覆盖地图
	for (; s >= 0; s--) {
		x = (snake + s)->x;
		y = (snake + s)->y;
		interf[x][y] = '@';
	}
}


void food(int* x, int* y, int* fx, int* fy, int* s, struct snake* snake) {
	int ffx, ffy;
	ffx = *fx;
	ffy = *fy;

	if (*x == *fx && *y == *fy) {//如果迟到了食物，产生下一个食物
		*fx = 1 + rand() % (WIDE - 3);
		*fy = 1 + rand() % (HIGH - 3);
		/*do {
			*fx = 1 + rand() % (WIDE - 3);
			*fy = 1 + rand() % (HIGH - 3);
		} while (ffx == *fx && ffy == *fy);//刷一个与上一次食物位置不同的食物

		for (int i = (*s); i >= 0; i--){

		}*/
		(*s)++;
	}
}


void control(int* x, int* y, int* X, int* Y) {
	if (_kbhit()) {//kbhit()是一个C和C++函数，用于非阻塞地响应键盘输入事件。其中文可译为“键盘敲击”(keyboard hit)。
		switch (_getch()) {
		case 'w':
		case 'W':
			if (interf[*y - 1][*y] != '@') {//爆炸不能回头
				*X = 0; *Y = -1;
			}
			break;
		case 'D':
		case 'd':
			if (interf[*y][*y + 1] != '@') {//爆炸不能回头
				*X = 1; *Y = 0;
			}
			break;
		case 'S':
		case 's':
			if (interf[*y + 1][*y] != '@') {//爆炸不能回头
				*X = 0; *Y = 1;
			}
			break;
		case 'A':
		case 'a':
			if (interf[*y - 1][*y] != '@') {//爆炸不能回头
				*X = -1; *Y = 0;
			}
			break;
		default:
			break;
		}
	}
	*x = *x + *X;
	*y = *y + *Y;
}


void draw(void)
{
	printf("\n");
	for (int yy = 0; yy < HIGH; yy++) {
		for (int xx = 0; xx < WIDE; xx++) {
			printf("%c", interf[xx][yy]);
			//printf("%i,%i,%c|",xx,yy,interf[xx][yy]);
		}
		printf("\n");
	}
}


int death(int x, int y, int s)
{
	if ( x == 0 || x == WIDE - 1 || y == 0 || y == HIGH - 1 || interf[x][y] == '@') {
		//system("cls");
		printf("\n游戏结束！");
		printf("\n最终得分：%d", s);
		printf("\n%d|%d|%c\n", x, y, interf[x][y]);
		Sleep(300);
		return 1;
	}
	return 0;
}