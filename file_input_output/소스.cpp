#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//파일 키보드 입력 -> 파일 열기 -> 16진수 코드로 출력 -> 아스키 코드 출력

char ifname[80];
string contents[1000];

void fileinput() {
	cout << "파일명을 입력하시오. \n";
	cin >> ifname;
}




int main() {
	
	
	fileinput();
	ifstream ifs;
	ifs.open(ifname);
	if (!ifs) {
		cerr << "Input Error!" << endl;
	}
	else {
		cout << "파일이 성공적으로 열렸습니다. \n";
		
		ofstream ofs("temporary.txt", ios::out);
		if (ofs.fail()) {
			cerr << "Output Error!" << endl;
		}
		else {
			string line;
			int count = 0;
			while (getline(ifs, line)) {
					contents[count++] = line;
					if (count >= 1000) break;
									
			}
			int opcount = 0;
			while (opcount < count) {
				ofs << contents[opcount++] << '\n';
			}

			ofs.close();
		}


		ifs.close();
	}

	

	return 0;
}