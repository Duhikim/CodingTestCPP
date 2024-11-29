#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int counting[10000];
int N;

int main() {
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		counting[temp - 1]++;
	}

	for (int i = 0; i < 10000; i++) {
		if (counting[i]) 
			for (int j = 0; j < counting[i]; j++) {
				printf("%d\n", i + 1);
			}
	}

	return 0;
}




/*
bool debug = //true;
			false;

int find_max(int array[], int size) {
	int max = array[0];
	for (int i = 1; i < size; i++) {
		max = (array[i] > max) ? array[i] : max;
	}
	return max;
}

int main() {
	int N;
	cin >> N;
	int* numbers;
	numbers = new int[N];
	for (int i = 0; i < N; i++) { cin >> numbers[i]; }

	int maximum = find_max(numbers, N);

	int* counting;
	counting = new int[maximum + 1];
	int* counting_sum;
	counting_sum = new int[maximum + 1];

	for (int i = 0; i < maximum + 1; i++) { counting[i] = 0; counting_sum[i] = 0; } //초기화

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < maximum + 1; j++) {
			if (numbers[i] == j) counting[j]++;
		}
	}
	
	if (debug) { for (int i = 0; i < maximum + 1; i++) cout << counting[i] << " "; cout << '\n'; }
	

	for (int i = 1; i < maximum + 1; i++) {
		counting_sum[i] = counting_sum[i - 1] + counting[i];
	}
	if (debug) { for (int i = 0; i < maximum + 1; i++) cout << counting_sum[i] << " "; cout << '\n'; }

	int* sorted;
	sorted = new int[N+1];
	for (int i = 0; i < N; i++) { sorted[i] = 0; } //초기화


	for (int i = 1; i <= maximum; i++) {
		for (int j = counting_sum[i] - counting[i] + 1; j <= counting_sum[i]; j++) {
			sorted[j] = i;
		}
	}

	for (int i = 1; i < N+1; i++) {
		cout << sorted[i] << '\n';
	}

	delete[] numbers, counting, sorted;
	return 0;
}
*/