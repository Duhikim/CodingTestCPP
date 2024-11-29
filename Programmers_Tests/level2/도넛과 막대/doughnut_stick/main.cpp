#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;
bool debug = true;
             //false;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);

    set<int> all_numbers;
    for (const auto& v1 : edges) {
        all_numbers.insert(v1[0]);
        all_numbers.insert(v1[1]);
    }
    map<int, int> find_index;
    int index = 0;
    for (const auto& num1 : all_numbers) {
        find_index.insert({ num1, index++ });
    }
    
    vector<vector<int>> all_data;
    vector<int> ea_data(4, 0); // {0점 번호, 1Leaving 수, 2Entering 수, 3중심점에서 받았는지(bool처럼 사용할 예정)}
    for (const auto& v1 : all_numbers) {
        ea_data[0] = v1;
        all_data.push_back(ea_data);
    }

    for (const auto& v1 : edges) {
        all_data[find_index[v1[0]]][1]++;
        all_data[find_index[v1[1]]][2]++;
    }

    int center_point=0;
    for (const auto& v1 : all_data) {
        if (v1[1] > 1 && !v1[2]) { //Leaving이 2 이상이며 Entering이 0인 경우 중심점이다.
            center_point = v1[0];
            break;
        }
    }

    int total_qty = 0;
    for (const auto& v1 : edges) {
        if (v1[0] == center_point) {
            all_data[find_index[v1[1]]][3] = 1;
            total_qty++;
        }
    }

    int amount_doughnut = 0;
    int amount_column = 0;
    int amount_eightshape = 0;
    
    for (const auto& v1 : all_data) {
        if (!v1[1]) { 
            amount_column++; //Leaving이 0인 포인트의 수가 막대 모양 그래프의 수와 같다.
        } 
        if ((v1[1] == 2) && ((v1[2] == 2) || ((v1[2] == 3) && (v1[3])))) { //(Leaving이 2 이면서,) && ((Entering이 2 이거나,) || (Entering이 3이며 && 중심점이 1이거나))
            amount_eightshape++;        
        }
    }
    amount_doughnut = total_qty - (amount_column + amount_eightshape);
    
    answer[0] = center_point;
    answer[1] = amount_doughnut;
    answer[2] = amount_column;
    answer[3] = amount_eightshape;
    return answer;
}


int main() {
    vector<vector<int>> edges1 = { 
        {2, 3}, {4, 3}, 
        {1, 1}, {2, 1} }; 
    if (debug) {
        for (auto num : solution(edges1)) {
            cout << num << " , ";
        } cout << '\n' << '\n';
    }
    // 기대값 {2, 1, 1, 0} (생성한 정점 번호, 도나쓰 모양 수, 막대 모양 수, 8자 모양 수)

    vector<vector<int>> edges2 = {
        {4, 11}, {1, 12}, {8, 3}, {12, 7}, {4, 2}, 
        {7, 11}, {4, 8}, {9, 6}, {10, 11}, {6, 10}, 
        {3, 5}, {11, 1}, {5, 3}, {11, 9}, {3, 8}
    };
    if (debug) {
        for (auto num : solution(edges2)) {
            cout << num << " , ";
        } cout << '\n' << '\n';
    }
    // 기대값 {4, 0, 1, 2} (생성한 정점 번호, 도나쓰 모양 수, 막대 모양 수, 8자 모양 수)


}