#include <iostream>
using namespace std;

int main() {	
	while (true) {
		int n, m;
		cin >> n >> m;

		int N = 1, M = 1;
		if (n == 1 || n == 3 || n == 4) N = 0;
		if (m == 1 || m == 3 || m == 4) M = 0;

		if (n == m || ((N | M) == 0)) {
			cout << "=" << endl;
		}
		else if (N == 0) {
			cout << "<" << endl;
		}
		else if (M == 0) {
			cout << ">" << endl;
		}
		else if (n - m == 2 || n - m == 3 || n - m == -5) {
			cout << "<" << endl;
		}
		else {
			cout << ">" << endl;
		}
	}
	return 0;
}