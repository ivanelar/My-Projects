#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int a;
	int b;
	int c;
	int d;
	

	while (cin >> a)
	{
		cin.ignore();
		cin >> b;
		cin.ignore();
		cin.ignore();
		cin.ignore();
		cin >> c;
		cin.ignore();
		cin >> d;
		
		int numerator = a * d + b * c;
		int denominator =  b*d;
		
		int devider = gcd(numerator, denominator);

		if (denominator / devider == 1)
		{
			cout << numerator / devider << endl;
		} else
		{
			cout << numerator / devider << "/" << (denominator / devider) << endl;
		}
		
	}

	return 0;
}