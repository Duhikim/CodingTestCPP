#include <iostream>
using namespace std;

int main() {
	int number;
	cin >> number;

	for (int i = 0; i < number; i++) {
		for (int k = 1; k < (number - i); k++) { printf(" "); }
		for (int j = 0; j < (i+1); j++) { printf("*");}
		
		printf("\n");
		
	}

	return 0;
}