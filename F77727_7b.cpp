#include <iostream>

using namespace std;

#define MAXN 150

unsigned n;
unsigned s;

unsigned A[MAXN][MAXN]={0};

const int MAX_VALUE = 10000;

unsigned T[MAXN], d[MAXN];
int pred[MAXN];


void dijkstra(unsigned s)
{ unsigned i;
    for (i = 0; i < n; i++)
        if (A[s][i] == 0) {
            d[i] = MAX_VALUE; pred[i] = -1;
        }
        else {
            d[i] = A[s][i]; pred[i] = s;
        }
    for (i = 0; i < n; i++) T[i] = 1;
    T[s] = 0;
    pred[s] = -1;
    
    while (1) {

        int j = -1;
        int di = MAX_VALUE;
        
        for (i = 0; i < n; i++)
            if (T[i] && d[i] < di) {
                di = d[i];
                j = i;
            }
        if (j == -1) break;
        T[j] = 0;
        
    
        for (i = 0; i < n; i++)
            if (T[i] && A[j][i] != 0)
                if (d[i] > d[j] + A[j][i]) {
                    d[i] = d[j] + A[j][i];
                    pred[i] = j;
                }
    }
}

void printResult(unsigned s)
{ 
  unsigned i;
  for (i = 0; i < n; i++) {
    if (d[i] == MAX_VALUE) {
      if(i==s) {
        cout << 0 << " ";
      } else {
        cout << -1 << " ";
      }
    } else {
      cout << d[i] << " ";
    }
  }
  cout << endl;
}

int main() 
{
  int e;
  while(cin >> e) {
      int max=0;
      for(int k=0; k<e; k++) {
          int i,j,w;
          cin >> i >> j >> w;
          A[i-1][j-1]=w;
          max = (i>max)?i:max;
          max = (j>max)?j:max;
      }
      n = max;
      for(int p=1; p<=max; p++) {
          s=p;
          dijkstra(s-1);
          printResult(s-1);
      }
      cout << endl;
  }
  return 0;
}
