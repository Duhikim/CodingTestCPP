#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	int fib[41][2];	
	fib[0][0] = 1, fib[0][1] = 0;
	fib[1][0] = 0, fib[1][1] = 1;

	for(int i=2; i<=40; i++) {
		fib[i][0] = fib[i - 1][0] + fib[i - 2][0];
		fib[i][1] = fib[i - 1][1] + fib[i - 2][1];
	}

	while (T--) {
		int N;
		cin >> N;		

		cout << fib[N][0] << " " << fib[N][1] << endl;
	}
	return 0;
}