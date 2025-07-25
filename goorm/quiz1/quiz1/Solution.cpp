#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
long long T;
vector<int> getPosition(const vector<string>* field, long long goalSteps);
vector<vector<int>> directions = {
	{0, 1},  // right
	{1, 0},  // down
	{0, -1}, // left
	{-1, 0}  // up
};

int main() {

	cin >> N >> M >> T;
	vector<string> field(N);
	for (int i = 0; i < N; i++) {
		cin >> field[i];
	}
	
	vector<int> position = getPosition(&field, T);
	cout << position[0]+1 << " " << position[1]+1 << endl;

}

vector<int> getPosition(const vector<string>* field, long long goalSteps) {
	int steps = 0;
	vector<vector<bool>> visited(N, vector<bool>(M, false));		
	int currR = 0, currC = 0;

	while (steps < goalSteps) {
		for (int i = 0; i < 4; i++) {
			int nextR = currR + directions[i][0];
			int nextC = currC + directions[i][1];
			if(nextR >= 0 && nextR < N && nextC >= 0 && nextC < M &&
				(*field)[nextR][nextC] == 'O' && !visited[nextR][nextC]) {
				visited[nextR][nextC] = true;				
				currR = nextR;
				currC = nextC;
				steps++;
				break; 
			}
		}
		if (currR == 0 && currC == 0) {
			// 현재 steps가 한바퀴를 돌았다는 의미
			return getPosition(field, goalSteps % steps);
		}
	}

	return {currR, currC};
}