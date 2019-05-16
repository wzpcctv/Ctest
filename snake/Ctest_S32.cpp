
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "interface.h"
#include "snake.h"

int main() {
	struct snake a[(WIDE - 2) * (HIGH - 2)];
	int snake_x = 5;
	int snake_y = 5;
	int X = 1;
	int Y = 0;
	int food_x, food_y;
	int score = 0;
	int tm_run = 0;
	int game_over = 0;

	/*do {
		food_x = 1 + rand() % (WIDE - 3);
		food_y = 1 + rand() % (HIGH - 3);
	} while (food_x == 4 && food_y == 4);*/
	food_x = 4;
	food_y = 4;

	for (; game_over == 0;) {
		system("cls");
		printf("\n title");
		printf("\nTM:%d", tm_run);
		printf("\nscore:%d", score);

		printf("\n");
		control(&snake_x, &snake_y, &X, &Y);
		build_snake(a, score, &snake_x, &snake_y);
		game_over = death(snake_x, snake_y, score);
		newinterface(a, food_x, food_y, score);
		food(&snake_x, &snake_y, &food_x, &food_y, &score, a);

		if (game_over == 0){
			draw();
			Sleep(300);
			tm_run = tm_run + 1;
		}
	}

	system("pause");
	return 0;
}