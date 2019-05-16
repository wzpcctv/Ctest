#ifndef INTERFACE_H
#define INTERFACE_H

#define WIDE 20
#define HIGH 15

void control(int* x, int* y, int* X, int* Y);
void snake(int x, int y);
int death(int x, int y, int s);
void newinterface(struct snake* snake, int fx, int fy, int s);
void food(int* x, int* y, int* fx, int* fy, int* s, struct snake* snake);
void draw(void);

#endif