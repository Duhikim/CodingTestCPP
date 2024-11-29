

//1차
/*
int main() {
	int n, sum=0, count=0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		sum += i;
		count++;
	}
	cout << count << '\n' << 1;

	return 0;
} */

//2차
/*
int main() {
	long long int n, sum=0, count = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum += i * j;
			count++;

		}
	}
	cout << count << '\n' << 2 << '\n';

	return 0;
} */

//2차-2
/*
int main() {
	long long int n, count = 0;
	cin >> n;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) { count++; }
	}
	cout << count << '\n' << 2 << '\n';

	return 0;
}
*/

// 3차
/*
int main() {
	long long int n;
	cin >> n;
	cout << n * n * n << '\n' << 3 << '\n';

	return 0;
}
*/


//3차-2
/*
int main() {

	long long int n;
	cin >> n;
	cout << n * (n - 2) * (n - 1) / 6 << '\n' << 3 << '\n';

	return 0;
}
*/


//0차
#include <iostream>
using namespace std;
int main() { int n; cin >> n; cout << 1 << '\n' << 0 << '\n'; return 0; }