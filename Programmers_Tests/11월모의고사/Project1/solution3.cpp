//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//bool getPop(int UnitSize, int si, int sj, vector<vector<int>>& popByUnit, int thresHold);
//int main() {
//	/**********************
//	첫째 줄 구름시의 크기 N과 기준 S 입력
//	다음 N개의 줄에 N개의 정수인 A[i][1], A[i][2], ... A[i][N] 입력
//	i번째 줄에서 j번째로 주어지는 수는 i행 j열의 해당하는 칸에 거주하는 인구 수.
//	3 <= N <= 1000
//	0 <= S <= 10^9
//	0 <= A[i][j] <= 100
//	모든 수는 정수
//	정할 수 있는 K의 최솟값을 출력한다. 만약 전체 인구수보다 S가 크다면 -1을 출력.
//	**********************/
//	int N, S;
//	cin >> N >> S;
//	int population = 0;
//	int min = S+1;
//	vector<vector<int>> popByUnit;
//	for (int i = 0; i < N; i++) {
//		vector<int> temp(N);
//		for (int j = 0; j < N; j++) {
//			cin >> temp[j];
//			population += temp[j];
//			if (temp[j] < min) min = temp[j];
//		}
//		popByUnit.push_back(temp);
//	}
//	if (S > population) {
//		cout << -1 << '\n';
//		return 0;
//	}
//	if (S <= min) {
//		cout << 1 << '\n';
//		return 0;
//	}
//	bool Success = false;
//	for (int Unit = 1; Unit <= N; Unit++) { // 구획 크기를 1부터 N까지 늘려나감.
//		for (int i = 0; i <= N - Unit; i++) {
//			for (int j = 0; j <= N - Unit; j++) {
//				Success = getPop(Unit, i, j, popByUnit, S);
//				if (!Success) break;
//			}
//			if (!Success) break;
//		}
//		if (Success) {
//			cout << Unit << '\n';
//			return 0;
//		}
//	}
//
//	cout << "Bug Check" << '\n';
//	return 0;
//}
//
//bool getPop(int UnitSize, int si, int sj, vector<vector<int>>& popByUnit, int thresHold) {
//	int N = popByUnit.size();
//	int Pop = 0;
//	for (int i = si; i < si+UnitSize; i++) {
//		for (int j = sj; j < sj+UnitSize; j++) {
//			Pop += popByUnit[i][j];
//			if (Pop >= thresHold) return true;
//		}
//	}
//	return false;
//}