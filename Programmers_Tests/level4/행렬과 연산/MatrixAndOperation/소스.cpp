#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <ctime>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    
    int row = rc.size(), col = rc[0].size();
    
    deque<int> col_first, col_last;
    deque<deque<int>> mat_field;

    for (int i = 0; i < row; i++) {
        col_first.push_back(rc[i][0]);
        col_last.push_back(rc[i][col - 1]);

        deque<int> temp;
        for (int j = 1; j < col - 1; j++) {
            temp.push_back(rc[i][j]);
        }
        mat_field.push_back(temp);
    }

    for (string& op : operations) {
        if (op[0] == 'R') {
            mat_field[0].push_front(move(col_first.front()));
            col_first.pop_front();
            col_last.push_front(move(mat_field[0].back()));
            mat_field[0].pop_back();
            mat_field[row - 1].push_back(move(col_last.back()));
            col_last.pop_back();
            col_first.push_back(move(mat_field[row - 1].front()));
            mat_field[row-1].pop_front();
            
        }
        else {
            col_first.push_front(move(col_first.back()));
            col_first.pop_back();
            mat_field.push_front(move(mat_field.back()));
            mat_field.pop_back();
            col_last.push_front(move(col_last.back()));            
            col_last.pop_back();
        }
    }

    for (int i = 0; i < row; i++) {
        vector<int> temp;
        temp.push_back(col_first[i]);
        for (int& num : mat_field[i]) {
            temp.push_back(num);
        }
        temp.push_back(col_last[i]);
        answer.push_back(temp);
    }

    return answer;
}

int main() {
    vector<vector<int>> rc;
    vector<string> operation;
    vector<vector<int>> answer;
    vector<vector<int>> expected;
    int max_num = 1000000;
    clock_t start, finish;
    double duration;

    rc = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    operation = { "Rotate", "ShiftRow" };
    expected = { {8, 9, 6}, {4, 1, 2}, {7, 5, 3} };
    answer = solution(rc, operation);
    if (expected == answer) std::cout << "Correct!\n";
    else std::cout << "Wrong!\n";
     cout << "예상 답\n";
     for (vector<int>& ex : expected) {
         for (int& num : ex) {
             cout << num << "  ";
         } cout << '\n';
     }
     cout << "계산된 답\n";
     for (vector<int>& ans : answer) {
         for (int& num : ans) {
             cout << num << "  ";
         } cout << '\n';
     }


    rc = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };
    operation = { "Rotate", "ShiftRow" };
    expected = { {11, 12, 9}, {4, 1, 2}, {7, 5, 3}, {10, 8, 6} };
    answer = solution(rc, operation);
    if (expected == answer) cout << "Correct!\n";
    else cout << "Wrong!\n";
      cout << "예상 답\n";
      for (vector<int>& ex : expected) {
          for (int& num : ex) {
              cout << num << "  ";
          } cout << '\n';
      }
      cout << "계산된 답\n";
      for (vector<int>& ans : answer) {
          for (int& num : ans) {
              cout << num << "  ";
          } cout << '\n';
      }

    rc = { {1, 2}, {3,4} };
    operation = { "Rotate", "Rotate" };
    expected = { {4, 3}, {2, 1} };
    answer = solution(rc, operation);
    if (expected == answer) cout << "Correct!\n";
    else cout << "Wrong!\n";
    cout << "예상 답\n";
    for (vector<int>& ex : expected) {
        for (int& num : ex) {
            cout << num << "  ";
        } cout << '\n';
    }
    cout << "계산된 답\n";
    for (vector<int>& ans : answer) {
        for (int& num : ans) {
            cout << num << "  ";
        } cout << '\n';
    }

    rc = { {8, 6, 3}, {3, 3, 7}, {8, 4, 9} };
    operation = { "Rotate", "ShiftRow", "ShiftRow" };
    expected = { {8, 3, 3}, {4, 9, 7}, {3, 8, 6} };
    answer = solution(rc, operation);
    if (expected == answer) cout << "Correct!\n";
    else cout << "Wrong!\n";
    cout << "예상 답\n";
    for (vector<int>& ex : expected) {
        for (int& num : ex) {
            cout << num << "  ";
        } cout << '\n';
    }
    cout << "계산된 답\n";
    for (vector<int>& ans : answer) {
        for (int& num : ans) {
            cout << num << "  ";
        } cout << '\n';
    }

    rc = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    operation = { "ShiftRow", "Rotate", "ShiftRow", "Rotate" };
    expected = { {1, 6, 7, 8}, {5, 9, 10, 4}, {2, 3, 12, 11} };
    answer = solution(rc, operation);
    if (expected == answer) cout << "Correct!\n";
    else cout << "Wrong!\n";
    cout << "예상 답\n";
    for (vector<int>& ex : expected) {
        for (int& num : ex) {
            cout << num << "  ";
        } cout << '\n';
    }
    cout << "계산된 답\n";
    for (vector<int>& ans : answer) {
        for (int& num : ans) {
            cout << num << "  ";
        } cout << '\n';
    }



    rc.clear();
    rc.resize(316);
    for (int i = 0; i < 316; i++)
        rc[i].resize(316);

    for (int i = 0; i < 316; i++) {
        for (int j = 0; j < 316; j++) {
            rc[i][j] = rand() % max_num;
        }
    }

    operation.resize(100000);
    for (int i = 0; i < 100000; i++) {
        int temp = rand() % 2;
        if (temp)
            operation[i] = "ShiftRow";
        else operation[i] = "Rotate";
    }

    cout << "시간을 재기 위한 테스트 케이스. 시작!\n";
    start = clock();
    answer = solution(rc, operation);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;



    rc.clear();
    rc.resize(50000);
    for (int i = 0; i < 50000; i++)
        rc[i].resize(2);

    for (int i = 0; i < 50000; i++) {
        for (int j = 0; j < 2; j++) {
            rc[i][j] = rand() % max_num;
        }
    }

    operation.resize(100000);
    for (int i = 0; i < 100000; i++) {
        if (i % 2)operation[i] = "ShiftRow";
        else operation[i] = "Rotate";
    }

    cout << "시간을 재기 위한 테스트 케이스. 시작!\n";
    start = clock();
    answer = solution(rc, operation);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;


    return 0;
}