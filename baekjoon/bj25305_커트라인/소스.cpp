#include <iostream>
using namespace std;

int main() {
	int N, k;
	cin >> N >> k;
	int* pArray;
	pArray = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> pArray[i];
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (pArray[j] > pArray[i]) {
				int temp = pArray[i];
				pArray[i] = pArray[j];
				pArray[j] = temp;
			}
		}
	}
	cout << pArray[k - 1] << '\n';
	return 0;
}