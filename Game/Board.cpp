#include "Board.h"
#include <stdlib.h>
using namespace  std;

#include "Qelement.h"
#include "Felement.h"
#include "Ielement.h"
QElement qelement;
FElement felement;
IElement ielement;
void Board::createfield()
{
	for (int i = 0; i < maxx; i++)
	{
		for (int m = 0; m < maxy; m++)
		{
			if ((rand() % 3) == 0)
			{
				field[i][m] = felement.symbol;
			}
			else
			{
				if ((rand() % 3) == 1)
				{
					field[i][m] = ielement.symbol;
				}
				else
				{
					field[i][m] = qelement.symbol;
				}
			}
		}
	}
	for (int i = 0; i < maxx; i++)
	{
		for (int m = 0; m < maxy; m++)
		{
			checkfield[i][m] = '0';
		}
	}
}

void Board::drawfield()
{
	for (int i = 0; i < maxx; i++)
	{
		for (int m = 0; m < maxy; m++)
		{
				cout << field[i][m];
		}
		cout << "\n";
	}
}
