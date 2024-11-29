/* #include <iostream>
#include <cmath>
using namespace std;

int convertabc(float abc[], char inpstr[]) {
	int strind = 0;
	for (int i = 0; i < 3; i++) {
		bool pos = true, jungpart = true, endofline = false;
		float tmpfl = 0;
		float tmpfl2 = 0.1;
		if (inpstr[strind] == '-') { pos = false; strind++; }
		if (inpstr[strind] == '+') strind++;
		
		
		while (!endofline) {

			while (jungpart) {
				if (inpstr[strind] == '.') { jungpart = false; strind++; break; }
				if (inpstr[strind] == ' ') { abc[i] = tmpfl; endofline = true; strind++; break; }
				if (int(inpstr[strind]) == 0) { abc[i] = tmpfl; endofline = true;  break; }
				tmpfl = tmpfl * 10.0 + (inpstr[strind++] - '0');

			}
			while (jungpart == false) {
				if (inpstr[strind] == ' ') { abc[i] = tmpfl; strind++; endofline = true; break; }
				if (int(inpstr[strind]) == 0) { abc[i] = tmpfl; endofline = true; break; }
				tmpfl += (inpstr[strind++] - '0') * tmpfl2; tmpfl2 /= 10;


			} 
			
		} 
		

	}
	return 0;
}

int read_coeff(float abc[]) {
	char inpstr[80], ch;
	char a, b, c;
	cin >> inpstr;
	a = inpstr[0]; b = inpstr[1]; 

	cout << abc[0] << "," << abc[1];
	return 0;

	/*
	ch = inpstr[0];
	switch (ch) {
	case 's' :
		return 1;
		break;
	case '+':
	case '-':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return(convertabc(abc, inpstr));
		break;
	default:
		return 1; //잘못 입력한 경우 프로그램 종료. 차후 에러코드 추가
	} 

	
}

void comprootout(float coeff[]) {
	cout << coeff[0] << "," << coeff[1] << "," << coeff[2] << '\n';
}

int proc() {
	float coeff[3];

	cout << "실수 a b c (띄어쓰기로 구분)를 입력 후 Enter. (s 입력시 프로그램 종료) \n";
	

	if (read_coeff(coeff) == 0) {
		comprootout(coeff);
		return 0;
	}
	return 1;

}

int main() {
	while (proc() == 0) {}
	
	
	return 0;

}

*/