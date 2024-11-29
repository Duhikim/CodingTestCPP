#include <iostream>
#include <string>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    while (testCase-- != 0) {
        int repeatTime;
        string word;
        string S = "";
        cin >> repeatTime >> word;
        for (char c : word) {
            for (int i = 0; i < repeatTime; i++) {
                S.push_back(c);
            }
        }
        cout << S << '\n';
    }
    return 0;
}