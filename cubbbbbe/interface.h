

#ifndef INTERFACE_H
#define INTERFACE_H

#define WIDE 10
#define HIGH 15

void freshInterface(struct obj* obj, struct brick* bk, int* brick_num);
void draw(struct obj* obj, struct brick* bk, int* brick_num, int score,int game_step);
void control( struct obj* obj, struct brick* brick, int brick_num);

#endif