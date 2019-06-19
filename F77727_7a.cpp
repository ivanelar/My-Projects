
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#define MAX 100
#define MAXVALUE 200

unsigned char can[MAX * MAXVALUE];
vector<unsigned> m;
unsigned n = 0;

void calc()
{ 
  unsigned long p, i, j;
  for (p = i = 0; i < n; p += m[i++]);
  for (i = 0; i <= p; i++) {
    can[i] = 0;
  }

  can[0] = 1;

  for (i = 0; i < n; i++) {
     for (j = p; j + 1 > 0; j--) {
        if (can[j]) can[j + m[i]] = 1;
     }
  }
  
  for (i = p/2; i > 1; i--) {
    if (can[i]) { 
      cout << i << " " << p-i << endl;
      return;
    }    
  }
}

int main()
{ 
  unsigned long num;
  string line;
  while(getline(cin, line)) {
    istringstream istr(line);
    m.clear();
    while(istr >> num) {
      m.push_back(num);
    }
    n = m.size();
    calc();
  }
  return 0;  
}
