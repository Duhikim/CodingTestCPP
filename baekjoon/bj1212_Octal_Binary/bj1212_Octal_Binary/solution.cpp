#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	// 8������ �־����� ��, 2������ ��ȯ�ϴ� ���α׷��� �ۼ��Ͻÿ�.
	// �ִ� ���� : 333,334. ��û��ϱ� �׳� string���� ó���ϴ°� ������.
	
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

