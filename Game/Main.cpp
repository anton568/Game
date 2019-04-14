#include <iostream>
#include <stdlib.h>
#include "Board.h"
#include "Ielement.h"
#include "Qelement.h"
#include "Felement.h"
using namespace std;
int main()
{
	Board board;
	IElement ielement;
	QElement qelement;
	FElement felement;
	Board* pboard = &board;
	board.createfield();
	int inox, inoy, intx, inty;
	bool checkthisturn;
	int checknextturn;
	int checkend;
	int checkpositionandturn;
	char tempsymbol;
	int count = 0;
	int checkbegin = 1;
	checkend = 1;
	cout << "Task: remove all items from the field.\n";
	cout << "Elements can move as shown in the pictures:\n";
	cout << " *  *  *                     \n";
	cout << "               *      *   *  \n";
	cout << " *  F  *     * I *      Q    \n";
	cout << "               *      *   *  \n";
	cout << " *  *  *                     \n";
	cout << "Elements are destroyed as shown in the figures:\n";
	cout << "    *  *             *      \n";
	cout << "    F        * I *     Q    \n";
	cout << "                         *  \n";
	system("pause");
	system("cls");
	while ((checkbegin != 0)&&count!=50)
	{
		checkbegin = 0;
		for (int i = 0; i < board.maxx; i++)
		{
			for (int m = 0; m < board.maxy; m++)
			{
				if (board.field[i][m] == ielement.symbol)
				{
					ielement.del(i, m, pboard);
				}
				if (board.field[i][m] == qelement.symbol)
				{
					qelement.del(i, m, pboard);
				}
				if (board.field[i][m] == felement.symbol)
				{
					felement.del(i, m, pboard);
				}
			}
		}
		checknextturn = 1;
		while (checknextturn != 0)
		{
			checknextturn = 0;
			for (int i = board.maxx - 1; i > -1; i--)
			{
				for (int m = board.maxy - 1; m > -1; m--)
				{
					if ((board.field[i][m] == ' ') || (board.checkfield[i][m] == '1'))
					{
						if (i == 0)
						{
							board.field[i][m] = ' ';
							board.checkfield[i][m] = '0';
							checkbegin++;
						}
						else
						{
							board.field[i][m] = board.field[i - 1][m];
							board.field[i - 1][m] = ' ';
							board.checkfield[i][m] = board.checkfield[i - 1][m];
							checkbegin++;
						}
					}
				}
			}
			for (int i = board.maxx - 1; i > -1; i--)
			{
				for (int m = board.maxy - 1; m > -1; m--)
				{
					if (board.checkfield[i][m] == '1')
						checknextturn++;
				}
			}
		}
		for (int i = 0; i < board.maxx; i++)
		{
			for (int m = 0; m < board.maxy; m++)
			{
				if ((rand() % 3) == 0)
				{
					board.field[i][m] = felement.symbol;
				}
				else
				{
					if ((rand() % 3) == 1)
					{
						board.field[i][m] = ielement.symbol;
					}
					else
					{
						board.field[i][m] = qelement.symbol;
					}
				}
			}
		}
		count++;
	}
	checknextturn = 1;
	while (checkend != 0)
	{
		checknextturn = 1;
		checkpositionandturn = 1;
		board.drawfield();
		while (checkpositionandturn != 0)
		{
			checkpositionandturn = 0;
			cout << "Input coordinates x,y one element\n" ;
			cin >> inoy;
			cin >> inox;
			if ((inox > board.maxx-1) || (inoy > board.maxy-1))
			{
				cout<<"Wrong one position";
				checkpositionandturn++;
			}
			cout << board.field[inox][inoy];
			cout << "Input coordinates x,y two element\n";
			cin >> inty;
			cin >> intx;
			if ((intx > board.maxx-1) || (inty > board.maxy-1))
			{
				cout<<"Wrong one position";
				checkpositionandturn++;
			}
			cout << board.field[intx][inty];
			if (board.field[inox][inoy] == ielement.symbol)
			{
				checkthisturn = ielement.check(inox, inoy, intx, inty/*, pboard*/);
			}
			else
			{
				if (board.field[inox][inoy] == qelement.symbol)
				{
					checkthisturn = qelement.check(inox, inoy, intx, inty/*, pboard*/);
				}
				else
				{
					if (board.field[inox][inoy] == felement.symbol)
					{
						checkthisturn = felement.check(inox, inoy, intx, inty/*, pboard*/);
					}
					else
					{
						cout << "Wrong one position";
						checkpositionandturn++;
					}
				}
			}
		}
		cout << checkthisturn << "\n";
		if (checkthisturn == true)
		{
			tempsymbol = board.field[inox][inoy];
			board.field[inox][inoy] = board.field[intx][inty];
			board.field[intx][inty] = tempsymbol;
		
			for (int i = 0; i < board.maxx; i++)
			{
				for (int m = 0; m < board.maxy; m++)
				{
					if (board.field[i][m] == ielement.symbol)
					{
						ielement.del(i, m, pboard);
					}
					if (board.field[i][m] == qelement.symbol)
					{
						qelement.del(i, m, pboard);
					}
					if (board.field[i][m] == felement.symbol)
					{
						felement.del(i, m, pboard);
					}
				}
			}
		}
		while (checknextturn != 0)
		{
			checknextturn = 0;
			for (int i = board.maxx - 1; i > -1; i--)
			{
				for (int m = board.maxy - 1; m > -1; m--)
				{
					if ((board.field[i][m] == ' ') || (board.checkfield[i][m] == '1'))
					{
						if (i == 0)
						{
							board.field[i][m] = ' ';
							board.checkfield[i][m] = '0';
						}
						else
						{
							board.field[i][m] = board.field[i - 1][m];
							board.field[i - 1][m] = ' ';
							board.checkfield[i][m] = board.checkfield[i - 1][m];
						}
					}
				}
			}
			for (int i = board.maxx - 1; i > -1; i--)
			{
				for (int m = board.maxy - 1; m > -1; m--)
				{
					if (board.checkfield[i][m] == '1')
						checknextturn++;
				}
			}
		}
		checkend = 0;
		for (int i = board.maxx - 1; i > -1; i--)
		{
			for (int m = board.maxy - 1; m > -1; m--)
			{
				if (board.checkfield[i][m] != ' ')
					checkend++;
			}
		}
		system("cls");
	}
	
	
}