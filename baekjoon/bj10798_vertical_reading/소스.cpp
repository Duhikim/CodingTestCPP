#include <iostream>
#include <istream>
#include <string>
using namespace std;

int main() {
	char alphabet[5][20] = { 0 };
	//int size[5];
	
	for (int i = 0; i < 5; i++) {cin >> alphabet[i];} // 입력

	
	//사이즈 측정
	/*
	for (int i = 0; i < 5; i++) {
		int temp = 0;
		for (int j = 0; alphabet[i][j] != '\0'; j++) {
			temp++;
		} size[i] = temp;
	}*/
	
	//사이즈 기준으로 출력
	/*
	for (int j = 0; j < 20; j++) {
		for (int i = 0; i < 5; i++) {
			if(j< size[i]) cout << alphabet[i][j];
		}
	} */

	//그냥 출력
	for (int j = 0; j < 20; j++) {
		for (int i = 0; i < 5; i++) {
			if (alphabet[i][j]) cout << alphabet[i][j];
		}
	}
	
	

	return 0;
}