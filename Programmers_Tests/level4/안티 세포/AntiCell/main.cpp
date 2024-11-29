#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;
int mod = 1000000007;

class AntiCell {
private:
    int size;
    int ACIdx;
    int ACSize;

    AntiCell();
    ~AntiCell();
};

void Search(vector<int>& b, vector<int>& c, set<vector<int>>& cs,
            int prev_prev, int prev_val, int curr_val, int idx)
{
    if (idx == b.size()) {
        cs.insert(c);
        return;
    }

    if (prev_val == 0
        || prev_val != curr_val) {
        Search(b, c, cs, prev_val, curr_val, b[idx+1], idx + 1);
    }
    else {
        Search(b, c, cs, prev_val, curr_val, b[idx + 1], idx + 1); // 합치지 않음
        Search(b, c, cs, prev_prev, prev_prev, 2 * curr_val, idx); // 합침

        
    }
}

int NumOfCase(vector<int>& b) {
    vector<int> c;
    set<vector<int>> cs;
    vector<int> CellIdx(b.size(), 0);
    map<int, int> CellSize;

    Search(b, c, cs, 0, 0, b[0], 0);


    return cs.size() % mod;
}

vector<int> solution(vector<int> a, vector<int> s) {
    vector<int> answer;

    int idx = 0;
    for (int& size : s) {
        vector<int> b;
        for (int i = idx; i < idx+size; i++) {
            b.push_back(a[i]);
        }
        answer.push_back(NumOfCase(b));
        idx += size;
    }

    return answer;
}

int main() {
    vector<int> a, s;
    vector<int> result;

    a = { 1, 1, 1, 1, 1, 1, 2, 5, 8, 2, 1, 1, 4, 8, 8, 8, 12, 6, 6 };
    s = { 4, 3, 1, 5, 6 };
    result = solution(a, s);
    for (int& num : result) {
        cout << num << " ";
    } cout << '\n';

}
