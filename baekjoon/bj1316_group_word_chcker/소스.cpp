#include <iostream>
#include <cstring>
using namespace std;

int main() {


	int N = 0;
	int counting = 0;
	cin >> N;

	for (int h = 0; h < N; h++) {
		int tmp = 0;
		bool isit = 1;

		string word;
		cin >> word;
		int size = word.size();

		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				if (word[i] != word[j]) { tmp = j; break; }
				if ((j == size - 1) && word[i] == word[j]) { tmp = j; }
			}

			for (int k = tmp + 1; k < size; k++) {
				if (word[i] == word[k]) {
					isit = 0;
					break;
				}
			}
		}
		if (isit) counting++;
	}

	cout << counting << '\n';

	return 0;
}