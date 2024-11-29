#include <iostream>
using namespace std;

int main() {
	int totalpay, prodnum;
	cin >> totalpay;
	cin >> prodnum;

	int sum = 0;

	for (int i = 0; i < prodnum; i++) {
		int eaprice, mount;
		cin >> eaprice >> mount;

		sum += (eaprice * mount);

	}

	if (sum == totalpay) printf("Yes");
	else printf("No");

	return 0;
}