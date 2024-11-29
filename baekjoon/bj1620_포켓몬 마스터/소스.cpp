#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
int N, M;


int main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> N >> M;
	vector<string> Num_to_Pokemon;
	map<string, int> Pokemon_to_Num;
	string input;
	
	for (int i = 0; i < N; i++) {
		cin >> input;
		Num_to_Pokemon.push_back(input);
		Pokemon_to_Num.insert(make_pair(input, i+1));
	}
		
	for (int i = 0; i < M; i++) {
		cin >> input;

		if (input[0]<='9') { // 입력이 숫자인 경우
			cout << Num_to_Pokemon[stoi(input) -1] << '\n';
		}
		else { // 입력이 숫자가 아닌 경우 (이름인 경우)
			auto Number = Pokemon_to_Num.find(input);
			cout << Number->second << '\n';
		}

	}
	
	return 0;
}