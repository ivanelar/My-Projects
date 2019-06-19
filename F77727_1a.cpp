/*Задача 1а. Да се напише програма за превръщане на естествено
число от запис в двоична, осмична и шестнадесетична бройни системи в запис в десетична бройна система. */

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int binaryToDecimal(long long n)
{
    int dec = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        dec += remainder*pow(2,i);
        ++i;
    }
    return dec;
}

int octalToDecimal(int o)
{
    int dec = 0, i = 0, rem;
    while (o != 0)
    {
        rem = o % 10;
        o /= 10;
        dec += rem * pow(8, i);
        ++i;
    }
    return dec;
}


unsigned long hexadecimalToDecimal(string h)
{
    unsigned long dec = 0;
    for (int i=0; i<h.length(); i++) {
        if (h[i]>=48 && h[i]<=57)
        {
            dec += (h[i]-48)*pow(16,h.length()-i-1);
        } else if (h[i]>=65 && h[i]<=70) {
            dec += (h[i]-55)*pow(16,h.length( )-i-1);
        } else if (h[i]>=97 && h[i]<=102) {
            dec += (h[i]-87)*pow(16,h.length()-i-1);
        }
    }
    return dec;
}


int main()
{
   long long bin;
   int oct;
   string hex;

   cout << "Enter a binary number: ";
   cin >> bin;
   cout << bin << " in binary = " << binaryToDecimal(bin) << " in decimal" << endl;

   cout << "Enter an octal number: ";
   cin >> oct;
   cout << oct << " in octal = " << octalToDecimal(oct) << " in decimal" << endl;

   cout << "Enter a hexadecimal number: ";
   cin >> hex;
   cout << hex << " in hexadecimal = " << hexadecimalToDecimal(hex) << " in decimal" << endl;

    return 0;
}
