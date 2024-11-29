#include <iostream>
#include <cmath>
using namespace std;

//海长 内靛

int main() {
	int N, B;


	string str = "";
	cin >> N >> B;

	while (N != 0) {
		str = char(N % B < 10 ? (N % B + '0') : (N % B - 10 + 'A')) + str; N /= B;
	}
	cout << str << '\n';

}




//贸澜 内靛
/*
int main() {
	int N, B;
	int Bnum[31];
	char Bnum2[31];



	for (int i = 0; i < 31; i++) { Bnum[i] = -1; Bnum2[i] = -1; }

	cin >> N >> B;

	if (N == B) { cout << 10 << '\n'; }
	else if (N < 10 && N < B) { cout << N << '\n'; }
	else if (N >= 10 && N < B) { cout << (char)(N - 10 + 'A') << '\n'; }
	else if (N > B && B < 10) {

		for (int i = 0; N != 0; i++) {
			Bnum[i] = N % B;
			N = (N - Bnum[i]) / B;

		}
		int size = 0;
		for (int i = 0; Bnum[i] >= 0; i++) { size++; }
		for (int i = 0; i < size; i++) {
			cout << Bnum[size - i - 1];
		}
		cout << '\n';
	}
	else if (N > B && B >= 10) {
		for (int i = 0; N != 0; i++) {
			if (N % B < 10) {
				Bnum2[i] = (char)(N % B + '0'); N = (N - (N % B)) / B;
			}
			else {
				Bnum2[i] = (char)(N % B - 10 + 'A'); N = (N - (N % B)) / B;
			}
		}
		int size = 0;
		for (int i = 0; Bnum2[i] != -1; i++) { size++; }
		for (int i = 0; i < size; i++) {
			cout << Bnum2[size - i - 1];
		}
		cout << '\n';
	}



	return 0;
}
*/


