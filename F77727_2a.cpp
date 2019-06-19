/*«адача 2а. ƒа се напише програма, ко€то намира бро€ на простите числа в случайно генерирана редица.*/

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
int s;
cout << "Input N(size): ";
cin >> s;
int *arr,i,numPrime = 0;
arr = new int[s];
for(int i=0; i<s; i++){
        arr[i] = (rand()%10000)+1;
        cout << arr[i] << " ";
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
delete arr;
}
