#include<iostream>
#include<string>
using namespace std;

int main() {	
	int N, M;
	cin >> N >> M;
	
	cout << "SN " << N;
	
	if (M <= 26) {
		cout << (char)(M + 'A' - 1) << endl;
	}
	else {
		string num = "";
		while(M > 0) {
			M--;
			num = (char)(M % 26 + 'a') + num;
			M /= 26;
		}
		cout << num << endl;
	}	
	
	return 0;

}