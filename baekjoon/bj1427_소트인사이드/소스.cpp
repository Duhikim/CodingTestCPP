#include <iostream>
using namespace std;

/*
문제
배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.
입력
첫째 줄에 정렬하려고 하는 수 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.
출력
첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.
*/


int N;
int numbers[10];
int Size;

int make_number_array(int n) {
	int size = 0;
	for (int i = 0; n > 0; i++) {
		numbers[i] = n % 10; n /= 10; size++;
	}
	return size;
}

void sorting(int* array, int size) {
	int temp;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (array[i] < array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

int main() {
	cin >> N;
	Size = make_number_array(N);
	sorting(numbers, Size);
	for (int i = 0; i < Size; i++) {
		cout << numbers[i];
	}
	cout << '\n';
	return 0;
}