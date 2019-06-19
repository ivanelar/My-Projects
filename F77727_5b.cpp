#include <iostream>
#include <iomanip>
using namespace std;
/* Максимален размер на дъската */
#define MAXN 10
/* Максимален брой правила за движение на коня */
#define MAXD 10

/* Размер на дъската */
unsigned n = 6;
/* Стартова позиция */
unsigned startX = 6;
unsigned startY = 1;
/* Правила за движение на коня */
const unsigned maxDiff = 8;
const int diffX[MAXD] = { 1, 1, -1, -1, 2, -2, 2, -2 };
const int diffY[MAXD] = { 2, -2, 2, -2, 1, 1, -1, -1 };

unsigned board[MAXN][MAXN];
unsigned newX, newY;

void printBoard()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(3) << board[i - 1][j];
		}
		cout << endl;
	}
	//exit(0);  /* изход от програмата */
}
bool check = false;
void nextMove(unsigned X, unsigned Y, unsigned i)
{
	board[X][Y] = i;
	if (i == n * n)
	{
		printBoard(); 
		check = true;
		return;
	}
	if (check)
	{
		return;
	}
	for (int k = 0; k < maxDiff; k++) {
		newX = X + diffX[k]; newY = Y + diffY[k];
		if ((newX >= 0 && newX < n && newY >= 0 && newY < n) && (0 == board[newX][newY]))
		{
			nextMove(newX, newY, i + 1);
		}
	}
	board[X][Y] = 0;
}

int main() {

	while (cin >> n)
	{
		cin >> startX;
		cin >> startY;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				board[i][j] = 0;
			}
		}

		nextMove(startX - 1, startY - 1, 1);
		if (!check)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << setw(3) << board[i][j];
				}
				cout << endl;
			}

		}
		check = false;
		cout << endl;
		//cout << "Задачата няма решение." << endl;
	}

	return 0;
}