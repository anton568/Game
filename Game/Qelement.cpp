#include "Qelement.h"



bool QElement::check(int onex, int oney, int twox, int twoy) {
	if (((twox-onex)*(twox-onex)==1)&& ((twoy - oney)*(twoy - oney) == 1))
		return true;
	else
		return false;
}
void QElement::del(int delx, int dely, Board* p) {
	if ((*p).field[delx + 1][dely + 1] == symbol)

	{
		if ((*p).field[delx + 2][dely + 2] == symbol)
		{
			if ((dely + 2 > (*p).maxy - 1) || (dely + 1 > (*p).maxy - 1)|| (delx + 2 > (*p).maxy - 1) || (delx + 1 > (*p).maxy - 1))
			{
			}
			else
			{
				(*p).checkfield[delx][dely] = '1';
				(*p).checkfield[delx+1][dely + 1] = '1';
				(*p).checkfield[delx+2][dely + 2] = '1';
			}
		}
		else if ((*p).field[delx - 1][dely - 1] == symbol)
		{
			if ((dely - 1 <-1) || (dely + 1 > (*p).maxy - 1) || (delx - 1 <-1) || (delx + 1 > (*p).maxy - 1))
			{
			}
			else
			{
				(*p).checkfield[delx][dely] = '1';
				(*p).checkfield[delx + 1][dely + 1] = '1';
				(*p).checkfield[delx - 1][dely - 1] = '1';
			}
		}
	}
	if ((*p).field[delx - 1][dely - 1] == symbol)
	{
		if ((*p).field[delx - 2][dely - 2] == symbol)
		{
			if ((dely - 1 < 0) || (dely - 2 < 0)|| (delx - 1 < 0) || (delx - 2 < 0))
			{
			}
			else
			{
				(*p).checkfield[delx][dely] = '1';
				(*p).checkfield[delx - 1][dely - 1] = '1';
				(*p).checkfield[delx - 2][dely - 2] = '1';
			}
		}
		else if ((*p).field[delx + 1][dely + 1] == symbol)
		{
			if ((dely + 1 > (*p).maxy - 1) || (dely - 1 < 0)|| (delx + 1 > (*p).maxx - 1) || (delx - 1 < 0))
			{
			}
			else
			{
				(*p).checkfield[delx][dely] = '1';
				(*p).checkfield[delx - 1][dely - 1] = '1';
				(*p).checkfield[delx + 1][dely + 1] = '1';
			}
		}
	}
	if ((*p).field[delx - 1][dely + 1] == symbol)
	{
		if ((*p).field[delx - 2][dely + 2] == symbol)
		{
			if ((delx - 1 < 0) || (delx - 2 < 0)|| (dely + 1 > (*p).maxy - 1) || (dely + 2 > (*p).maxy - 1))
			{
			}
			else
			{
				(*p).checkfield[delx][dely] = '1';
				(*p).checkfield[delx - 1][dely + 1] = '1';
				(*p).checkfield[delx - 2][dely + 2] = '1';
			}
		}
		else if ((*p).field[delx + 1][dely - 1] == symbol)
		{
			if ((delx + 1 > (*p).maxx - 1) || (delx - 1 < 0)|| (dely + 1 > (*p).maxy - 1) || (dely - 1 < 0))
			{
			}
			else
			{
				(*p).checkfield[delx][dely] = '1';
				(*p).checkfield[delx - 1][dely + 1] = '1';
				(*p).checkfield[delx + 1][dely - 1] = '1';
			}
		}
	}
	if ((*p).field[delx + 1][dely - 1] == symbol)
	{
		if ((*p).field[delx + 2][dely - 2] == symbol)
		{
			if ((delx + 1 > (*p).maxx - 1) || (delx + 2 > (*p).maxx - 1)|| (dely - 1 < 0) || (dely - 2 < 0))
			{
			}
			else
			{
				(*p).checkfield[delx][dely] = '1';
				(*p).checkfield[delx + 1][dely - 1] = '1';
				(*p).checkfield[delx + 2][dely - 2] = '1';
			}
		}
		else if ((*p).field[delx - 1][dely + 1] == symbol)
		{
			if ((delx + 1 > (*p).maxx - 1) || (delx - 1 < 0)|| (dely + 1 > (*p).maxx - 1) || (dely - 1 < 0))
			{
			}
			else
			{
				(*p).checkfield[delx][dely] = '1';
				(*p).checkfield[delx + 1][dely - 1] = '1';
				(*p).checkfield[delx - 1][dely + 1] = '1';
			}
		}
	}
}
