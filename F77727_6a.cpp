#include <iostream>
#include <string>
#include <sstream>

using namespace std;
string k;
string m;

void calculate(int n, int l)
{
  if(n > l) {
    n = (n%l);
  }
  for (int i=0; i < l; i++) {
    if(n >= l) {
      n=0;
    }
    cout << k[n];
    n++;
  }
  cout << endl;
}

int main()
{
  int numb, leng;
  while(getline(cin, m)) {
    k = m;
    leng = k.length();
    getline(cin, m);
    istringstream istr(m);
    while(istr >> numb) {
      calculate(numb, leng);
    }
  }
  return 0;
}
