#include <iostream>
#include <cstring>
using namespace std;

int main() {


	string word;
	cin >> word;

	int size = word.size();
	int counting = 0;

	for (int i = 0; i < size - 1; i++) {
		if (word[i] == 'c') {
			if (word[i + 1] == '=') counting++;
			else if (word[i + 1] == '-') counting++;

		}
		else if (word[i] == 'd' && word[i + 1] == 'z' && (i + 2) < size && word[i + 2] == '=') counting += 2;
		else if (word[i] == 'd' && word[i + 1] == '-') counting++;
		else if (word[i] == 'l' && word[i + 1] == 'j') counting++;
		else if (word[i] == 'n' && word[i + 1] == 'j') counting++;
		else if (word[i] == 's' && word[i + 1] == '=') counting++;
		else if (word[i] == 'z' && word[i + 1] == '=') {
			if (i == 0) counting++;
			else if ((i - 1) >= 0 && word[i - 1] != 'd') counting++;
		}

	}
	size -= counting;
	cout << size << '\n';

	return 0;


}