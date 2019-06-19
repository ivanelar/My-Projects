#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_ADDS 100

///* Сума, която ще разбиваме */
//const unsigned n = 25;
///* Брой различни стойности на монетите */
//const unsigned gN = 6;
///* Стойности на монетите */
//const unsigned given[] = { 100, 50, 20, 10, 5, 2 };
//
//unsigned mp[MAX_ADDS];
vector<int> given;
void print(unsigned lenght, int *mp)
{
	for (int i = 0; i < lenght; i++){
		//printf("%u + ", mp[i]);
		cout << mp[i] << "+";
	}
	//printf("%d\n", mp[lenght]);
	cout << mp[lenght] << endl;
}

void devNum(unsigned n, unsigned pos, int gN, int *mp, int &cnt)
{
	unsigned k, p;
	for (p = gN; p > 0; p--) {
		k = given[p - 1];
		if (n > k) {
			mp[pos] = k;
			if (mp[pos] <= mp[pos - 1])
			{
				devNum(n - k, pos + 1, gN, mp, cnt);
			}
		}
		else if (n == k) {
			mp[pos] = k;
			if (mp[pos] <= mp[pos - 1]) {
				//print(pos, mp);
				cnt++;
			}
		}
	}
}


int main(void) {

	string line;
	int k;
	while (getline(cin, line))
	{
		istringstream is(line);
		while (is >> k) given.push_back(k);
		string line2;
		getline(cin, line2);
		istringstream is2(line2);
		vector<int> sums;
		while (is2 >> k) sums.push_back(k);


		//reverse(given.begin(), given.end());
		vector<int> result;
		for (vector<int>::iterator i = sums.begin(); i != sums.end(); i++)
		{
			/*vector<int> mp;
			mp.push_back(*i);*/
			int mp [1000];
			mp[0] = *i + 1;
			int cnt = 0;
			devNum(*i, 1, given.size(), mp, cnt);
			result.push_back(cnt);
		}
		
		for (vector<int>::iterator i = result.begin(); i != result.end(); i++)
		{
			cout << *i << " ";
		}
		cout << endl;

		given.clear();

	}
	/*mp[0] = n + 1;
	devNum(n, 1);*/
	return 0;
}


//void print(unsigned lenght, vector<int>mp)
//{
//	for (vector<int>::iterator i = mp.begin(); i != mp.end(); i++)
//	{
//		cout << *i << " + ";
//		if (lenght<0)
//		{
//			break;
//		}
//
//	}
//	cout << endl;
//	//unsigned k;
//	//for (int i = 0; i < lenght; i++){
//	//	//printf("%u + ", mp[i]);
//	//	//cout << mp[i] << "+";
//	//	k++;
//	//}
//	////printf("%d\n", mp[lenght]);
//	////cout << mp[lenght] << endl;
//	//cout << k << endl;
//}