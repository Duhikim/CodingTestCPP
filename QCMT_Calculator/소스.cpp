#include <iostream>
using namespace std;

int Qunit, flowunit, tempunit;
string Qunitchar, flowunitchar, tempunitchar;
bool quitprogram = 0;
double Qcal_v = 0, flow_v = 0, deltaT_v = 0;
bool Qloop = 0, floop = 0, tloop = 0; //void unit_setting() 에서 사용

//Q 단위 선택 함수
void Q_unit_set(int x) {
	switch (x) {
	case 1 :
		Qunitchar = "kW";
		cout << "선택된 단위 : " << Qunitchar << '\n';
		break;
	case 2:
		Qunitchar = "BTU/h";
		cout << "선택된 단위 : " << Qunitchar << '\n';
		break;
	case 3:
		Qunitchar = "kcal/h";
		cout << "선택된 단위 : " << Qunitchar << '\n';
		break;
	case 0:
		cout << "프로그램을 종료합니다. \n";
		quitprogram = 1;
		break;
	default :
		cout << "1, 2, 3 또는 0을 입력하십시오. \n";
		Qloop = 1;
		break;
	}	
}

//유량 단위 선택 함수
void flow_unit_set(int x) {
	switch (x) {
	case 1:
		flowunitchar = "LPM";
		cout << "선택된 단위 : " << flowunitchar << '\n';
		break;
	case 2:
		flowunitchar = "LPS";
		cout << "선택된 단위 : " << flowunitchar << '\n';
		break;
	case 3:
		flowunitchar = "CFM";
		cout << "선택된 단위 : " << flowunitchar << '\n';
		break;
	case 4:
		flowunitchar = "CMH";
		cout << "선택된 단위 : " << flowunitchar << '\n';
		break;
	case 5:
		flowunitchar = "GPM";
		cout << "선택된 단위 : " << flowunitchar << '\n';
		break;
	case 0:
		cout << "프로그램을 종료합니다. \n";
		quitprogram = 1;
		break;
	default:
		cout << "1, 2, 3, 4, 5 또는 0을 입력하십시오. \n";
		floop = 1;
		break;
	}
}

//온도 단위 선택 함수
void temp_unit_set(int x) {
	switch (x) {
	case 1:
		tempunitchar = "°C";
		cout << "선택된 단위 : " << tempunitchar << '\n';
		break;
	case 2:
		tempunitchar = "°F";
		cout << "선택된 단위 : " << tempunitchar << '\n';
		break;
	case 3:
		tempunitchar = "K";
		cout << "선택된 단위 : " << tempunitchar << '\n';
		break;
	case 0:
		cout << "프로그램을 종료합니다. \n";
		quitprogram = 1;
		break;
	default:
		cout << "1, 2, 3 또는 0을 입력하십시오. \n";
		tloop = 1;
		break;
	}
}

//단위 선택 함수
void unit_setting() {
	
	cout << "\n<변수별 단위 입력>\n";

	do {
		Qloop = 0;
		cout << "\n<Q (시간당 열량) 단위> \n";
		cout << "1. kW		2. BTU/h		3. kcal/h		0. 프로그램 종료\n";
		cin >> Qunit;
		if (Qunit == 0) quitprogram = 1;
		if (!quitprogram) { Q_unit_set(Qunit); }
	} while (Qloop);

	do {
		floop = 0;
		if (!quitprogram) {
			cout << "\n<유량 단위> \n";
			cout << "1. LPM		2. LPS		3. CFM		4. CMH		5. GPM		0. 프로그램 종료 \n";
			cin >> flowunit;
			if (Qunit == 0) quitprogram = 1;
		}
		if (!quitprogram) flow_unit_set(flowunit);
	} while (floop);

	do {
		tloop = 0;
		if (quitprogram != 1) {
			cout << "\n<온도 단위> \n";
			cout << "1. °C		2. °F		3. K		0. 프로그램 종료  \n\n";
			cin >> tempunit;
			if (Qunit == 0) quitprogram = 1;
		}
		if (quitprogram != 1) temp_unit_set(tempunit);
	} while (tloop);
		
}

