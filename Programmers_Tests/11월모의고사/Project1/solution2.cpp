//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//void Search(int Start, int Target, int currentDataSize, vector<vector<int>>& cables, vector<bool>& visited, int& min);
//
//int main() {
//	/*************
//	첫째 줄에 통신탑 수 N과 케이블 수 M 입력.
//	둘째 줄에 데이터 전송 시작하는 통신탑의 번호 S, 데이터를 받는 통신탑의 번호 E 입력.
//	다음 M개의 줄에 ai, bi, ki가 공백을 두고 주어짐. 
//		ai와 bi를 연결하는 케이블의 데이터 전송 한계가 ki라는 의미
//	2<= N <= 200 000
//	1 <= M <= 300 000
//	1 <= S,E <= N; S!=E
//	1 <= ai, bi <= N; ai != bi
//	1 <= k1 <= 200 000
//	입력값은 모두 정수.
//
//	S에서 E로 크기 1짜리 데이터를 보낼 때 도착 데이터의 최소 크기를 출력. 불가능 한경우 -1 출력.
//	***************/
//
//	int N, M, S, E;
//	cin >> N >> M >> S >> E;
//	
//	vector<vector<int>> cables;
//	for (int i = 0; i < M; i++) {
//		vector<int> temp(3);
//		cin >> temp[0] >> temp[1] >> temp[2];
//		cables.push_back(temp);
//	}
//	vector<bool> visited(N+1, false);
//	int min = -1;
//	Search(S, E, 1, cables, visited, min);
//	cout << min << '\n';
//
//	return 0;
//}
//
//void Search(int Start, int Target, int currentDataSize, vector<vector<int>>& cables, vector<bool>& visited, int& min) {
//	if (Start == Target) {
//		if (min == -1 || currentDataSize < min)
//			min = currentDataSize;
//		return;
//	}
//	for (int i = 0; i < cables.size(); i++) {
//		// 가장 먼저 데이터 사이즈가 케이블 용량보다 작거나 같아야 함.
//		if (currentDataSize <= cables[i][2]) {
//			if (cables[i][0] == Start
//				&& visited[cables[i][1]] == false) {
//				visited[cables[i][1]] = true;
//				Search(cables[i][1], Target, currentDataSize + 1, cables, visited, min);
//				visited[cables[i][1]] = false;
//			}
//			else if (cables[i][1] == Start
//				&& visited[cables[i][0]] == false) {
//				visited[cables[i][0]] = true;
//				Search(cables[i][0], Target, currentDataSize + 1, cables, visited, min);
//				visited[cables[i][0]] = false;
//			}
//		}
//		else continue;
//	}
//}