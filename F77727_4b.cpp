#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool string_sort(string a, string b)
{
	if (a.length() == b.length())
	{
		return a < b;
	} else
	{
		return a.length() < b.length();
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		unsigned long long size = 0;
		cin >> size;
		vector<string> vec;
		for (int i = 0; i < size; i++)
		{
			string stmp;
			cin >> stmp;
			vec.push_back(stmp);
		}

		sort(vec.begin(), vec.end(), string_sort);

		if (size % 2 == 0)
		{
			string fel = vec[size / 2];
			string sel = vec[(size / 2) - 1];
			if (fel.length() == sel.length())
			{
				if (fel > sel)
				{
					cout << sel << endl;
				}
				else
				{
					cout << fel << endl;
				}
			}
			else
			{
				if (fel.length() > sel.length())
				{
					cout << sel << endl;
				}
				else
				{
					cout << fel << endl;
				}
			}
		}
		else
		{
			cout << vec[size / 2] << endl;
		}
		
	}

	return 0;
}