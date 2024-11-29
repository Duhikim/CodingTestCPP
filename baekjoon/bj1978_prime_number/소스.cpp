#include <iostream>
using namespace std;

int main() {
	int N, counting=0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		bool primenum = 1;
		cin >> num;
		for (int j = 2; j < num; j++) {
			if (num % j == 0) { primenum = 0; break; }
		}
		if (num != 1 && primenum) counting++;

	}
	cout << counting << '\n';
	return 0;
}