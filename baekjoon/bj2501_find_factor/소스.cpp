#include <iostream>
using namespace std;

int main() {
	int N, K, counting=0;
	cin >> N >> K;


	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			counting++;
			if (counting == K) { cout << i << '\n'; }
		}

		if (i == N && counting < K) { cout << 0 << '\n'; }
	}

	return 0;
}