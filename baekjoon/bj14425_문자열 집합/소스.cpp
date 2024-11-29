#include <iostream>
#include <string>
#include <set>
using namespace std;

int N, M;
set<string> S;
int counter;

int main() {
	cin >> N >> M;
	string word;

	for (int i = 0; i < N; i++) {
		cin >> word;
		S.insert(word);
	}
	for (int i = 0; i < M; i++) {
		cin >> word;
		if (S.find(word) != S.end()) counter++;
	}
	
	cout << counter << '\n';
	return 0;
}