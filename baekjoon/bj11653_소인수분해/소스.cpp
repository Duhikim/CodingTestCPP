#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N > 1) {
		int start = 2;
		for (int i = start; i <= N; i++) {
			if (N % i == 0) { N /= i; printf("%d\n", i); start = i; break; }

		}


	}
	
	return 0;

}
