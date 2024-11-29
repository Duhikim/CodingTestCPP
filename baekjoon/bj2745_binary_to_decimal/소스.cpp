#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int main() {
	/*
	//BÁø¹ý¼ö N
	int B = 0;
	string Ntemp;
	int sum_decimal = 0;

	cin >> Ntemp >> B;
	int size = Ntemp.size();
	
	if (B < 10) {
		for (int i = 0; i < size; i++) {
			sum_decimal += (((int)Ntemp[i] - (int)'0') * pow(B, (size - i - 1)));
		}	cout << sum_decimal << '\n';
	}
	if (B == 10) { cout << Ntemp << '\n'; }

	if (B > 10) {
		for (int i = 0; i < size; i++) {
			if ((int)'0' <= (int)Ntemp[i] && (int)Ntemp[i] <= (int)'9') {
				sum_decimal += (((int)Ntemp[i] - (int)'0') * pow(B, (size - i - 1)));
			}
			else if ((int)'A' <= (int)Ntemp[i] && (int)Ntemp[i] <= (int)'Z') {
				sum_decimal += (((int)Ntemp[i] - (int)'A' + 10) * pow(B, (size - i - 1)));

			}
		}	cout << sum_decimal << '\n';
	}*/

	string N;
	int B = 0;
	cin >> N >> B;
	cout << stoi(N, nullptr, B);
	

	return 0;
}