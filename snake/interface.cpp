
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "interface.h"
#include "snake.h"

char interf[WIDE][HIGH];
//�ߣ�ʳ��xy���ߵĳ��ȣ�����
void newinterface(struct snake* snake, int fx, int fy, int s) {
	int x, y;
	for (int xx = 0; xx < WIDE; xx++) {
		//������ͼ
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

	//����ÿ�����帲�ǵ�ͼ
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

	if (*x == *fx && *y == *fy) {//����ٵ���ʳ�������һ��ʳ��
		*fx = 1 + rand() % (WIDE - 3);
		*fy = 1 + rand() % (HIGH - 3);
		/*do {
			*fx = 1 + rand() % (WIDE - 3);
			*fy = 1 + rand() % (HIGH - 3);
		} while (ffx == *fx && ffy == *fy);//ˢһ������һ��ʳ��λ�ò�ͬ��ʳ��

		for (int i = (*s); i >= 0; i--){

		}*/
		(*s)++;
	}
}


void control(int* x, int* y, int* X, int* Y) {
	if (_kbhit()) {//kbhit()��һ��C��C++���������ڷ���������Ӧ���������¼��������Ŀ���Ϊ�������û���(keyboard hit)��
		switch (_getch()) {
		case 'w':
		case 'W':
			if (interf[*y - 1][*y] != '@') {//��ը���ܻ�ͷ
				*X = 0; *Y = -1;
			}
			break;
		case 'D':
		case 'd':
			if (interf[*y][*y + 1] != '@') {//��ը���ܻ�ͷ
				*X = 1; *Y = 0;
			}
			break;
		case 'S':
		case 's':
			if (interf[*y + 1][*y] != '@') {//��ը���ܻ�ͷ
				*X = 0; *Y = 1;
			}
			break;
		case 'A':
		case 'a':
			if (interf[*y - 1][*y] != '@') {//��ը���ܻ�ͷ
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
		printf("\n��Ϸ������");
		printf("\n���յ÷֣�%d", s);
		printf("\n%d|%d|%c\n", x, y, interf[x][y]);
		Sleep(300);
		return 1;
	}
	return 0;
}