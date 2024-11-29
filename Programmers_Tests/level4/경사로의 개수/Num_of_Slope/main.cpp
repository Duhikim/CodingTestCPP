#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <map>
#define ii pair<int, int>
#define ll unsigned long long

using namespace std;

vector<ii> direction = {
    {0, -1}, {1, 0}, {0, 1}, {-1, 0}
};
ii operator+ (const ii& a, const ii& b) {    
    return { a.first + b.first, a.second + b.second };
}


void OneCycle(const vector<vector<int>>& grid, const vector<int>& d, const ii& coord_start, const ii& coord_current, int ind, vector<vector<map<ii, int>>>& FullData) {
    if (ind == d.size()) {        
        if (FullData[coord_start.second][coord_start.first].find(coord_current) == FullData[coord_start.second][coord_start.first].end()) {
            FullData[coord_start.second][coord_start.first].insert({ coord_current, 1 });
        }
        else {
            FullData[coord_start.second][coord_start.first].find(coord_current)->second += 1;
        }        
        return;
    }

    for (int i = 0; i < 4; i++) {
        ii coord_new = coord_current + direction[i];
        if (coord_new.first < 0
            || coord_new.second < 0
            || coord_new.first >= grid[0].size()
            || coord_new.second >= grid.size()
            || grid[coord_current.second][coord_current.first] + d[ind % d.size()] != grid[coord_new.second][coord_new.first])
            continue;
        OneCycle(grid, d, coord_start, coord_new, ind + 1, FullData);
    }
}
void Get_FullData(const vector<vector<int>>& grid, const vector<int>& d, vector<vector<map<ii, int>>>& FullData) {
    int n = grid.size(); // 세로 길이
    int m = grid[0].size(); // 가로 길이

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {            
            OneCycle(grid, d, { j, i }, { j, i }, 0, FullData);
        }
    }
}
void Print_FullData(vector<vector<map<ii, int>>>& FullData) {
    int n = FullData.size();
    int m = FullData[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (FullData[i][j].size()) {
                cout << "출발 좌표 : { " << j << " , " << i << " }\n";
                for (auto& map1 : FullData[i][j]) {                    
                    cout << "도착 좌표 : { " << map1.first.first << " , " << map1.first.second << " } , 루트 : " << map1.second << '\n';
                }
           }
        }
    }
}


void Search(vector<vector<map<ii, int>>>& FullData, int k, ii coord, int cycle, int xtime, ll& answer) {
    if (cycle == k) {
        answer += xtime;
        while (answer >= 1000000007) { answer -= 1000000007; }// 1,000,000,007 = 10억7       
        
        cout << answer << '\n';
        return;
    }


    if (FullData[coord.second][coord.first].size() == 0) return;
    for (auto& map1 : FullData[coord.second][coord.first]) {
        ii coord_next = map1.first;
        Search(FullData, k, coord_next, cycle + 1, (xtime * map1.second)% 1000000007, answer);
    }

}

int solution(vector<vector<int>> grid, vector<int> d, int k) {
    ll answer = 0;
    int n = grid.size(); // 세로 길이
    int m = grid[0].size(); // 가로 길이

    //FullData : n x m 크기의 행렬. {x, y}좌표에는 해당 좌표에서 한 사이클을 돌았을때 도착할 수 있는 좌표가 벡터로 들어감.
    //vector<vector<vector<ii>>> FullData(n, vector<vector<ii>>(m, vector<ii>(64, {-1, -1})));
    vector<vector<map<ii, int>>> FullData(n, vector<map<ii, int>>(m));

    Get_FullData(grid, d, FullData);
    Print_FullData(FullData);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Search(FullData, k, { j, i }, 0, 1, answer);
        }
    }
    return answer;
}

int main() {
    vector<vector<int>>grid;
    vector<int> d;
    int k;
    ll ans;

    grid = {
        {3, 4, 6, 5, 3}, 
        {3, 5, 5, 3, 6}, 
        {5, 6, 4, 3, 6}, 
        {7, 4, 3, 5, 0}};
    d = {1, -2, -1, 0, 2};
    k = 2;
    ans = solution(grid, d, k);
    cout << "Result : " << ans << '\n';
    if (ans == 16) cout << "정답\n"; else cout << "오답\n";

    grid = {
        {3, 6, 11, 12}, 
        {4, 8, 15, 10}, 
        {2, 7, 0, 16}};
    d = {1, -2, 5};
    k = 3;
    ans = solution(grid, d, k);
    cout << "Result : " << ans << '\n';
    if (ans == 1) cout << "정답\n"; else cout << "오답\n";

    grid = {
        {0, 0, 0}, 
        {1, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 1}, 
        {1, 0, 0}};
    d = {0, 0, 1, -1, 0, 0, 1, -1};
    k = 7;
    ans = solution(grid, d, k);
    cout << "Result : " << ans << '\n';
    if (ans == 595737277) cout << "정답\n"; else cout << "오답\n";
    
}