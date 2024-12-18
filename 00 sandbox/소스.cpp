#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

long long F(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;

    long long prev_prev = 1;
    long long  prev = 1;
    long long curr = 0;
    for (int i = 2; i <= n; i++) {
        curr = prev + prev_prev;
        prev_prev = prev;
        prev = curr;
        
    }
    return curr;
}

int main() {
    int n;
    while (cin >> n && n >= 0) {
        cout << "Fibonacci[" << n << "] = " << F(n) << '\n';
    }
    cout << "프로그램 종료\n";
   
    return 0;
}
