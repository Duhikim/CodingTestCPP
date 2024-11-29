#include <iostream>
using namespace std;

//ax + by = c
//dx + ey = f
//x와 y를 구하시오.

int main() {
	int a, b, c, d, e, f, x, y;
	cin >> a >> b >> c >> d >> e >> f;

	for (x = -999; x < 1000; x++) {
		for (y = -999; y < 1000; y++) {
			if (a * x + b * y == c && d * x + e * y == f) {
				cout << x << " " << y << '\n'; return 0;
			}
		}
	}
	return 0;
}