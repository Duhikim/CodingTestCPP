//#include<iostream>
//#include<string>
//#include<vector>
//#include<deque>
//using namespace std;
//
//bool debug =
//true;
////false;
//
//bool conditionCheck(const deque<char>& subPassword, const vector<int>& condition);
//void getAnswer(int S, int P, const string& password, const vector<int>& condition, int& answer);
//
//int main() {	
//
//	int S, P;
//	string password;
//	vector<int> condition = vector<int>(4, 0);
//	int answer = 0;;
//
//	if (!debug) {
//		cin >> S >> P;
//		cin >> password;
//		cin >> condition[0] >> condition[1] >> condition[2] >> condition[3];
//	}
//	while (debug) {
//		cout << "Enter S and P: ";
//		cin >> S >> P;
//		cout << "Enter password: ";
//		cin >> password;
//		cout << "Enter conditions (A, C, G, T): ";
//		cin >> condition[0] >> condition[1] >> condition[2] >> condition[3];
//
//		getAnswer(S, P, password, condition, answer);
//	}
//
//	getAnswer(S, P, password, condition, answer);
//
//	return 0;
//}
//
//bool conditionCheck(const deque<char>& subPassword, const vector<int>& condition) {
//	
//	vector<int> count(4, 0);
//	for (char c : subPassword) {
//		if (c == 'A') count[0]++;
//		else if (c == 'C') count[1]++;
//		else if (c == 'G') count[2]++;
//		else if (c == 'T') count[3]++;
//	}
//	if( count[0] >= condition[0] && 
//		count[1] >= condition[1] && 
//		count[2] >= condition[2] && 
//		count[3] >= condition[3]) {		
//		return true;
//	}
//	return false;
//}
//
//void getAnswer(int S, int P, const string& password, const vector<int>& condition, int& answer) {
//	
//	deque<char> subPassword;
//	
//	for (int i = 0; i + P -1 < password.length(); i++) {
//		if (i == 0) {
//			for (int j = 0; j < P; j++) subPassword.push_back(password[j]);
//		}
//		else {
//			subPassword.pop_front();
//			subPassword.push_back(password[i+P-1]);
//		}		
//		if (conditionCheck(subPassword, condition)) {
//			answer++;
//
//			if (debug) {
//				cout << "Meet requirement : (" << answer << ") ";				
//				cout << '\n';
//			}
//		}
//	}
//	cout << answer << endl;
//	answer = 0;
//}