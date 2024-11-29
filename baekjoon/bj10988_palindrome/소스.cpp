/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	char word[110];
	cin >> word;

	int counting = 0;
	for (int i = 0; i < 110; i++) {
		if (word[i] == '\0') break;
		counting++;
	}
	
	bool YESorNO = 1;
	for (int i = 0; i < counting - (counting / 2); i++) {
		if (word[i] != word[counting - 1 - i]) { YESorNO = 0;  break; }

	}
	cout << YESorNO << '\n';

	return 0;
}*/


// 밑은 다른 사람의 코드
#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int a = s.size() / 2;
	int b = s.size() - 1;
	int p = 1;

	for (int i = 0; i < a; ++i)	{
		if (s[i] != s[b]) {
			p = 0;
			break;
		}

		else {	p = 1;	}

		--b;
	}

	cout << p << endl;

}