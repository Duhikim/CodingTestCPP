#include <iostream>
using namespace std;

//각 입력
/*
int main() {
	
	int A, B, C;
	cin >> A >> B >> C;

	
		if ((A + B + C) != 180) {
			cout << "Error" << '\n'; return 0;
		}
		else {
			if (A == B && A == C) {
				cout << "Equilateral" << '\n'; return 0;
			}
			else if ((A == B) || (A == C) || (B == C)) {
				cout << "Isosceles" << '\n'; return 0;
			}
			else {
				cout << "Scalene" << '\n'; return 0;
			}
		}
	
}
*/

//변 입력

//최대 변 구하기
bool is_it_invalid(int A, int B, int C) {
	int max = A;
	if (B > max) max = B;
	if (C > max) max = C;
	
	return (max >= (A + B + C - max)) ? 0 : 1;	
}

int main() {
	int A, B, C;
	
	while (true) {
		cin >> A >> B >> C;
		if (!A && !B && !C) break;

		bool invalid = is_it_invalid(A, B, C);
		if (!invalid) cout << "Invalid" << '\n';

		else if (A == B && B == C) {
			cout << "Equilateral" << '\n';
		}
		else if (A == B || B == C || C == A) cout << "Isosceles" << '\n';
		else cout << "Scalene" << '\n';

	}

	return 0;
}