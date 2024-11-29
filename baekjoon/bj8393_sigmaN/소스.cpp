#include<iostream>
using namespace std;

void sigma(int n, int sum) {
	for (int i = 0; i < n; i++) {
		sum += i + 1;
	}
	printf("%d\n", sum);
}

int main() {
	int n;
	int sum = 0;
	cin >> n;
	
	sigma(n, sum);
	return 0;
}