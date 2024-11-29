#include <iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	int counter = 0;

	for (int i = 0; i * 3 <= N; i++) {
		for (int j = 0; (i * 3 + j * 5) <= N; j++) {
			if (i * 3 + j * 5 == N) {
				//if (debug) { cout << "i : " << i << '\n' << "j : " << j << '\n' << "i * 3 + j * 5 = " << i * 3 + j * 5 << '\n'; }
				cout << i + j << '\n'; return 0;
			}

		}
	} cout << -1 << '\n';

	return 0;
}

// 설탕봉지 3kg짜리와 5kg짜리가 있음.
// N 킬로그램을 배달할 때 최대한 적은 봉지로 배달.