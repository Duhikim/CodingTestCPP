#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int counter;
void counting(vector<vector<int>>& targets);

int solution(vector<vector<int>> targets) {
    int answer = 0;
    counter = 0;
    
    sort(targets.begin(), targets.end());   

    counting(targets);

    answer = counter;
    return answer;
}

void counting(vector<vector<int>>& ref_vec) {   
    counter++;
    if (ref_vec.size() == 1) {
         
        return;
    }
    
    int ref_index = 0;    
    for (int i = 1; i < ref_vec.size(); i++) {
        if (ref_vec[ref_index][1] > ref_vec[i][0]) {
            if (ref_vec[ref_index][1] >= ref_vec[i][1]) {
                ref_index = i;
            }
            //else {아무것도 안함}
        }
        else {
            counter++;
            ref_index = i;
        }
    }

    return;
}

int main() {
    vector<vector<int>> targets1 = { {4, 5},{4, 8 }, {10, 14},{11, 13},{5, 12},{3, 7},{1, 4 } };
    //result : 3
    cout << solution(targets1) << '\n';

    return 0;
}