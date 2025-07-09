#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	// 8진수가 주어졌을 때, 2진수로 변환하는 프로그램을 작성하시오.
	// 최대 길이 : 333,334. 엄청기니까 그냥 string으로 처리하는게 나을듯.
	
	string octal, binary;
	cin >> octal;
	if(octal == "0") {
		cout << "0\n";
		return 0;
	}
	for (char c : octal) {
		switch (c) {
		case '0': binary += "000"; break;
		case '1': binary += "001"; break;
		case '2': binary += "010"; break;
		case '3': binary += "011"; break;
		case '4': binary += "100"; break;
		case '5': binary += "101"; break;
		case '6': binary += "110"; break;
		case '7': binary += "111"; break;
		}
	}
	for (char c : binary) {
		if (c != '0') {
			cout << binary.substr(binary.find(c)) << '\n';
			return 0;
		}
	}
	
	
}

