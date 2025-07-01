#include<iostream>
#include<string>
#include<vector>
#include<deque>
using namespace std;

bool debug =
//true;
false;

void getAnswer(int S, int P, const string& password, const vector<int>& condition, int& answer);
bool conditionCheck(const vector<int>& count, const vector<int>& condition);

int main() {
	int S, P;
	string password;
	vector<int> condition = vector<int>(4, 0);
	int answer = 0;;

	if (!debug) {
		cin >> S >> P;
		cin >> password;
		cin >> condition[0] >> condition[1] >> condition[2] >> condition[3];
	}
	while (debug) {
		cout << "Enter S and P: ";
		cin >> S >> P;
		cout << "Enter password: ";
		cin >> password;
		cout << "Enter conditions (A, C, G, T): ";
		cin >> condition[0] >> condition[1] >> condition[2] >> condition[3];

		getAnswer(S, P, password, condition, answer);
	}

	getAnswer(S, P, password, condition, answer);

	return 0;
}

bool conditionCheck(const vector<int>& count, const vector<int>& condition) {
	if (count[0] >= condition[0] && 
		count[1] >= condition[1] && 
		count[2] >= condition[2] && 
		count[3] >= condition[3]) {
		return true;
	}
	return false;
}


void getAnswer(int S, int P, const string& password, const vector<int>& condition, int& answer) {

	vector<int> count(4, 0);
	for (int i = 0; i < P; i++) {
		if( password[i] == 'A') count[0]++;
		else if (password[i] == 'C') count[1]++;
		else if (password[i] == 'G') count[2]++;
		else if (password[i] == 'T') count[3]++;
	}	

	for(int i=0; i<S-P+1; i++) {
		if(conditionCheck(count, condition)) {
			answer++;
		}
		if (i == S-P) break;
		if(password[i]== 'A') count[0]--;
		else if (password[i] == 'C') count[1]--;
		else if (password[i] == 'G') count[2]--;
		else if (password[i] == 'T') count[3]--;
		if(password[i+P] == 'A') count[0]++;
		else if (password[i+P] == 'C') count[1]++;
		else if (password[i+P] == 'G') count[2]++;
		else if (password[i + P] == 'T') count[3]++;
	}

	cout << answer << endl;
	answer = 0;
}