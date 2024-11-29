#include <iostream>
#include <string>
#include <vector>
#define ii pair<int, int>

using namespace std;
enum Color {
    Red,
    Blue
};
vector<pair<int, int>> Move = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0},
};
ii operator+(const ii& a, const ii& b) {
    return { a.first + b.first, a.second + b.second };
}
ii operator+=(ii& a, const ii& b) {
    a.first += b.first;
    a.second += b.second;
    return a;
}

bool CanGo(const vector<vector<int>>& maze, pair<int, int> coord) {
    if (coord.first <0 ||
        coord.second < 0 ||
        coord.first >= maze[0].size() ||
        coord.second >= maze.size() ||
        maze[coord.second][coord.first] == 5
        )  
        return false;    
    return true;
}
bool Visited(pair<int, int> coord, vector<vector<pair<bool, bool>>>& visited, int color) {
    if (color == Red) {
        if (visited[coord.second][coord.first].first)
            return true;
        return false;
    }
    else {
        if (visited[coord.second][coord.first].second)
            return true;
        return false;
    }
}

void DFS(const vector<vector<int>>& maze, pair<int, int> red_coord, pair<int, int> blue_coord, int counter, int& answer, vector<vector<pair<bool, bool>>>& visited) {
    if (//maze[레드y축][레드x축] == 3 && maze[블루 y축][블루 x축] == 4
        maze[red_coord.second][red_coord.first] == 3 && maze[blue_coord.second][blue_coord.first] == 4
        ) {
        answer = min(answer, counter);
        return;
    }

    for (int i = 0; i < 4; i++) {
        //Red 이동 
        ii newred = red_coord;

        if (maze[newred.second][newred.first] != 3) {
            newred += Move[i];

            if (!CanGo(maze, newred) || Visited(newred, visited, Red)) 
                continue;
            
            visited[newred.second][newred.first].first = true;
        }

        for (int j = 0; j < 4; j++) {
            //Blue 이동
            ii newblue = blue_coord;

            if (maze[newblue.second][newblue.first] != 4) {
                newblue += Move[j];

                if (!CanGo(maze, newblue) || Visited(newblue, visited, Blue))
                    continue;                
            }

            if (newred == newblue || ((red_coord == newblue) && (blue_coord == newred)))
                continue;
            
            visited[newblue.second][newblue.first].second = true;
            DFS(maze, newred, newblue, counter + 1, answer, visited);
            visited[newblue.second][newblue.first].second = false;
        }
        visited[newred.second][newred.first].first = false;
    }
}

int solution(vector<vector<int>> maze) {
    int answer = 1000;
    /*  0	빈칸
        1	빨간 수레의 시작 칸
        2	파란 수레의 시작 칸
        3	빨간 수레의 도착 칸
        4	파란 수레의 도착 칸
        5	벽*/
    int n = maze.size();    // 세로 길이
    int m = maze[0].size(); // 가로 길이
    pair<int, int> red_pos, blue_pos; // x, y축 좌표
    vector<vector<pair<bool, bool>>> visited(4, vector<pair<bool, bool>>(4, { false, false })); // visited[x][y].first : x,y 좌표의 레드 방문 여부, visited[x][y].second : x, y 좌표의 블루 방문 여부

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 1) {
                red_pos = { j,i };                
            }
            if (maze[i][j] == 2) {
                blue_pos = { j,i };                
            }
        }
    }

    visited[red_pos.second][red_pos.first].first = true;
    visited[blue_pos.second][blue_pos.first].second = true;

    DFS(maze, red_pos, blue_pos, 0, answer, visited);

    return answer == 1000? 0: answer;
}

int main() {
    vector<vector<int>> maze;

    maze.clear();
    maze = { {1, 4}, {0, 0}, {2, 3} };
    cout << "예상 3, 답 : " << solution(maze) << '\n';

    maze.clear();
    maze = {{1, 0, 2}, {0, 0, 0}, {5, 0, 5}, {4, 0, 3}};
    cout << "예상 7, 답 : " << solution(maze) << '\n';

    maze.clear();
    maze = {{1, 5}, {2, 5}, {4, 5}, {3, 5}};
    cout << "예상 0, 답 : " << solution(maze) << '\n';

    maze.clear();
    maze = {{4, 1, 2, 3}};
    cout << "예상 0, 답 : " << solution(maze) << '\n';

    return 0;
}