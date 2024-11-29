#include <iostream>
using namespace std;

int main() {
	string S;
	cin >> S;
	int len = S.length();

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < len; j++) {
			if (S[j] == (i + 'a')) { cout << j << " "; break; }
			else if (j == len - 1) { cout << -1 << " "; }
		}
	}
	cout << '\n';
	return 0;
}