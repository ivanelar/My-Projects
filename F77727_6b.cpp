#include <iostream>
#include <string>
#include <map>
 
using namespace std;
static const int MAX = 100000;

int n, m;
string num;
 
int main() 
{
       
  while(cin >> n) {

    m = n;
    if(m >= MAX) {
      continue;
    }
    map<string, unsigned> majorant;
    string element, maxEl;
    while(n--) {
        cin >> element;
        majorant[element]++;
        if(majorant[element] > m/2) {
            maxEl = element;
        }
    }
    cout << maxEl << endl;
  }
  return 0;
}
