#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> numbers(N);
	for(int i= 0; i < N; i++) {
		cin >> numbers[i];
	}

	
	cout << "YES" << endl;
	cout << numbers[0] * 111 << endl;
	return 0;


}