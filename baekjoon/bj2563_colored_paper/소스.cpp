#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 0;

	bool coord[101][101] = { 0, };

	

	

	for (int k=0; k<N; k++){
		int x=0, y=0;
		cin >> x >> y;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (coord[x+i][y+j] != 1) { coord[x+i][y+j] = 1;  count++; }

			}
		}
	}
	
	cout << count << '\n';
	


	return 0;
}

///////
