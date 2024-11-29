#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1-i; j++) printf(" ");
		for (int k = 0; k < 2 * i + 1; k++) printf("*"); printf("\n");
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < i + 1; j++) printf(" ");
		for (int k = 0; k < 2 * N - 3 - 2 * i; k++) printf("*"); printf("\n");

	}

	return 0;
}