#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int* pNum;
	pNum = new int[N];
	

	for (int i = 0; i < N; i++) {
		cin >> pNum[i];
	}

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		int sum = 0;

		for (int j = (start - 1); j < end; j++) {
			sum += pNum[j];
		}
		cout << sum << '\n';
	}
	return 0;
}