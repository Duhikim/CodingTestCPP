/*
#include <iostream>
using namespace std;

int main() {
	int N, X;
	cin >> N >> X;


	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (temp < X) printf("%d ", temp);
	}

	return 0;
} */

#include <iostream>
using namespace std;

int main() {
	int N, X;
	cin >> N >> X;

	int temp;
	for (int i = 0; i < N; i++) {

		cin >> temp;
		if (temp < X) printf("%d ", temp);
	}

	return 0;
}