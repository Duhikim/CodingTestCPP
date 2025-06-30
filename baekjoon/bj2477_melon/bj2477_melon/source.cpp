#include <iostream>
#include <vector>

using namespace std;

int getSquareMeters(int coordinates[6][2]);

int main() {

	int perSquareMeter;
	cin >> perSquareMeter;

	int coordinates[6][2];
	coordinates[0][0] = 0;
	coordinates[0][1] = 0;

	int minX = 0, minY = 0;

	for (int i = 1; i < 6; i++) {
		int direction, distance;
		cin >> direction >> distance;

		switch (direction) {
		case 1: // East
			coordinates[i][0] = coordinates[i - 1][0] + distance;
			coordinates[i][1] = coordinates[i - 1][1];
			break;
		case 2: // West
			coordinates[i][0] = coordinates[i - 1][0] - distance;
			coordinates[i][1] = coordinates[i - 1][1];
			if (coordinates[i][0] < minX) {
				minX = coordinates[i][0];
			}
			break;
		case 3: // South
			coordinates[i][0] = coordinates[i - 1][0];
			coordinates[i][1] = coordinates[i - 1][1] - distance;
			if (coordinates[i][1] < minY) {
				minY = coordinates[i][1];
			}
			break;
		case 4: // North
			coordinates[i][0] = coordinates[i - 1][0];
			coordinates[i][1] = coordinates[i - 1][1] + distance;
			break;
		}
	}
	for (int i = 0; i < 6; i++) {
		coordinates[i][0] -= minX;
		coordinates[i][1] -= minY;
	}

	int squareMeters = getSquareMeters(coordinates);


	cout << squareMeters * perSquareMeter << '\n';
	return 0;
}

int getSquareMeters(int coordinates[6][2]) {
	int maxX = 0, maxY = 0;

	for (int i = 0; i < 6; i++) {
		if (coordinates[i][0] > maxX) {
			maxX = coordinates[i][0];
		}
		if (coordinates[i][1] > maxY) {
			maxY = coordinates[i][1];
		}
	}
	int mid[2];
	for (int i = 0; i < 6; i++) {
		if (coordinates[i][0] > 0 && coordinates[i][0] < maxX
			&& coordinates[i][1] > 0 && coordinates[i][1] < maxY) {
			mid[0] = coordinates[i][0];
			mid[1] = coordinates[i][1];
			break;
		}
	}
	int voidWidth = 0, voidHeight = 0;
	for (int i = 0; i < 6; i++) {
		if (coordinates[i][0] == mid[0] && coordinates[i][1] != mid[1]) {
			voidWidth = abs(coordinates[i][1] - mid[1]);
		}
		if (coordinates[i][1] == mid[1] && coordinates[i][0] != mid[0]) {
			voidHeight = abs(coordinates[i][0] - mid[0]);
		}
	}

	return (maxX * maxY) - (voidWidth * voidHeight);
}