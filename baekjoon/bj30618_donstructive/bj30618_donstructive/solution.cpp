#include <iostream>
#include <vector>	
#include <string>	
#include <algorithm>
using namespace std;

// N���� ���ڷ� �̷���� �������� i��° ���ڰ�, �� ������ ���Ӻκм����� �����ϴ� Ƚ���� i * (N - i + 1)�̴�.
// ������ ����� ������ 2���Լ��� ����� ������ ���� ũ��. �� ���� �����Ѵ�.
// ���ֵ����ϴ� ���� ������� ū���ڸ� ��ġ�ϸ� ���� ū ������ ���� �� �ִ�.

int main() {
	int N;
	cin >> N;

	vector<int> permutation(N);

	for (int i = 0; i < N / 2; i++) {
		permutation[i] = 2*i + 1;
		permutation[N - i - 1] = 2*i + 2;
	}
	if(N % 2 == 1) {
		permutation[N / 2] = N;
	}

	for (int i = 0; i < N-1; i++) {
		cout << permutation[i] << " ";
	} cout << permutation[N - 1] << endl;

	return 0;
}

