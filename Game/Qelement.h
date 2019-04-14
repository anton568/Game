#ifndef QELEMENT_H
#define QELEMENT_H
#include "Board.h"
#include "Move.h"
class QElement : public Move {
public:
	char symbol = 'Q';
	bool check(int onex, int oney, int twox, int twoy);
	void del(int delx, int dely, Board* p);

};
#endif