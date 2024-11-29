#include <iostream>
using namespace std;


int main()
{
	char str[110][110];
	for (int i = 0; i < 110; i++) {
		cin.getline(str[i], 110);
		if (cin.eof()) break;
		cout << str[i] << '\n';
	}

	return 0;
}