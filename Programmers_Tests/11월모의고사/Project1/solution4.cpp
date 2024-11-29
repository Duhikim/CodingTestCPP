//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//void processQuery(int query, int num1, int num2, vector<int>& A);
//
//int main() {
//	int N, Q;
//	cin >> N >> Q;
//	
//	vector<int> A(N);
//	for (int i = 0; i < N; i++) {
//		cin >> A[i];
//	}
//
//	int Query;
//	int num1, num2;
//	for (int i = 0; i < Q; i++) {
//		cin >> Query >> num1 >> num2;
//		processQuery(Query, num1, num2, A);
//	}
//
//	return 0;
//}
//
//void processQuery(int query, int num1, int num2, vector<int>& A) {
//	int weedLen = 0;
//	switch (query) {
//	case 1:		
//		for (int i = num1; i <= num2; i++) {
//			weedLen += A[i-1];
//		}
//		cout << weedLen << '\n';
//		return;
//	case 2:
//		A[num1-1] += num2;
//		return;
//	case 3:
//		A[num1-1] -= num2;
//		if (A[num1-1] < 0) A[num1] = 0;
//		return;
//	}
//}