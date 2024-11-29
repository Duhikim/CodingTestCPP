#include <iostream>
#include <cmath>
using namespace std;

float calcroot(float a, float b, float c); //근의 공식 계산 함수 선언


int main() {
	bool endmainloop = false; //end main loop가 true가 되면 프로그램 종료.
	bool azeroloop = true; //a가 0일경우 a값 다시 입력.
	float a, b, c;
	float ans1=0, ans2=0;

	while (endmainloop == false) {
		while (azeroloop) {
			cout << "2차 방정식 ax^2 + bx + c = 0에 대하여 \n";
			cout << "0이 아닌 실수 a의 값을 입력하시오. \n";
			cin >> a;
			if (a == 0) {
				cout << "0이 아닌 실수를 입력하시오.\n";
				
			}
			else {
				azeroloop = false;
				cout << "실수 b의 값을 입력하시오. \n";
				cin >> b;
				cout << "실수 c의 값을 입력하시오. \n";
				cin >> c;
			}

		}
			
		azeroloop = true;

		
		calcroot(a, b, c);		//근의 공식 함수

		bool endqstloop = false;

		while (endqstloop==false) { //프로그램 종료 의사 확인

			char endqst;
			cout << "다시 하시겠습니까? (y / n) \n";
			cin >> endqst;

			if ((endqst == 'n') || (endqst == 'N')) { endqstloop = true; endmainloop = true; }
			else if ((endqst == 'y') || (endqst == 'Y')) { endqstloop = true; }
			else {
				cout << "y 혹은 n의 값을 입력하십시오. \n";
			}

			}

	}


	return 0;
}

float calcroot(float a, float b, float c) { //근의 공식 함수 정의
	//ans1 = (-b+(b^2-4ac)^0.5)/2a
	//ans1 = (-b-(b^2-4ac)^0.5)/2a
	//b^2-4ac => 0 > 실수근, < 0 허수근
	//-b/2a +- disc/2a*i

	float ans1, ans2;

	float disc = pow(b, 2) - (4 * a * c);
	
	if (disc >=  0) {
		ans1 = (0 - b + pow(disc, 0.5)) / (2 * a);
		ans2 = (0 - b - pow(disc, 0.5)) / (2 * a);
		cout << "2차 방정식" << a << "x^2 + " << b << "x + " << c << " = 0 의 실근은 " << ans1 << " 와 " << ans2 << "입니다. \n\n";
	}
	else {
		float tmp = pow(0 - disc, 0.5) / (2 * a);
		ans1 = (0 - b) / (2 * a);

		cout << "2차 방정식" << a << "x^2 + " << b << "x + " << c << " = 0 의 허근은 " << ans1 << "+"<< tmp << "*i" <<" 와 " << ans1 << "-" << tmp << "*i" << "입니다. \n\n";

	}

	return 0;


}
