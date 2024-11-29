#include <iostream>
using namespace std;

int main() {
	int Testcase;
	cin >> Testcase;

	while (Testcase--) {
		int C;
		cin >> C;	
	
		printf("%d %d %d %d\n", C / 25, C % 25 / 10, C % 25 % 10 / 5 , C % 25 % 10 % 5);


	}

	return 0;
}