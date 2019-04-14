#ifndef FELEMENT_H
#define FELEMENT_H
#include "Board.h"
#include "Move.h"
class FElement : public Move {
public:
	char symbol = 'F';
	bool check(int onex, int oney, int twox, int twoy/*, Board* p*/);
	void del(int delx, int dely, Board* p);
};
#endif