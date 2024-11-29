#include <iostream>
using namespace std;

bool debug = //true;
			false;

int N;
int* number, * pre, * post;

int merge(int first, int second) {
	if (post[first] == first && post[second] == second) {
		if (number[first] < number[second]) {
			post[first] = second;
			if (debug) printf("index %d. %d 뒤에 index %d. %d를 연결했음\n", first, number[first], second, number[second]);
			return first;
		}
		else { post[second] = first; 
		if (debug) printf("index %d. %d 뒤에 index %d. %d를 연결했음\n", second, number[second], first, number[first]);
		return second; }
	}
	else if (post[first] == first) {
		if (number[first] < number[second]) {
			post[first] = second;
			if (debug) printf("index %d. %d 뒤에 index %d. %d를 연결했음\n", first, number[first], second, number[second]);
			return first;
		}
		else {
			post[second] = merge(first, post[second]);
			if (debug) printf("index %d. %d 뒤에 index %d. %d를 연결했음\n", second, number[second], post[second], number[post[second]]);
			return second;
		}
	}
	else if (post[second] == second) {
		if (number[first] > number[second]) {
			post[second] = first;
			if (debug) printf("index %d. %d 뒤에 index %d. %d를 연결했음\n", second, number[second], post[second], number[post[second]]);
			return second;
		}
		else {
			post[first] = merge(post[first], second);
			if (debug) printf("index %d. %d 뒤에 index %d. %d를 연결했음\n", first, number[first], post[first], number[post[first]]);
			return first;
		}
	}
	else {
		if (number[first] < number[second]) {
			post[first] = merge(post[first], second); 
			if (debug) printf("index %d. %d 뒤에 index %d. %d를 연결했음\n", first, number[first], post[first], number[post[first]]);
			return first;
		}
		else {
			post[second] = merge(first, post[second]); 
			if (debug) printf("index %d. %d 뒤에 index %d. %d를 연결했음\n", second, number[second], post[second], number[post[second]]);
			return second;
		}
	}
}


int sorting(int start, int amount) {
	if (amount == 1) { return start; }
	if (amount == 2) {
		if (number[start] < number[start + 1]) {
			post[start] = (start + 1);
			if (debug) printf("index %d. %d 뒤에 index %d. %d를 연결했음\n", start, number[start], start + 1, number[start + 1]);
			return start;
		}
		else {
			post[start + 1] = start;
			if (debug) printf("index %d. %d 뒤에 index %d. %d를 연결했음\n", start + 1, number[start + 1], start, number[start]);
			return (start + 1);
		}
	}

	if (amount > 2) {
		int firstindex = sorting(start, amount / 2);
		int secondindex = sorting(start + amount / 2, amount - amount / 2);
		return merge(firstindex, secondindex);
	}

}

int main() {
	cin >> N;
	number = new int[N];
	pre = new int[N];
	post = new int[N];

	for (int i = 0; i < N; i++) { cin >> number[i]; }
	for (int i = 0; i < N; i++) { pre[i] = i; post[i] = i; } 

	int smallest = sorting(0, N);

	while (1) {
		cout << number[smallest] << '\n';
		if (smallest == post[smallest]) break;
		smallest = post[smallest];
		
	}
	delete[] number, pre, post;

	return 0;
}
