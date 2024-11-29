#include <iostream>
using namespace std;

int main() {
	int ary[28];
	for (int i = 0; i < 28; i++) {	cin >> ary[i];	}
	
	int ans[2] = { 0, 0 };
	
	
	for (int i = 1; i < 31; i++) {
		if (ans[0] == 0) {
			for (int j = 0; j < 28; j++) {
				if (i == ary[j]) break;
				else if (j == 27 && i != ary[27]) { ans[0] = i;  break; }
			}
		}
		else {
			for (int j = 0; j < 28; j++) {
				if (i == ary[j]) break;
				else if (j == 27 && i != ary[27]) { ans[1] = i; break; }
			}
		}
	}
	

	printf("%d\n%d", ans[0], ans[1]);


	return 0;
}