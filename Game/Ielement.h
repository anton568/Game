#ifndef IELEMENT_H
#define IELEMENT_H
#include "Board.h"
#include "Move.h"
class IElement :public Move {
public:
	char symbol = 'I';
	bool check(int onex, int oney, int twox, int twoy);
	void del(int delx, int dely, Board* p);
};
#endif