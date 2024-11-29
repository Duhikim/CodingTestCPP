#include <string>
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

void ShiftRow_Multi(vector<vector<int>>& rc, int time) {
    int row = rc.size();  
    time %= row;
    if (time == 0) return;

    vector<int> temp = rc[0];
    int idx = 0, idx_origin = 0, idx_temp = 0;;
    int counter = row;
    
    while (counter--) {
        idx_origin = idx - time;
        if (idx_origin < 0) idx_origin += row;

        if (idx_origin == idx_temp) {
            rc[idx] = temp;
            idx_temp++;
            idx = idx_temp;
            temp = rc[idx_temp];
            continue;
        }
        rc[idx] = rc[idx_origin];

        idx = idx_origin;
    }
    
    /*cout << time << "번 줄이동\n";
    for (vector<int>& ans : rc) {
        for (int& num : ans) {
            cout << num << "  ";
        } cout << '\n';
    } */
}

void Rotate_Multi(vector<vector<int>>& rc, int time) {
    int row = rc.size();
    int col = rc[0].size();
    int one_cycle = ((col - 1) * 2 + (row - 1) * 2);
    time %= one_cycle;
    if (time == 0) return;    

    int counter = one_cycle;
    int idx = 0, idx_origin = 0, idx_temp=0;
    int temp = rc[0][0];
    
    while (counter--) {
        idx_origin = idx - time;
        if (idx_origin < 0) idx_origin += one_cycle;

        if (idx_origin == idx_temp) {
            if (idx < col) rc[0][idx] = temp;
            else if (idx < col + row - 1) rc[idx - col + 1][col - 1] = temp;
            else if (idx < 2 * col + row - 2) rc[row - 1][2 * col + row - 3 - idx] = temp;
            else rc[one_cycle - idx][0] = temp;
            idx_temp++;
            idx = idx_temp;
            if (idx_temp < col)                       temp = rc[0][idx_temp];
            else if (idx_temp < col + row - 1)        temp = rc[idx_temp - col + 1][col - 1];
            else if (idx_temp < 2 * col + row - 2)    temp = rc[row - 1][2 * col + row - 3 - idx_temp];
            else                                      temp = rc[one_cycle - idx_temp][0];

            continue;
        }
        int origin_val;
        if (idx < col) {
            if (idx_origin < col)                       origin_val = rc[0][idx_origin];
            else if (idx_origin < col + row - 1)        origin_val = rc[idx_origin - col + 1][col - 1];
            else if (idx_origin < 2 * col + row - 2)    origin_val = rc[row - 1][2 * col + row - 3 - idx_origin];
            else                                        origin_val = rc[one_cycle - idx_origin][0];
            rc[0][idx] = origin_val;
        }
        else if (idx < col + row - 1) {
            if (idx_origin < col)                       origin_val = rc[0][idx_origin];
            else if (idx_origin < col + row - 1)        origin_val = rc[idx_origin - col + 1][col - 1];
            else if (idx_origin < 2 * col + row - 2)    origin_val = rc[row - 1][2 * col + row - 3 - idx_origin];
            else                                        origin_val = rc[one_cycle - idx_origin][0];
            rc[idx - col + 1][col - 1] = origin_val;
        }
        else if (idx < 2 * col + row - 2) {
            if (idx_origin < col)                       origin_val = rc[0][idx_origin];
            else if (idx_origin < col + row - 1)        origin_val = rc[idx_origin - col + 1][col - 1];
            else if (idx_origin < 2 * col + row - 2)    origin_val = rc[row - 1][2 * col + row - 3 - idx_origin];
            else                                        origin_val = rc[one_cycle - idx_origin][0];
            rc[row - 1][2 * col + row - 3 - idx] = origin_val;
        }
        else {
            if (idx_origin < col)                       origin_val = rc[0][idx_origin];
            else if (idx_origin < col + row - 1)        origin_val = rc[idx_origin - col + 1][col - 1];
            else if (idx_origin < 2 * col + row - 2)    origin_val = rc[row - 1][2 * col + row - 3 - idx_origin];
            else                                        origin_val = rc[one_cycle - idx_origin][0];
            rc[one_cycle - idx][0] = origin_val;
        }
        idx = idx_origin;
    }

    /*cout << time << "번 회전\n";
    for (vector<int>& ans : rc) {
        for (int& num : ans) {
            cout << num << "  ";
        } cout << '\n';
    }*/
}
void Rotate_Shift_Multi(vector<vector<int>>& rc, int time) {
    //vector<vector<int>> temp = rc;
    int row = rc.size();
    int col = rc[0].size();    
    
    int one_cycle = row;
    int time_temp = time % one_cycle;
    if (time_temp) {
        
        int counter;

        for (int j = 1; j < col - 1; j++) {
            counter = one_cycle;
            int idx = 0, idx_origin = 0, idx_temp = 0;
            int temp = rc[0][j - 1];
            while (counter--) {
                idx_origin = idx - time_temp;
                if (idx_origin < 0) idx_origin += one_cycle;

                if (idx_origin == idx_temp) {
                    rc[idx][j] = temp;
                    idx_temp++;
                    idx = idx_temp;
                    temp = rc[idx_temp][j];
                    continue;
                }

                if (idx == 0) rc[idx][j - 1] = rc[idx_origin][j];
                else rc[idx][j] = rc[idx_origin][j];

                idx = idx_origin;
            }
        }
    }

    if (row % 2 == 1) {
        one_cycle = row + 1;
        time_temp = time % one_cycle;
        if (time_temp) {
            int idx = 0, idx_origin=0, idx_temp = 0;
            int temp = rc[0][col - 2];
            int counter = one_cycle;
            while (counter--){
                idx_origin = idx - time_temp;
                if (idx_origin < 0) idx_origin += one_cycle;
                
                int i;
                if (idx == 0) { i = -1; }
                else if (idx < one_cycle / 2) i = idx * 2 - 1;
                else i = idx * 2 - one_cycle;

                if (idx_origin == idx_temp) {
                    rc[i][col - 1] = temp;
                    idx_temp++;
                    idx = idx_temp;
                    
                    temp = (idx_temp < one_cycle / 2) 
                        ? rc[idx_temp * 2 - 1][col - 1] 
                        : rc[idx_temp * 2 - one_cycle][col - 1];
                    continue;
                }


                int origin_val;                
                if (idx_origin < one_cycle / 2) 
                    origin_val = rc[2 * idx_origin - 1][col - 1];
                else 
                    origin_val = rc[2 * idx_origin - one_cycle][col - 1];
                
                if (i == -1) rc[0][col - 2] = origin_val;
                else rc[i][col - 1] = origin_val;
                
                idx = idx_origin;
            }            
        }
    }
    
    else {
        one_cycle = row / 2;
        time_temp = time % one_cycle;
        if (time_temp) {
            int idx = 0, idx_origin = 0, idx_temp = 0;
            int temp = rc[0][col - 1];
            int counter = one_cycle;

            while (counter--) {
                idx_origin = idx - time_temp;
                if (idx_origin < 0) idx_origin += one_cycle;

                if (idx_origin == idx_temp) {
                    rc[2*idx][col - 1] = temp;
                    idx_temp++;
                    idx = idx_temp;
                    temp = rc[2 * idx_temp][col - 1];
                    continue;
                }
                
                rc[2 * idx][col - 1] = rc[2 * idx_origin][col - 1];

                idx = idx_origin;
            }
        }

        one_cycle += 1;
        time_temp = time % one_cycle;
        if (time_temp) {            
            int idx = 0, idx_origin = 0, idx_temp = 0;
            int temp = rc[0][col - 2];
            int counter = one_cycle;

            while (counter--) {
                idx_origin = idx - time_temp;
                if (idx_origin < 0) idx_origin += one_cycle;

                if (idx_origin == idx_temp) {
                    rc[2 * idx - 1][col - 1] = temp;
                    idx_temp++;
                    idx = idx_temp;
                    temp = rc[2 * idx_temp - 1][col - 1];
                    continue;
                }

                int i;
                if (idx == 0) i = -1;                 
                else i = 2*idx - 1;                

                if (idx == 0) 
                    rc[0][col - 2] = rc[2 * idx_origin - 1][col - 1];
                else 
                    rc[i][col - 1] = rc[2 * idx_origin - 1][col - 1];

                idx = idx_origin;
            }
        }
    }

    /*cout << time << "번 복합 이동(회전 후 열이동)\n";
    for (vector<int>& ans : rc) {
        for (int& num : ans) {
            cout << num << "  ";
        } cout << '\n';
    }*/
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer = rc;
    int row = rc.size();
    int col = rc[0].size();
    int rot_sft = 0;

    int i = 0;
    int rot_shf = 0;
    while (i < operations.size()) {
        int rot = 0, shf = 0;          
        while (i < operations.size() && operations[i][0] == 'R') {
            rot++;
            i++;            
        }
        while (i < operations.size() && operations[i][0] == 'S') {
            shf++;
            i++;
        }

        if (rot > 1 || shf > 1 || rot == 0 || shf == 0) {
            if (!rot_shf) {
                if (rot) Rotate_Multi(answer, rot);
                if (shf) ShiftRow_Multi(answer, shf);
            }
        }
        else {            
            rot_shf++;
            rot = 0;
            shf = 0;
        }

        if (rot_shf) {
            if (i >= operations.size() && rot==0 && shf==0) {
                Rotate_Shift_Multi(answer, rot_shf);
                break;
            }
            else if(!rot && !shf) {
                continue;
            }
            else {
                Rotate_Shift_Multi(answer, rot_shf);
                rot_shf = 0;
                if (rot) Rotate_Multi(answer, rot);
                if (shf) ShiftRow_Multi(answer, shf);
            }            
        }        
    }

    return answer;
}


