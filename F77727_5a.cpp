#include <iostream>
#include <cmath>
#include <iomanip>
#define NMAX 10000000
using namespace std;

float funCalc(float x){

	float result = (2 * x*x*x) - (7 * x) - 7;//2x3 - 7x - F%100
	return result;
}

int main(){
	//3.4189965453
	float a = -10;
	float b = 10;
	float tol = 0.000001;
	int n = 1;
	float c = 0;
	float funVal = 0;
	float result = 0;
	bool check = true;

	if (a < b && ((funCalc(a) < 0 && funCalc(b) > 0) || (funCalc(a)>0 && funCalc(b) < 0))){
		
		while (n <= NMAX && check)
		{
			c = (a + b) / 2.0;
			if (funCalc(c) == 0 || (float)(b - a)/2 < tol){
				result = c;
				funVal = funCalc(c);
				check = false;
			}

			if ((funCalc(c) > 0 && funCalc(a) > 0) || (funCalc(c) < 0 && funCalc(a) < 0))
			{
				a = c;
			}
			else
			{
				b = c;
			}
			n++;
		}

	}

	if (check){
		cout << "NO SOLUTION" << endl;
	}
	else{
		cout  << fixed << setprecision(10) << result << " ";
		cout << fixed << setprecision(10) << funVal << endl;
	}
	return 0;
}

