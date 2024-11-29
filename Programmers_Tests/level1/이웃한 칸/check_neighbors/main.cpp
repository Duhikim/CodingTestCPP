#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;

    int n = board[0].size();
    int count = 0;
    int dh[4] = { 0,1,-1,0 };
    int dw[4] = { 1,0,0,-1 };

    for (int i = 0; i < 4; i++) {
        int h_check = h + dh[i];
        int w_check = w + dw[i];
        if (h_check >= 0 && h_check < n && w_check >= 0 && w_check < n) {
            if (board[h][w] == board[h_check][w_check]) count++;
        }
    }

    answer = count;

    return answer;
}

int main() {
    vector<vector<string>> board1 =
    { {"blue",   "red",      "orange",   "red"}
    ,{"red",    "red",      "blue",     "orange"}
    ,{"blue",   "orange",   "red",      "red"}
    ,{"orange", "orange",   "red",      "blue"} };
    int h1 = 1, w1 = 1;
    cout << solution(board1, h1, w1) << '\n'; // 예상 2

    vector<vector<string>> board2 =
    { {"yellow",    "green",    "blue"}
    , {"blue",      "green",    "yellow"}
    , {"yellow",    "blue",     "blue"} };
    int h2 = 0, w2 = 1;
    cout << solution(board1, h1, w1) << '\n'; // 예상 1
    
    return 0;
}