int main2() {
    vector<vector<int>> rc;
    vector<string> operation;
    vector<vector<int>> answer;
    vector<vector<int>> expected;
    int max_num = 1000000;
    clock_t start, finish;
    double duration;

    rc = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    operation = {"Rotate", "ShiftRow"};
    expected = {{8, 9, 6}, {4, 1, 2}, {7, 5, 3}};
    answer = solution(rc, operation);
    if (expected == answer) cout << "Correct!\n";
    else cout << "Wrong!\n";
   /* cout << "예상 답\n";
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
    }*/


    rc = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };
    operation = { "Rotate", "ShiftRow" };
    expected = { {11, 12, 9}, {4, 1, 2}, {7, 5, 3}, {10, 8, 6} };
    answer = solution(rc, operation);
    if (expected == answer) cout << "Correct!\n";
    else cout << "Wrong!\n";
  /*  cout << "예상 답\n";
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
    }*/

    rc = { {1, 2}, {3,4}};
    operation = { "Rotate", "Rotate" };
    expected = { {4, 3}, {2, 1} };
    answer = solution(rc, operation);
    if (expected == answer) cout << "Correct!\n";
    else cout << "Wrong!\n";
    /*cout << "예상 답\n";
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
    }*/

    rc = {{8, 6, 3}, {3, 3, 7}, {8, 4, 9}};
    operation = {"Rotate", "ShiftRow", "ShiftRow"};
    expected = {{8, 3, 3}, {4, 9, 7}, {3, 8, 6}};
    answer = solution(rc, operation);
    if (expected == answer) cout << "Correct!\n";
    else cout << "Wrong!\n";
    ///*cout << "예상 답\n";
    //for (vector<int>& ex : expected) {
    //    for (int& num : ex) {
    //        cout << num << "  ";
    //    } cout << '\n';
    //}
    //cout << "계산된 답\n";
    //for (vector<int>& ans : answer) {
    //    for (int& num : ans) {
    //        cout << num << "  ";
    //    } cout << '\n';
    //}*/

    rc = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    operation = {"ShiftRow", "Rotate", "ShiftRow", "Rotate"};
    expected = {{1, 6, 7, 8}, {5, 9, 10, 4}, {2, 3, 12, 11}};
    answer = solution(rc, operation);
    if (expected == answer) cout << "Correct!\n";
    else cout << "Wrong!\n";
    ///*cout << "예상 답\n";
    //for (vector<int>& ex : expected) {
    //    for (int& num : ex) {
    //        cout << num << "  ";
    //    } cout << '\n';
    //}
    //cout << "계산된 답\n";
    //for (vector<int>& ans : answer) {
    //    for (int& num : ans) {
    //        cout << num << "  ";
    //    } cout << '\n';
    //}*/



    rc.clear();
    rc.resize(316);
    for (int i=0; i<316; i++)
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
      if(i%2)operation[i] = "ShiftRow";        
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