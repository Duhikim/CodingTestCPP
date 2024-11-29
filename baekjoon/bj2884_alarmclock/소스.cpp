#include <iostream>
using namespace std;

int main() {
	int hour, minute;
	cin >> hour >> minute;

	if ((minute - 45) < 0) {
		if ((hour - 1) < 0) {
			hour += 23;
			minute += 15;
		}
		else { hour--; minute += 15; }
	}
	else { minute -= 45; }

	printf("%d %d\n", hour, minute);

	return 0;
}