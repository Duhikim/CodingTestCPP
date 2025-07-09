#include<iostream>
using namespace std;

int main() {
	long long R, K, M;
	cin >> R >> K >> M;

	long long halfLifeTime = 1;
	long long benefit = R;
	while (K * halfLifeTime <= M) {
		benefit /= 2;
		if (benefit == 0) break;
		halfLifeTime++;
	}
	cout << benefit << endl;
	
	return 0;
}