#include <iostream>
using namespace std;

int main() {
//	bool debug = //true;
//				false;

	int N, M;
	cin >> N >> M;
	int* numbers;
	numbers = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
		if (numbers[i] >= M) numbers[i] = 0;
	}
	//if (debug) { for (int i = 0; i < N; i++) cout << numbers[i] << " "; cout << '\n'; }

	int max = 0;
	for (int i = 0; i < N-2; i++) {
		if (numbers[i]) {
			for (int j = i + 1; j < N-1; j++) {
				if (numbers[j]) {
					for (int k = j + 1; k < N; k++) {
						int temp = numbers[i] + numbers[j] + numbers[k];
						if (temp == M) { //if (debug) { cout << numbers[i] << " + " << numbers[j] << " + " << numbers[k] << " = " << M << '\n'; } 
						cout << M << '\n'; return 0; }
						if (temp < M) {
							max = (temp > max) ? temp : max;
						}
					}
				}
			}
		}

	}
	cout << max << '\n';

	return 0;

}