#include <iostream>
using namespace std;

int main() {
	while (true) {
		int A, B;
		cin >> A >> B;

		if (A == 0 && B == 0) return 0;

		if (B % A == 0) { cout << "factor" << '\n'; }
		else if (A % B == 0) { cout << "multiple" << '\n'; }
		else { cout << "neither" << '\n'; }

	}

	return 0;
}