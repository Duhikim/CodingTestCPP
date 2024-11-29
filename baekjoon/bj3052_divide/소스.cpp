#include <iostream>
using namespace std;

int main() {
	int numbers[10];
	for (int i = 0; i < 10; i++) {	cin >> numbers[i];	}
	for (int i = 0; i < 10; i++) { numbers[i] = numbers[i] % 42; }

	int counting=10;

	for (int i = 0; i < 10; i++) {
		for (int j = i+1; j < 10; j++) {
			if (numbers[i] == 42) {}
			else if (numbers[i] == numbers[j]) { numbers[j] = 42, counting--; }
		}
	}
	cout << counting << '\n';

	return 0;
}