#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool stringSort(char a, char b)
{
	return a > b;
}

int main()
{
	string s;

	while (cin >> s)
	{
		sort(s.begin(), s.end(), stringSort);
		cout << s << endl;
	}
	
	return 0;
}