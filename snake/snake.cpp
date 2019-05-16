
#include <stdio.h>
#include <stdlib.h>
#include "snake.h"

void build_snake(struct snake* snake, int s, int* sx, int* sy)
{
	for (int i = s; i >= 0; i--)
	{
		if (i == 0) {
			(snake + i)->number = i;
			(snake + i)->x = *sx;
			(snake + i)->y = *sy;
		}
		else {
			(snake + i)->number = i;
			(snake + i)->x = (snake + i - 1) -> x;
			(snake + i)->y = (snake + i - 1) -> y;
		}
	}
}