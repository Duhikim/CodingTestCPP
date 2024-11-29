#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* pArr;
	pArr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> pArr[i];
	}
	
	int min;
	int max;
	min = pArr[0];
	max = pArr[0];

	for (int i = 1; i < N; i++) {
		if (pArr[i] < min) min = pArr[i];
		else if (pArr[i] > max) max = pArr[i];
	}
		

	printf("%d %d", min, max);

	return 0;
}