//구하고자 하는 변수 선택 함수
int which_value;
void which_you_want() {
	cout << "\n구하고자 하는 변수를 입력하시오.\n";
	cout << "1. Q (시간당 열량)		2. M (질량유량)		3. deltaT (온도차)		9. 단위 재설정		0. 프로그램 종료\n";
	cin >> which_value;
	switch (which_value) {
	case 1:
		cout << "Q (시간당 열량)을 선택하셨습니다. \n\n";
		break;
	case 2:
		cout << "M (질량 유량)을 선택하셨습니다. \n\n";
		break;
	case 3:
		cout << "deltaT (온도차)를 선택하셨습니다. \n\n";
		break;
	case 9:
		cout << "단위를 다시 설정합니다. \n\n";
		unit_setting();
		break;
	case 0:
		cout << "프로그램을 종료합니다. \n";
		quitprogram = 1;
		break;
	default:
		cout << "1, 2, 3, 9 또는 0을 입력하십시오. \n";
		which_you_want();
		break;
	}
	
}

//물질 선택 함수
int material;
double specific_h;
double density;
void choose_material() {
	cout << "\n열교환 하는 물질은 어떤 물질입니까? 혹은 직접 비열을 입력하십시오. \n";
	cout << "1. 물		2. 공기		3. 비열/밀도 직접 입력		9. 단위 재설정		0. 프로그램 종료 \n";
	cin >> material;
	switch (material) {
	case 1:
		specific_h = 4.1868; //물의 비열 입력 4.1868 [kJ / K*kg]
		density = 1; //물의 밀도 입력. 1kg/liter
		break;
	case 2:
		specific_h = 1.004832; //공기의 비열 입력 1.004832 [kJ / K*kg]
		density = 1.29/1000; //공기의 밀도 입력. 1.29 g/liter
		break;
	case 3:
		cout << "비열을 입력해 주십시오. 단위 [kcal/kg·°C] \n";
		cin >> specific_h;
		cout << "밀도를 입력해 주십시오. 단위 [kg/m^3] \n";
		cin >> density;
		break;
	case 9:
		cout << "단위를 다시 설정합니다. \n\n";
		unit_setting();
		break;
	case 0:
		cout << "프로그램을 종료합니다. \n";
		quitprogram = 1;
		break;
	default:
		cout << "1, 2, 3, 9 또는 0을 입력하십시오. \n";
		choose_material();
		break;
	}
}

//열량 입력
double Qcal() {
	cout << "\n시간당 열량을 입력하십시오. " << Qunitchar << '\n';
	double temp;
	cin >> temp;
	return temp;
}

//유량 입력
double flow() {
	cout << "\n물질의 유량을 입력하십시오. " << flowunitchar << '\n';
	double temp;
	cin >> temp;
	return temp;
}
//온도차 입력
double deltaT() {
	cout << "\n입출구 온도차를 입력하십시오. " << tempunitchar << '\n';
	double temp;
	cin >> temp;
	return temp;
}

//Q 단위 환산
double coordQ(double x) {
	switch (Qunit) {
	case 1: // kW = kJ/s
		return x;
	case 2: //BTU/h
		return (x * 2.928751 / 10000);
	case 3: //kcal/h
		return (x * 1.162222 / 1000);		
	}
}

//유량 단위 환산
double coordflow(double x) {
	switch (flowunit) {
	case 1: //LPM
		return (x / 60);
	case 2: //LPS
		return x;		
	case 3: //CFM
		return (x * 0.4719474);
	case 4: //CMH
		return (x * 0.2777778);
	case 5: //GPM
		return (x * 6.30902 / 100);
	}
}

//온도차 단위 환산
double coordtemp(double x) {
	switch (tempunit) {
	case 1: // 섭씨
		return x;
	case 2: // 화씨
		return (x / 1.8);
	case 3: //켈빈
		return x;
	}
}

// Q 계산
double calcQ(double f, double t) {
	return specific_h * density * f * t;
}
// 유량 계산
double calcflow(double q, double t) {
	return q / (specific_h * density * t);
}
// 온도차 계산
double calctemp(double q, double f) {
	return q / (specific_h * density * f);
}

