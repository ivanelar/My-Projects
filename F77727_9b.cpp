#include <iostream>
#include <cstring>

using namespace std;

int const MAXN = 1010;
int const MAX_VALUE = 1011;

int A[MAXN][MAXN];
int used[MAXN];
unsigned minCycle[MAXN];
unsigned cycle[MAXN];
unsigned n;
int curSum;
int minSum;

void printCycle()
{
	unsigned i;
	if (minCycle[0])
	{
		cout << "1";
		for (i = 0; i < n - 1; i++)
		{
			cout << " " << minCycle[i] + 1;
		}
		cout << endl;
	}
	else
	{
		cout << "-1" << endl;
	}
}

void hamilton(unsigned i, unsigned level)
{
	unsigned k;
	if ((0 == i) && (level > 0))
	{
		if (level == n)
		{
			minSum = curSum;
			for (k = 0; k < n; k++)
				minCycle[k] = cycle[k];
		}
		return;
	}

	if (used[i])
	{
		return;
	}

	used[i] = 1;

	for (k = 0; k < n; k++)
	{
		if (A[i][k] && k != i)
		{
			cycle[level] = k;
			curSum += A[i][k];
			if (curSum < minSum)
				hamilton(k, level + 1);
			curSum -= A[i][k];
		}
	}
	used[i] = 0;
}

int main()
{

	unsigned t;
	unsigned x, y, z;

	while (cin >> t)
	{
		n = 0;
		memset(used, 0, MAXN);
		memset(minCycle, 0, MAXN);
		memset(A, 0, MAXN*MAXN);
		minSum = MAX_VALUE;
		curSum = 0;
		cycle[0] = 1;

		for (unsigned i = 0; i < t; ++i)
		{
			cin >> x >> y >> z;
			n = n>x ? n : x;
			n = n>y ? n : y;
			A[x - 1][y - 1] = z;
			A[y - 1][x - 1] = z;
		}
		hamilton(0, 0);
		printCycle();
	}
	return 0;
}
