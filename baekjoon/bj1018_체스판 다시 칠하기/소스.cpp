#include <iostream>
using namespace std;

int main() {
	bool debug = //true;
				false;
	do {

		int N, M;
		char color[51][51] = { 0, };
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> color[i][j];
			}
		}

		if (debug) {
			cout << '\n' << "   "; for (int j = 0; j < M; j++) cout << j + 1 << " "; cout << '\n';
			for (int i = 0; i < N; i++) {
				if (i<9)cout <<"0"<< i + 1 << " ";
				else cout << i + 1 << " ";
				for (int j = 0; j < M; j++) {
					cout << color[i][j] << " ";
				} cout << '\n';
			} cout << '\n';
		}

		int minimum_count = -1;
		int minimum_count2 = -1;


		//N개의 행, M개의 열. 8 <= N,M <= 50
		//시작 지점을 1행 1열로 부터 N-7행 M-7열로 시작하는 곳 까지.
		//시작지점을 W로 한 번, B로 한 번. W시작: 행x열 값이 홀수인 경우 W. B시작: 행x열 값이 홀수인 경우 B.

		for (int i = 0; i < N - 7; i++) {
			for (int j = 0; j < M - 7; j++) { //시작지점 탐색
				int count_temp = 0;
				for (int k = 0; k < 8; k++) { //시작지점부터 8행
					for (int l = 0; l < 8; l++) { //시작지점부터 8열
						if ((((i + k + 1) % 2) && ((j + l + 1) % 2)) || (!((i + k + 1) % 2) && (!((j + l + 1) % 2)))) { if (color[i + k][j + l] == 'B') count_temp++; } //홀수행, 홀수열or 짝수행, 짝수열의 조건, 시작을 W부터, 홀수가 B면 temp++
						if (((i + k + 1) % 2 && !((j + l + 1) % 2)) || !((i + k + 1) % 2) && (j + l + 1) % 2) { if (color[i + k][j + l] == 'W') count_temp++; } //홀수행, 짝수열or 짝수행, 홀수열의 조건, 시작을 W부터, 짝수가 W면 temp++
					}

				} if (minimum_count<0 || count_temp < minimum_count) minimum_count = count_temp;
				if (debug) cout << i + 1 << ", " << j + 1 << "부터 시작하여 첫칸이 W가 되어야 할 때의 minimum_count 는 " << minimum_count << '\n';

				count_temp = 0;
				for (int k = 0; k < 8; k++) { //시작지점부터 8행
					for (int l = 0; l < 8; l++) { //시작지점부터 8열
						if ((((i + k + 1) % 2) && ((j + l + 1) % 2)) || (!((i + k + 1) % 2) && (!((j + l + 1) % 2)))) { if (color[i + k][j + l] == 'W') count_temp++; } //홀수행, 홀수열or 짝수행, 짝수열의 조건, 시작을 B부터, 홀수가 W면 temp++
						if (((i + k + 1) % 2 && !((j + l + 1) % 2)) || (!((i + k + 1) % 2) && (j + l + 1) % 2)) { if (color[i + k][j + l] == 'B') count_temp++; } //홀수행, 짝수열or 짝수행, 홀수열의 조건, 시작을 B부터, 짝수가 B면 temp++
					}

				} if (minimum_count<0 || count_temp < minimum_count) minimum_count = count_temp;
				if (debug && minimum_count2<0 || count_temp < minimum_count2) minimum_count2 = count_temp;
				if (debug) cout << i + 1 << ", " << j + 1 << "부터 시작하여 첫칸이 B가 되어야 할 때의 minimum_count2는 " << minimum_count2 << '\n';
			}
		}

		cout << minimum_count << '\n';

	} while (debug);

	return 0;

}