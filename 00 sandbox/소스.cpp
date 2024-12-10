#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
using namespace std;

int main() {
   
    vector<int> a = { 1,2,3,4,5 };
    vector<int> b = a;
    for (int num : b) cout << num; cout << '\n';

    a[4] = 0;
    for (int num : a) cout << num; cout << '\n';
    for (int num : b) cout << num; cout << '\n';

    list<int> c = { 1,2,3,4,5 };
    list<int> d = c;
    for (int num : d) cout << num; cout << '\n';

    c.push_back(10);
    for (int num : c) cout << num; cout << '\n';
    for (int num : d) cout << num; cout << '\n';
    
    return 0;
}