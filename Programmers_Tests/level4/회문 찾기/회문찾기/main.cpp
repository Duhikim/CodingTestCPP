#include <iostream>
#include <vector>

using namespace std;

int solution(const vector<string>& matrix, int len) {
	int counter = 0;
	for (int i = 0; i <= 8 - len; i++) {
		for (int j = 0; j <= 8 - len; j++) {
			int len_temp = len;
			int temp = j;
			while (true) {
				if (len_temp == 1 || len_temp == 0) counter++;
				if (matrix[i][temp] != matrix[i][temp + len - 1]) break;
				len_temp -= 2;
				temp++;
			}
			len_temp = len;
			temp = i;
			while (true) {
				if (len_temp == 1 || len_temp == 0) counter++;
				if (matrix[temp][j] != matrix[temp + len - 1][j]) break;
				len_temp -= 2;
				temp++;
			}
		}
	}
	return counter;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 1;

	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int length;
		cin >> length;
		
		vector<string> matrix(8);
		for (int i = 0; i < 8; i++) {
			string str_temp;
			cin >> str_temp;
			matrix[i] = str_temp;
		}
		
		cout << "#"<<test_case<< " " << solution(matrix, length) << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}