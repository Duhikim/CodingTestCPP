#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	// ���η� �ڸ��� ������ ���η� �ڸ��� �̵�, ���η� �ڸ��� ������ ���η� �ڸ��� �̵�
	// ���� �׳� �����ѹ� �����ѹ��� �����ư��鼭 �ڸ��� ��.
	// ���η� �ڸ��� ���μ�+1���� ������ ������
	// ���η� �ڸ��� ���μ�+1���� ������ ������

	int hor = 0, ver = 0;
	int pieces = 1;
	for (int i = 1; i <= N; i++) { // i�� Ȧ���� ����, ¦���� ���η� �ڸ���.
		if (i % 2 == 1) {
			hor++;
			pieces += ver + 1;
		}
		else {
			ver++;
			pieces += hor + 1;
		}
	} cout << pieces << endl;
	return 0;
}