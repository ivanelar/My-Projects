/*Да се напише програма, която намира броя на простите числа в случайно генерирана редица от 10000 числа.*/

#include<iostream>
#include<cstdlib>
using namespace std;
int divideNum(int n){
    int cnt = 0;
    for(int a = 1; a <= n; a++){
        if(n%a == 0){
            cnt++;
        }
    }
    return cnt;
}
int main()
{
int s = 10000;
int arr[s],i,numPrime = 0;
for(int i=0; i<s; i++){
        arr[i] = (rand()%10000)+1;
 }


cout<<"Prime numbers are: ";
//Print the array.
for(i=0;i<s;i++)
{

if(divideNum(arr[i]) < 3){
    numPrime++;
}
}
cout << numPrime;
}
