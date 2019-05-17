#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include "obj.h"
#include "interface.h"


void new_obj(struct obj* obj,int x,int y) {
	char str[200] = "";
	int max = 5;
	int i = rand() % 1;
	int n;
	switch (i) {
		case 0:
			strcat(str, "@@@@");
			strcat(str, "@@@@");
			strcat(str, "@@@@");
			strcat(str, "@@@@");
			break;
		case 1:
			strcat(str, "    ");
			strcat(str, " @@ ");
			strcat(str, " @@ ");
			strcat(str, "    ");
			break;
		case 2:
			strcat(str, " @  ");
			strcat(str, " @  ");
			strcat(str, " @  ");
			strcat(str, " @  ");
			break;
		case 3:
			strcat(str, " @  ");
			strcat(str, " @  ");
			strcat(str, " @  ");
			strcat(str, " @  ");
			break;
		case 4:
			strcat(str, " @  ");
			strcat(str, " @  ");
			strcat(str, " @  ");
			strcat(str, " @  ");
			break;
	}

	for (n = 0; n < 16; n++) {
		(obj)->map[n] = str[n];
	}
	obj->x = x;
	obj->y = y;
	obj->id = i;
}

//¸¡¿ÕµÄ·½¿éÍùÏÂÅÜ
void brick_down(struct obj* obj, struct brick* brick,int* brick_num,int* game_step) {
	int n, n2, n3,n4,num,x = 0;
	int xx, yy;
	int over = 0;
	for (n = 0; n < 16; n++) {
		xx = (obj->x) + n%4;
		yy = (obj->y) + n/4;
		if (obj -> map[n] == '@') {
			if (yy == HIGH - 2) {
				over = 1;
				break;
			}
			for (n2 = 0; n2 < *brick_num; n2++) {
				if (((brick + n2)->x == xx) && ((brick + n2)->y == yy + 1)) {
					over = 1;
					//draw(obj, brick, brick_num, 0, *game_step);
					//printf("%d,%d,%d,%d", (brick + n2)->x, (brick + n2)->y, xx, yy);
					//Sleep(100000);
					break;
				}
			}
			if (over == 1) {
				break;
			}
		}
	}

	if (over == 1) {

		for (n = 0; n < 16; n++) {
			if (obj->map[n] == '@') {
				printf("\nbrick_num:%d , %d", *brick_num, n);
				for (n2 = 0; n2 < *brick_num; n2++) {
					if ((brick + n2)->x == (obj->x) + n % 4 && (brick + n2)->y == (obj->y) + n / 4) {
						*game_step = 2;
						break;
					}
				}
				if (*game_step != 2) {
					(brick + *brick_num)->x = (obj->x) + n % 4;
					(brick + *brick_num)->y = (obj->y) + n / 4;
					*brick_num = *brick_num + 1;
					*game_step = 0;
				}
				else
				{
					break;
				}
			}
		}

		for (x = 0; x < HIGH; x++) {
			num = 0;
			for (n4 = 0; n4 < *brick_num; n4++) {
				if ((brick + n4)->y == x) {
					num++;
				}
			}
			if (num == WIDE - 2) {
				for (n2 = 0; n2 < *brick_num; n2++) {
					if ((brick + n2)->y == x) {
						(brick + n2)->x = (brick + *brick_num)->x;
						(brick + n2)->y = (brick + *brick_num)->y;
						*brick_num = *brick_num - 1;
						n2--;
						printf("\nbrick_num -1 :%d", *brick_num);
					}
				}
			}
		}
	} else {
		obj->y++;
	}
}

void game_over_check(struct brick* brick,int brick_num,int* game_step) {
	int i;
	for (i = 0; i < brick_num; i++) {
		if ((brick + i)->y <= 1) {
			*game_step = 2;
			break;
		}
	}
}


void obj_move(int dir,struct obj* obj, struct brick* brick, int brick_num) {
	int xx, yy, i,i2;

	if (dir == 0) {//Íù×ó
		for (i = 0; i < 16; i++) {
			xx = obj->x + i % 4 - 1;
			yy = obj->y + i / 4;
			if (obj->map[i] == '@') {
				for (i2 = 0; i2 < brick_num; i2++) {
					if ((brick + i2)->x == xx && (brick + i2)->y == yy) {
						return;
					}
				}
				if (xx == 0 || xx == WIDE - 1) {
					return;
				}
			}
		}
		obj->x = obj->x - 1;
		return;
	}
	else if (dir == 1) {
		for (i = 0; i < 16; i++) {
			xx = obj->x + i % 4 + 1;
			yy = obj->y + i / 4;
			if (obj->map[i] == '@') {
				for (i2 = 0; i2 < brick_num; i2++) {
					if ((brick + i2)->x == xx && (brick + i2)->y == yy) {
						return;
					}
				}
				if (xx == 0 || xx == WIDE - 1) {
					return;
				}
			}
		}
		obj->x = obj->x + 1;
		return;
	}
}