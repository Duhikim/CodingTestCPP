#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;    
    
    int number = 0;
    int min_of_s = *min_element(starts.begin(), starts.end());

    // 테이블을 만들고 반복 횟수를 기준으로 내림차 정렬을 함. 
    // 다음에 starts의 요소들과 비교해서 위에서부터 first숫자를 비교. 
    // first 숫자가 starts의 요소와 e 사이면 second 숫자를 push_back.

    vector<pair<int, int>> num_time;

    for (int i = 1; i <= e; i++) {
        for (int j = 1; j <= e; j++) {
            number = i * j;
            if (number > e) break;
            if (number < min_of_s) continue;
            //vector의 first에 해당 숫자가 있는지 탐색
            auto iter = find_if(num_time.begin(), num_time.end(), 
                [number](const pair<int, int>& p) {return p.first == number; });
            if (iter == num_time.end()) {
                num_time.push_back({ number, 1 });
            }
            else {
                iter->second++;
            }
        }
    }
    //두번째 요소를 기준으로 내림차 정렬.
    sort(num_time.begin(), num_time.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
        });
    
    for (int s : starts) {
        for (const pair<int, int>& p : num_time) {
            if (p.first >= s) {
                answer.push_back(p.first);
                break;
            }
        }
    }  
    
    return answer;
}

int main() {
    int e;
    vector<int> starts;
    vector<int> expected;
    vector<int> results;

    e = 8;
    starts = { 1, 3, 7 };
    expected = { 6, 6, 8 };
    results = solution(e, starts);
    if (expected == results) cout << "Correct!" << '\n';
    else cout << "Wrong.." << '\n';

    return 0;
}