#ifndef SNAKE_H
#define SNAKE_H

struct snake {
	int x;
	int y;
	int number;
	void shot() {

	};
};

void build_snake(struct snake* snake, int s, int* sx, int* sy);

#endif