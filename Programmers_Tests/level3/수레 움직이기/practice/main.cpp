#include <iostream>
#include <vector>
#define ii pair<int, int>

using namespace std;
enum Color {
	Red, Blue
};
vector<ii> Move{
	{0, -1}, // Up
	{1, 0}, // Right
	{0, 1}, // Down
	{-1, 0} // Left
};
ii operator+=(ii& a, ii b) {
	a.first += b.first;
	a.second += b.second;
	return a;
}

bool Visited(const vector<vector<pair<bool, bool>>>& visited, ii coord, int color) {
	if (color == Red) 
		return visited[coord.second][coord.first].first;
	
	else 
		return visited[coord.second][coord.first].second;	
}

bool CantGo(const vector<vector<int>>& maze, ii coord) {
	int n = maze.size(); // 세로 길이
	int m = maze[0].size(); // 가로 길이

	return (coord.first < 0 || coord.first >= m || coord.second < 0 || coord.second >= n || maze[coord.second][coord.first] == 5);
}


void Search(const vector<vector<int>>& maze, ii red, ii blue, vector<vector<pair<bool, bool>>>& visited, int& answer, int counter) {
	if (maze[red.second][red.first] == 3 &&
		maze[blue.second][blue.first] == 4) {
		if (counter < answer || !answer) answer = counter;
		return;
	}
	for (int i = 0; i < 4; i++) {
		ii new_red = red;
		
		if (maze[new_red.second][new_red.first] != 3) {
			new_red += Move[i]; // Up, Right, Down, Left 순서
			if (CantGo(maze, new_red) || Visited(visited, new_red, Red)) continue;
			visited[new_red.second][new_red.first].first = true;
		}

		for (int j = 0; j < 4; j++) {
			ii new_blue = blue;
			
			if (maze[new_blue.second][new_blue.first] != 4) {
				new_blue += Move[j]; // Up, Right, Down, Left 순서
				if (CantGo(maze, new_blue) ||					// 벽이거나 타일을 벗어남
					Visited(visited, new_blue, Blue))			// 이미 방문한 칸
					continue;

				
			}
			if (new_blue == new_red ||						// 두 수레가 같은 칸으로 이동
				((new_blue == red) && (new_red == blue)))	// 두 수레가 서로 바뀌는 이동
				continue;

			visited[new_blue.second][new_blue.first].second = true;
			Search(maze, new_red, new_blue, visited, answer, counter + 1);
			visited[new_blue.second][new_blue.first].second = false;
		}
		visited[new_red.second][new_red.first].first = false;
	}
	return;
}

int solution(vector<vector<int>> maze) {
	int answer = 0;
	
	int n = maze.size(); // 세로 길이
	int m = maze[0].size(); // 가로 길이
	ii red, blue;
	vector<vector<pair<bool, bool>>> visited(4, vector<pair<bool, bool>>(4, { 0, 0 }));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i][j] == 1) red = { j, i };
			if (maze[i][j] == 2) blue = { j, i };
		}
	}

	visited[red.second][red.first].first = true;
	visited[blue.second][blue.first].second = true;
	Search(maze, red, blue, visited, answer, 0);

	return answer;
}

int main() {
	vector<vector<int>> maze;
		
	//maze = { {1, 4}, {0, 0}, {2, 3} };
	//cout << "기대값 3, 계산값 : " << solution(maze) << '\n';
	//
	//maze = {{1, 0, 2}, {0, 0, 0}, {5, 0, 5}, {4, 0, 3}};
	//cout << "기대값 7, 계산값 : " << solution(maze) << '\n';

	//maze = {{1, 5}, {2, 5}, {4, 5}, {3, 5}};
	//cout << "기대값 0, 계산값 : " << solution(maze) << '\n';

	//maze = {{4, 1, 2, 3}};
	//cout << "기대값 0, 계산값 : " << solution(maze) << '\n';

	maze = { {1, 0, 0, 0},
			 {0, 0, 0, 0},
			 {0, 4, 5, 0} ,
			 {5, 0, 3, 2} };
	cout << "기대값 5, 계산값 : " << solution(maze) << '\n';
		
	return 0;
}