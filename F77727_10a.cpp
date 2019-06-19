#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

int const MAX_PRIME = 100000001;

bool numbers[MAX_PRIME];
int found_primes;

void initial_primes(bool x[])
{
	found_primes = 2;
	x[0] = x[1] = true;
}

void not_prime(bool x[], int last_prime, int max_prime)
{
    int sumL=last_prime+last_prime;
	for(int i = sumL ; i < MAX_PRIME; i+=last_prime)
    {
      x[i] = true;
	}
}

int nextprime(bool x[], int last_prime, int max_prime)
{
	int result = last_prime+1;
	for(int i = result; i < max_prime; ++result)
    {
		if(!x[result])
        {
            break;
        }
	}
	return result;
}

void fill_primes(bool x[], int max_prime)
{
	if(max_prime >= MAX_PRIME)
    {
      max_prime = MAX_PRIME-1;
    }
	if(found_primes < max_prime)
    {
		do
		{
			not_prime(x, found_primes, max_prime);
		} while((found_primes=nextprime(x, found_primes, max_prime)) <= max_prime);
	}
}

int primes_range(bool x[], int a, int b)
{
	int cnt = 0;
	if(a < 0)
    {
      a = 0;
    }
	if (b >= MAX_PRIME)
    {
       b= MAX_PRIME-1;
    }
	fill_primes(x,b);
	for(int i = a; i <=b; ++i)
    {
		if(!x[i])
			cnt++;
	}
	return cnt;
}

int small_delitel(bool x[], int num)
{
	int result;
	fill_primes(x, num);
	for(int i = 0; i <= num; ++i)
    {
		if(!x[i] && num%i==0)
		{
			result = i;
			break;
		}
	}
	return result;
}

int is_prime(bool x[], int num)
{
	if(num < 0 || num >= MAX_PRIME)
    {
      return 0;
    }
	fill_primes(x, num);
	return x[num]?0:1;
}

int rev_prime(bool x[], int num)
{
	char tmp[10];
	sprintf(tmp, "%d", num);
	reverse(tmp, tmp+strlen(tmp));
	num = atoi(tmp);

	return is_prime(x, num);
}

void cl_primes(bool x[], int num)
{
	bool found = false;
	if(is_prime(x, num))
    {
		cout << num << endl;
		return;
	}

	for(int i = 1; i < MAX_PRIME; ++i)
    {
		if(is_prime(x, num-i))
		{
			cout << num-i;
			found = true;
		}
		if(is_prime(x, num+i))
		{
			cout << (found?" ":"") << num+i;
            found = true;
		}
		if(found)
		{
			cout << endl;
			break;
		}
	}
}

int primes_littleK(bool x[], int num)
{
	return primes_range(x, 0, num-1);
}


int main()
{
	string ch;
	int a, b;
	initial_primes(numbers);

	while(cin >> ch)
    {
		if(ch == "quit")
        {
			break;
		}
		switch(toupper(ch[0]))
      {
		case 'A':cin >> a >> b;cout << primes_range(numbers, a, b) << endl;break;
		case 'B':cin >> a;cout << small_delitel(numbers, a) << endl;break;
		case 'C':cin >> a;cout << is_prime(numbers, a) << endl;	break;
		case 'D':cin >> a;cout <<rev_prime(numbers, a) << endl;	break;
		case 'E':cin >> a;cl_primes(numbers, a);break;
		case 'F':cin >> a;cout << primes_littleK(numbers, a) << endl;break;
	  }
	}
	return 0;
}
