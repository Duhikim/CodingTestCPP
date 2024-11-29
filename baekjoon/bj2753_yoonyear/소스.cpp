#include <iostream>
using namespace std;

int main() {

	int yearinput;
	cin >> yearinput;

	if (yearinput % 400 == 0) {
		cout << 1 << '\n';
	}
	else if (((yearinput % 4) == 0) && ((yearinput % 100) != 0)) {
		cout << 1 << '\n';
	}
	else cout << 0 << '\n';

	return 0;
}