#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
enum ball_coord {
    X = 0,
    Y = 1
};
enum direction {
    Up = 0,
    Down = 1,
    Left = 2,
    Right = 3
};

int Cushion(const int& m, const int& n, const int& startX, const int& startY, const vector<int>& ball, int direction);

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    vector<int> nomin(4);
    
    for (int i = 0; i < balls.size(); i++) {
        for (int j = 0; j < 4; j++) {
            nomin[j] = Cushion(m, n, startX, startY, balls[i], j);
        }
        answer.push_back(*min_element(nomin.begin(), nomin.end()));
    }
    return answer;
}

int Cushion(const int& m, const int& n, const int& startX, const int& startY, const vector<int>& ball, int direction) {
    
    switch (direction) {
    case Up:
        if (startX == ball[X] && startY < ball[Y]) return 100 * (m * m + n * n); //쿠션에 맞기 전에 1적구에 맞으므로 매우 큰값 리턴
        return (pow((startX - ball[X]), 2) + pow((2 * n - startY - ball[Y]), 2));
    case Down:
        if (startX == ball[X] && startY > ball[Y]) return 100 * (m * m + n * n); //쿠션에 맞기 전에 1적구에 맞으므로 매우 큰값 리턴
        return (pow((startX - ball[X]), 2) + pow((startY + ball[Y]), 2));
    case Left:
        if (startY == ball[Y] && startX > ball[X]) return 100 * (m * m + n * n); //쿠션에 맞기 전에 1적구에 맞으므로 매우 큰값 리턴
        return (pow((startX + ball[X]), 2) + pow((startY - ball[Y]), 2));
    case Right:
        if (startY == ball[Y] && startX < ball[X]) return 100 * (m * m + n * n); //쿠션에 맞기 전에 1적구에 맞으므로 매우 큰값 리턴
        return (pow((2*m - startX - ball[X]), 2) + pow((startY - ball[Y]), 2));
    }
}

int main() {
    int m = 10, n = 10, startX = 3, startY = 7;
    vector<vector<int>> balls = { {7, 7}, {2, 7}, {7, 3} }; 
    for (auto& num : solution(m, n, startX, startY, balls)) {
        cout << num << '\n';    
    } //예상 [52, 37, 116]

    return 0;
}