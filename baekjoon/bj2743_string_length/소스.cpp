#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[110];
	cin >> str;
	cout << strlen(str) << '\n';
	return 0;
}


//¼öµ¿
/*
int main() {
	char str[110];
	cin >> str;
	int counting = 0;
	

	while (str[counting] != '\0') { counting++; }

	cout << counting << '\n';

	return 0;
} */