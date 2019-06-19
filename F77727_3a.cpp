#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

template <typename T>
string ToString(T Number)
{
	ostringstream ss;
	ss << Number;
	return ss.str();
}

string check(int n, int sum, vector<int> a)
{
	string res = "";
	unsigned i;
	int tempSum = 0;
	vector<string> result;
	result.push_back("");
	for (i = 0; i < n; i++) tempSum += a[i];
	if (tempSum == sum) {
		for (i = 0; i < n; i++)
		{
			if (a[i] > 0) {

				result[0] = result[0] + "+" + ToString(a[i]);

			}
			else {

				result[0] = result[0] + ToString(a[i]);
			}
		}
		if (result[0][0] == '+')
		{
			res = result[0].replace(0, 1, "") + '=' + ToString(tempSum);
		}
	}

	return res;
}

vector<string> print;
void variate(unsigned i, int n, vector<int> a, int sum)
{


	if (i >= n) {

		string b = check(n, sum, a);
		if (b != "")
		{
			print.push_back(b);
		}

		return;

	}

	a[i] = abs(a[i]);
	variate(i + 1, n, a, sum);
	a[i] = -abs(a[i]);
	variate(i + 1, n, a, sum);


}

int main() {


	string line;
	int k;
	while (getline(cin, line))
	{
		vector<int> v;
		istringstream is(line);
		while (is >> k) v.push_back(k);
		variate(0, v.size() - 1, v, v[v.size() - 1]);

		if (print.empty())
		{
			cout << endl;
		}
		else
		{
			for (vector<string>::iterator i = print.begin(); i != print.end(); i++)
			{
				cout << *i << endl;
				break;
			}
		}

		print.clear();

	}

	return 0;
}
