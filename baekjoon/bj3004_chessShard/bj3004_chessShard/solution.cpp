#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	// 가로로 자른게 많으면 세로로 자를때 이득, 세로로 자른게 많으면 가로로 자를때 이득
	// 따라서 그냥 가로한번 세로한번씩 번갈아가면서 자르면 됨.
	// 가로로 자르면 세로선+1개의 조각이 더생김
	// 세로로 자르면 가로선+1개의 조각이 더생김

	int hor = 0, ver = 0;
	int pieces = 1;
	for (int i = 1; i <= N; i++) { // i가 홀수면 가로, 짝수면 세로로 자르자.
		if (i % 2 == 1) {
			hor++;
			pieces += ver + 1;
		}
		else {
			ver++;
			pieces += hor + 1;
		}
	} cout << pieces << endl;
	return 0;
}