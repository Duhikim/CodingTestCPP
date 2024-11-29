#include <iostream>
using namespace std;

int main() {
	int number;
	cin >> number;

	int* pArray;
	pArray = new int[number];

	for (int i = 0; i < number; i++) {
		cin >> pArray[i];
	}

	int findnum;
	int counting = 0;
	cin >> findnum;

	for (int i = 0; i < number; i++) {
		if (pArray[i] == findnum) counting++;

	}
	printf("%d\n", counting);

	return 0;
}