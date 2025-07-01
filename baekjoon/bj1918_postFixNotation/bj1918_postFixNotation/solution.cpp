#include <iostream>
#include <vector>
#include <string>

using namespace std;

string substituteLetters(const string& expression);
string enhancedFomula(const string& expression);
string defaultFomula(const string& firstOperand, const string& secondOperand, char operatorChar);
void makeUppserCase(string& str);
string getRidOfBrackets(const string& expression);

int main() {

	bool debug = 
		 //true;
		 false;

	string expression;

	while(debug) {
		cout << "Enter expression: ";
		cin >> expression;

		cout << getRidOfBrackets(substituteLetters(expression)) << '\n';
	}
	if (!debug) {
		cin >> expression;

		cout << getRidOfBrackets(substituteLetters(expression)) << '\n';
	}
	return 0;
}

string getRidOfBrackets(const string& expression) {
	string result = expression;

	while (result.find('(') != string::npos) {
		int startIdx, endIdx;
		for (int i = 0; i < result.size(); i++) {
			if (result[i] == '(') {
				startIdx = i;
			}
			else if (result[i] == ')') {
				endIdx = i;
				break;
			}
		}
		string subExpression = result.substr(startIdx + 1, endIdx - startIdx - 1);
		subExpression = enhancedFomula(subExpression);
		result = result.replace(startIdx, endIdx - startIdx + 1, subExpression);
	}
	result = enhancedFomula(result);

	return result;
}

string substituteLetters(const string& expression) {
	
	string result;

	for(char c: expression) {
		if (c >= 'A' && c <= 'Z') {
			result += c - 'A' + 'a'; // Convert uppercase to lowercase
		}
		else if (c == '+') result += '1';
		else if (c == '-') result += '2';
		else if (c == '*') result += '3';
		else if (c == '/') result += '4';		
		else if( c == '(' || c == ')') {
			result += c;
		}
		else cout << "Invalid character in expression: " << c << endl;
	}
	return result;
}

string enhancedFomula(const string& expression) {
	string result = expression;

	while(result.find('3') != string::npos || result.find('4') != string::npos) {
		string firstOperand, secondOperand;
		int startIdx = 0, endIdx = 0;
		for (int i = 0; i < result.size(); i++) {
			if (result[i] == '3' || result[i] == '4') {
				for (int p = i - 1; i >= 0; p--) {
					if (result[p] == '1' || result[p] == '2') {
						//p+1 부터 i-1 까지 문자열 추출
						firstOperand = result.substr(p + 1, i - p - 1);
						startIdx = p + 1;
						break;
					}
					if (p == 0) {
						firstOperand = result.substr(0, i);
						startIdx = 0;
						break;
					}
				}
				for(int p=i+1; p < result.size(); p++) {
					if (result[p] == '1' || result[p] == '2' || result[p] == '3' || result[p] == '4') {
						//i+1 부터 p-1 까지 문자열 추출
						secondOperand = result.substr(i + 1, p - i - 1);
						endIdx = p - 1;
						break;
					}
					if (p == result.size() - 1) {
						secondOperand = result.substr(i + 1, p - i);
						endIdx = p;
						break;
					}
				}
				result = result.replace(startIdx, endIdx - startIdx + 1, defaultFomula(firstOperand, secondOperand, result[i]));
				break;
			}			
		}
	}

	while (result.find('1') != string::npos || result.find('2') != string::npos) {
		string firstOperand, secondOperand;
		int startIdx = 0, endIdx = 0;
		for (int i = 0; i < result.size(); i++) {
			if (result[i] == '1' || result[i] == '2') {
				for (int p = i - 1; i >= 0; p--) {
					if (result[p] == '1' || result[p] == '2') {
						//p+1 부터 i-1 까지 문자열 추출
						firstOperand = result.substr(p + 1, i - p - 1);
						startIdx = p + 1;
						break;
					}
					if (p == 0) {
						firstOperand = result.substr(0, i);
						startIdx = 0;
						break;
					}
				}
				for (int p = i + 1; p < result.size(); p++) {
					if (result[p] == '1' || result[p] == '2') {
						//i+1 부터 p-1 까지 문자열 추출
						secondOperand = result.substr(i + 1, p - i - 1);
						endIdx = p - 1;
						break;
					}
					if (p == result.size() - 1) {
						secondOperand = result.substr(i + 1, p - i);
						endIdx = p;
						break;
					}
				}
				result = result.replace(startIdx, endIdx - startIdx + 1, defaultFomula(firstOperand, secondOperand, result[i]));
				break;
			}
		}
	}
	makeUppserCase(result);

	return result;
}

void makeUppserCase(string& str) {
		for (char& c : str) {
		if (c >= 'a' && c <= 'z') {
			c -= ('a' - 'A'); // Convert lowercase to uppercase
		}
		}
}

string defaultFomula(const string& firstOperand, const string& secondOperand, char operatorChar) {
	switch (operatorChar) {
		case '1':
			return firstOperand + secondOperand + "+";
		case '2':
			return firstOperand + secondOperand + "-";
		case '3':
			return firstOperand + secondOperand + "*";
		case '4':
			return firstOperand + secondOperand + "/";
		default:
			return firstOperand + secondOperand + operatorChar;
	}
}