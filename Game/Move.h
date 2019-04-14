#ifndef MOVE_H
#define MOVE_H
class Move {
	virtual bool check(int onex,int oney,int twox, int twoy)=0;
	virtual void del(int delx, int dely,Board* p)=0;
};
#endif