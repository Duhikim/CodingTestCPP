#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

bool debug = 
 true;
 //false;

int main() {
	if(debug) cout << "debug mode" << endl;
	
	while (true) {
		int shingles;
		cin >> shingles;

		if (shingles <= 4) {
			cout << 4 << endl;
			if (debug) continue;
			else return 0;
		}
		// 만약 shingles가 제곱수면 제곱 근을 한 변으로 가지면 됨.
		// 제곱수가 아니라면, 제곱근에서 하나는 내림을, 하나는 올림을 하여 곱해서 shingles와 비교.
		// 만약 곱한 값이 크거나 같다면, 그 값들을 가로, 세로 값으로 가지면 됨
		// 만약 곱한 값이 작다면 내림한 값에 +1을 하여 가로, 세로 값으로 가지면 됨.

		int width, height;
		width = height = sqrt(shingles);

		if (width * height == shingles) {
			cout << (width + height - 2) * 2 << endl;
			if (debug) continue;
			return 0;
		}
		if ((width + 1) * height >= shingles) {
			cout << (width + height - 2) * 2 + 2 << endl;
			if (debug) continue;
			return 0;
		}
		cout << (width + height - 2) * 2 + 4 << endl;
		if (debug) continue;
		return 0;
	}
}
