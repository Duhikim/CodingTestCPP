/*
문제
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 
정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 
숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다. 두 숫자 카드에 같은 수가 적혀있는 경우는 없다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수가 주어지며, 
이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다

출력
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 가지고 있으면 1을, 아니면 0을 공백으로 구분해 출력한다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool debug = //true;
			false;
int N, M;
int* mycard;

bool find_card(int num, int start, int size) {
	if (size == 1) {
		if (num == mycard[start]) return 1; return 0;
	}
	if (size == 2) {
		if (num == mycard[start] || num == mycard[start+1]) return 1; return 0;
	}
	// ((if size > 2))
	if (num == mycard[start + size / 2]) return 1;
	if (num < mycard[start + size / 2]) {
		return find_card(num, start, size / 2);
	}
	if (num > mycard[start + size / 2]) {
		return find_card(num, start + size / 2, size - size / 2);
	}
	return 0;
}

int main() {
	cin >> N;
	mycard = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> mycard[i];
	}

	sort(mycard, mycard+N);
	if (debug) { for (int i = 0; i < N; i++) { cout << mycard[i] << " "; } cout << '\n'; }
	

	cin >> M;
	
	for (int i = 0; i < M; i++) {
		int givennum;
		cin >> givennum;
		bool is_it = find_card(givennum, 0, N);
		cout << is_it << " ";
	}
	cout << '\n';

	delete[] mycard;
	
	return 0;
}

