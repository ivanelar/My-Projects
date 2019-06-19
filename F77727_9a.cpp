#include <iostream>
#include <cstring>

using namespace std;

int const MAXN = 110;
int const MAX_VALUE = 111;

int A[MAXN][MAXN];
int n;
int T[MAXN];
int d[MAXN];
int pred[MAXN];

void dijkstra(int s)
{
	for (int i = 0; i < n; i++)
	{
		if (A[s][i] == 0)
		{
			d[i] = MAX_VALUE;
			pred[i] = -1;
		}
		else
		{
			d[i] = A[s][i];
			pred[i] = s;
		}
	}

	for (int i = 0; i < n; i++)
		T[i] = 1;

	T[s] = 0;
	pred[s] = -1;

	while (true)
	{
		int j = -1;
		int di = MAX_VALUE;

		for (int i = 0; i < n; i++)
		{
			if (T[i] && d[i] < di)
			{
				di = d[i];
				j = i;
			}
		}

		if (j == -1)
		{
			break;
		}

		T[j] = 0;

		for (int i = 0; i < n; i++)
		{
			if (T[i] && A[j][i] != 0)
			{
				if (d[i] > d[j] + A[j][i])
				{
					d[i] = d[j] + A[j][i];
					pred[i] = j;
				}
			}
		}
	}
}

void printResult(int s)
{
	for (int i = 0; i < n; i++)
	{
		if (i == s)
		{
			cout << " " << "0";
		}
		else
		{
			if (d[i] == MAX_VALUE)
			{
				cout << " " << "-1";
			}
			else
			{
				cout << " " << d[i];
			}
		}
	}
}

int main()
{
	int t;
	int x, y, z;

	while (cin >> t)
	{
		n = 0;
		memset(A, 0, MAXN*MAXN);
		for (int i = 0; i < t; ++i)
		{
			cin >> x >> y >> z;
			n = n > x ? n : x;
			n = n > y ? n : y;
			A[x - 1][y - 1] = z;
		}
		for (int i = 0; i < n; ++i)
		{
			dijkstra(i);
			printResult(i);
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
/*
Задача 9а. [5.4.2, стр. 272] dijkstra.c
Даден е ориентиран граф с положителни тегла на дъгите. Да се намери минимален път от зададен връх до всички други
върхове на графа.
Вход:
На входа се задава най-напред броя на дъгите на ориентиран граф, а после списък от тези дъги и техните дължини.
Списъкът се състои от не повече от 100 дъги, зададени с двойки номера на върхове (начало, край) и дължината на дъгата.
Върховете на графа са номерирани с последователни цели положителни числа, започвайки от 1. Входът съдържа много примери.
Изход:
За всеки пример на нов ред се отпечатва редица от дължините на минималните пътища от връх с номер 1, номер 2 и т.н.
до всички върхове последователно, според номерацията на върховете. Ако няма път се отпечатва -1. Примерите се отделят
с празен ред.
Пример:
3
1 2 1
2 3 1
1 4 2
2
1 2 4
2 1 5
Решение на примера:
0 1 2 2
-1 0 1 -1
-1 -1 0 -1
-1 -1 -1 0

0 4
5 0
*/

