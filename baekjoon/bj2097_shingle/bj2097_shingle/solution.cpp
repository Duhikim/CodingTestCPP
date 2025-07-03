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
		// ���� shingles�� �������� ���� ���� �� ������ ������ ��.
		// �������� �ƴ϶��, �����ٿ��� �ϳ��� ������, �ϳ��� �ø��� �Ͽ� ���ؼ� shingles�� ��.
		// ���� ���� ���� ũ�ų� ���ٸ�, �� ������ ����, ���� ������ ������ ��
		// ���� ���� ���� �۴ٸ� ������ ���� +1�� �Ͽ� ����, ���� ������ ������ ��.

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
