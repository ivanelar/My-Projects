#include <iostream>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

int main() 
{
    set<string> sSet;
    string line, word;
    while(getline(cin, line)) {
        stringstream strStream(line);
        while(strStream >> word) {
            sort(word.begin(), word.end());
            sSet.insert(word);
        }
        cout << sSet.size() << endl;
        sSet.clear();
    }

    return 0;
}
