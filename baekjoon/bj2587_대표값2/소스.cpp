#include <iostream>
using namespace std;



int main() {
	int array[5];
	int sum=0;

	for (int i = 0; i < 5; i++) {
		cin >> array[i];
		sum += array[i];
	}
	cout << sum / 5 << '\n';

	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (array[j] < array[i]) {
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	cout << array[2] << '\n';
	return 0;

}
