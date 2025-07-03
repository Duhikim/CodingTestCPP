#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int width, height;
	cin >> width >> height;

	int cutting;
	cin >> cutting;

	vector<int> vertCuts = { 0, width };
	vector<int> horCuts = { 0, height };

	for(int c = 0; c < cutting; c++) {
		int direction, position;
		cin >> direction >> position;

		if(direction == 0) { // vertical cut
			horCuts.push_back(position);
		} else if(direction == 1) { // horizontal cut
			vertCuts.push_back(position);
		}
	}

	sort(vertCuts.begin(), vertCuts.end());
	sort(horCuts.begin(), horCuts.end());

	// 수직, 수평에서 가장 큰 차이를 찾아서 곱하면 될듯.

	int maxVertDiff = 0;
	int maxHorDiff = 0;

	for(int i=1; i<vertCuts.size(); i++) {
		if (vertCuts[i] - vertCuts[i - 1] > maxVertDiff) {
			maxVertDiff = vertCuts[i] - vertCuts[i - 1];
		}
	}
	for(int i=1; i<horCuts.size(); i++) {
		if (horCuts[i] - horCuts[i - 1] > maxHorDiff) {
			maxHorDiff = horCuts[i] - horCuts[i - 1];
		}
	}

	cout << maxVertDiff * maxHorDiff << endl;

	return 0;
}