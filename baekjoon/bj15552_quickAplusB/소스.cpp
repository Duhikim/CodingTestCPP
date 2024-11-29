#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* pArr;
	pArr = new int[N];

	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		pArr[i] = A + B;
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", pArr[i]);
	}

	return 0;
}