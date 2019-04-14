#ifndef BOARD_H
#define BOARD_H
#include <iostream>

class Board
{
public:
    int maxx = 10;
	int maxy = 7;
	char field[10][7];
	char checkfield[10][7];
	void createfield();
	void drawfield();
};
#endif