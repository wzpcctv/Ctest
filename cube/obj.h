

#ifndef OBJ_H
#define OBJ_H

struct obj {
	int x;
	int y;
	int id;
	char map[16];
};

struct brick {
	int x;
	int y;
};


void new_obj(struct obj* obj, int x, int y);
void brick_down(struct obj* obj, struct brick* brick,int* brick_num,int* game_step);
void game_over_check(struct brick* brick, int brick_num, int* game_step);
void obj_move(int dir, struct obj* obj, struct brick* brick, int brick_num);

#endif