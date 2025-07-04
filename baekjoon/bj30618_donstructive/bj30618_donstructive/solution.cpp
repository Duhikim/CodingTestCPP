#include <iostream>
#include <vector>	
#include <string>	
#include <algorithm>
using namespace std;

// N개의 숫자로 이루어진 순열에서 i번째 숫자가, 그 순열의 연속부분수열에 등장하는 횟수는 i * (N - i + 1)이다.
// 프라임 계수가 음수인 2차함수라 가운데로 갈수록 값이 크다. 즉 자주 등장한다.
// 자주등장하는 곳인 가운데부터 큰숫자를 배치하면 가장 큰 점수를 얻을 수 있다.

int main() {
	int N;
	cin >> N;

	vector<int> permutation(N);

	for (int i = 0; i < N / 2; i++) {
		permutation[i] = 2*i + 1;
		permutation[N - i - 1] = 2*i + 2;
	}
	if(N % 2 == 1) {
		permutation[N / 2] = N;
	}

	for (int i = 0; i < N-1; i++) {
		cout << permutation[i] << " ";
	} cout << permutation[N - 1] << endl;

	return 0;
}