// Q 출력
void outputQ(double q) {
	switch (Qunit) {
	case 1: // kW = kJ/s
		cout << "\n------------------------------------------------------\n";
		cout << "시간당 열량은" << q << " " << Qunitchar << "입니다.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 2: //BTU/h
		cout << "\n------------------------------------------------------\n";
		cout << "시간당 열량은" << (q / 2.928751 * 10000) << " " << Qunitchar << "입니다.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 3: //kcal/h
		cout << "\n------------------------------------------------------\n";
		cout << "시간당 열량은" << (q / 1.162222 * 1000) << " " << Qunitchar << "입니다.\n";
		cout << "------------------------------------------------------\n";
		break;
	}
}

// 유량 출력
void outputflow(double f) {
	switch (flowunit) {
	case 1: //LPM
		cout << "\n------------------------------------------------------\n";
		cout << "유량은" << f*60 << " " << flowunitchar << "입니다.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 2: //LPS
		cout << "\n------------------------------------------------------\n";
		cout << "유량은" << f << " " << flowunitchar << "입니다.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 3: //CFM
		cout << "\n------------------------------------------------------\n";
		cout << "유량은" << (f / 0.4719474) << " " << flowunitchar << "입니다.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 4: //CMH
		cout << "\n------------------------------------------------------\n";
		cout << "유량은" << (f / 0.2777778) << " " << flowunitchar << "입니다.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 5: //GPM
		cout << "\n------------------------------------------------------\n";
		cout << "유량은" << (f / 6.30902 * 100) << " " << flowunitchar << "입니다.\n";
		cout << "------------------------------------------------------\n";
		break;
	}
}
 
// 온도차 출력
void outputtemp(double t) {
	switch (tempunit) {
	case 1: // 섭씨
		cout << "\n------------------------------------------------------\n";
		cout << "입출구 온도차는" << t << " " << tempunitchar << "입니다.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 2: // 화씨
		cout << "\n------------------------------------------------------\n";
		cout << "입출구 온도차는" << t*1.8 << " " << tempunitchar << "입니다.\n";
		cout << "------------------------------------------------------\n";
		break;
	case 3: //켈빈
		cout << "\n------------------------------------------------------\n";
		cout << "입출구 온도차는" << t << " " << tempunitchar << "입니다.\n";
		cout << "------------------------------------------------------\n";
		break;
	}
}

//모든 단위는 기본단위로 환산하여 계산한다. Q [kW/h], c[kJ/K kg], m [kg/s], T [K], flow[LPS]
int main() {
	bool programend = 0;
	bool partloop = 0;

	printf("Q = C x M x deltaT 계산기 (ver 1.01)\n\n"); //ver1.01 March 20, 2024


	while (!programend) {
		if (!partloop) unit_setting(); // 단위 설정

		if (quitprogram) return 0;
		which_you_want(); // 구하고자 하는 변수 설정

		if (quitprogram) return 0;
		choose_material(); // 물질 입력

		if (quitprogram) return 0;
		if (which_value != 1)	Qcal_v = Qcal();
		if (which_value != 2)	flow_v = flow();
		if (which_value != 3)	deltaT_v = deltaT();


		if (quitprogram) return 0;

		//계산을 위한 단위 환산
		if (which_value != 1)	Qcal_v = coordQ(Qcal_v);
		if (which_value != 2)	flow_v = coordflow(flow_v);
		if (which_value != 3)	deltaT_v = coordtemp(deltaT_v);
		//계산
		if (which_value == 1)	Qcal_v = calcQ(flow_v, deltaT_v);
		if (which_value == 2)	flow_v = calcflow(Qcal_v, deltaT_v);
		if (which_value == 3)	deltaT_v = calctemp(Qcal_v, flow_v);

		//결과 단위 환산 후 출력
		if (which_value == 1)	outputQ(Qcal_v);
		if (which_value == 2)	outputflow(flow_v);
		if (which_value == 3)	outputtemp(deltaT_v);


		if (quitprogram) return 0;
		bool questionloop = 0;
		do {
			questionloop = 0;
			cout << "\n\n다시 하시겠습니까?\n";
			cout << "1. 같은 단위로 다시 계산		2. 단위 재설정		0. 프로그램 종료\n";
			int endoption;
			cin >> endoption;
			switch (endoption) {
			case 1:
				partloop = 1;
				break;
			case 2:
				partloop = 0;
				break;
			case 0:
				return 0;
			default:
				cout << "1, 2 혹은 0을 입력하십시오.\n";
				questionloop = 1;
				break;
			}
		} while (questionloop);


	}

}