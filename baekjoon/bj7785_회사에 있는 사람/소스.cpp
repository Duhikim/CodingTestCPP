#include <iostream>
#include <string>
#include <set>
using namespace std;

struct Compare {
	bool operator() (const string& a, const string& b) const{
		return a > b;
	}
};

int main() {
	int N;
	cin >> N;
	set<string, Compare> Register;
	for (int i = 0; i < N; i++) {
		string word, action;
		cin >> word >> action;
		
		if (action == "enter") Register.insert(word);
		else if (action == "leave") Register.erase(word);
	}

	for (string str : Register) {
		cout << str << '\n';
	}
	return 0;
}