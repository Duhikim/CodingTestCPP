#include <iostream>
using namespace std;

// N개의 숫자가 주어졌을 때, 이를 오름차 순으로 정렬.
// 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.
// 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

int main() {
	int N;
	cin >> N;
	int* pArray;
	pArray = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> pArray[i];
	}

	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (pArray[j] < pArray[i]) {
				temp = pArray[i];
				pArray[i] = pArray[j];
				pArray[j] = temp;
			}
		}		
	}
	for (int i = 0; i < N; i++) {
		cout << pArray[i] << '\n';
	}
	return 0;
}