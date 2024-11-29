#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool debug = true;
             //false;
enum WinLose {
    Win,
    Draw,
    Lose,
    Index
};
vector<vector<int>> make_combinations(int n);
vector<vector<int>> make_enemy(const vector<vector<int>>& combinations, int n);
vector<int> match(const vector<int>& combA, const vector<int>& combB, const vector<vector<int>>& dice, int i);


vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    vector<vector<int>> combinationsA = make_combinations(dice.size());
    vector<vector<int>> combinationsB = make_enemy(combinationsA, dice.size());

    vector<vector<int>> score_board(combinationsA.size());
    for (int i = 0; i < combinationsA.size(); i++) {
        vector<int> score = match(combinationsA[i], combinationsB[i], dice, i);
        score_board.push_back(score);
    }
    sort(score_board.rbegin(), score_board.rend());
    answer = combinationsA[score_board[0][3]];

    for (int& num : answer) {
        num += 1;
    }
    return answer;
}

vector<vector<int>> make_combinations(int n) {
    int k = n / 2;
    vector<std::vector<int>> combinations;

    vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }
    vector<bool> selector(n);
    fill(selector.begin(), selector.begin() + k, true);

    do {
        std::vector<int> combination;
        for (int i = 0; i < n; ++i) {
            if (selector[i]) {
                combination.push_back(indices[i]);
            }
        }
        combinations.push_back(combination);
    } while (std::prev_permutation(selector.begin(), selector.end()));
    
   
    return combinations;
}
vector<vector<int>> make_enemy(const vector<vector<int>>& combinations, int n) {
    vector<vector<int>> enemy;
    
    int counter = combinations.size();
    int mainI = 0;
    while (counter) {        
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                if (i == combinations[mainI][j]) break;
                if (j == n / 2 - 1) temp.push_back(i);
            }
        }
        enemy.push_back(temp);
        mainI++;
        counter--;
    }
  

    return enemy;
}
vector<int> match(const vector<int>& combA, const vector<int>& combB, const vector<vector<int>>& dice, int i) {
    vector<int> score(4, 0);
    score[Index] = i;
    int n = dice.size();
    int k = n / 2;

    vector<int> sum_of_diceA;
    for (int a = 0; a < 6; a++) {
        int sum = 0;
        if(k>1)
        for (int b = 0; b < 6; b++) {
            if(k>2)
            for (int c = 0; c < 6; c++) {
                if(k>3)
                for (int d = 0; d < 6; d++) {
                    if(k>4) // k=5
                    for (int e = 0; e < 6; e++) { 
                        sum = dice[combA[0]][a] + dice[combA[1]][b] + dice[combA[2]][c] + dice[combA[3]][d] + dice[combA[4]][e];
                        sum_of_diceA.push_back(sum);
                    }
                    else { //k=4
                        sum = dice[combA[0]][a] + dice[combA[1]][b] + dice[combA[2]][c] + dice[combA[3]][d];
                        sum_of_diceA.push_back(sum);
                    }
                }
                else { //k=3
                    sum = dice[combA[0]][a] + dice[combA[1]][b] + dice[combA[2]][c];
                    sum_of_diceA.push_back(sum);
                }
            }
            else { //k=2
                sum = dice[combA[0]][a] + dice[combA[1]][b];
                sum_of_diceA.push_back(sum);
            }
        }
        else { //k=1
            sum = dice[combA[0]][a];
            sum_of_diceA.push_back(sum);
        }
    }
    
    vector<int> sum_of_diceB;
    for (int a = 0; a < 6; a++) {
        int sum = 0;
        if (k > 1)
            for (int b = 0; b < 6; b++) {
                if (k > 2)
                    for (int c = 0; c < 6; c++) {
                        if (k > 3)
                            for (int d = 0; d < 6; d++) {
                                if (k > 4)
                                    for (int e = 0; e < 6; e++) {
                                        sum = dice[combB[0]][a] + dice[combB[1]][b] + dice[combB[2]][c] + dice[combB[3]][d] + dice[combB[4]][e];
                                        sum_of_diceB.push_back(sum);
                                    }
                                else {
                                    sum = dice[combB[0]][a] + dice[combB[1]][b] + dice[combB[2]][c] + dice[combB[3]][d];
                                    sum_of_diceB.push_back(sum);
                                }
                            }
                        else {
                            sum = dice[combB[0]][a] + dice[combB[1]][b] + dice[combB[2]][c];
                            sum_of_diceB.push_back(sum);
                        }
                    }
                else {
                    sum = dice[combB[0]][a] + dice[combB[1]][b];
                    sum_of_diceB.push_back(sum);
                }
            }
        else {
            sum = dice[combB[0]][a];
            sum_of_diceB.push_back(sum);
        }
    }
   /* if (debug) {
        cout << "상대 덱의 숫자 경우의 수 \n";
        for (int& num : sum_of_diceB) {
            cout << num << '\n';
        }
    }*/
    //두 벡터를 정렬한 후 비교하면 보다 빠르게 비교 가능할 듯 함.    
    sort(sum_of_diceB.begin(), sum_of_diceB.end());

    for (int& num : sum_of_diceA) {
        auto lower = lower_bound(sum_of_diceB.begin(), sum_of_diceB.end(), num);
        auto upper = upper_bound(sum_of_diceB.begin(), sum_of_diceB.end(), num);

        score[Draw] += upper - lower;
        score[Win] += lower - sum_of_diceB.begin();
        score[Lose] += sum_of_diceB.end() - upper;
    }
    if (debug) {
        cout << "My pick : \n";
        for (int num : combA) {
            cout << num << " ";
        }cout << '\n';
        cout << "Win : " << score[Win] << " , Draw : " << score[Draw] << " , Lose : " << score[Lose] << '\n';
    }
    //아래와 같이 할 경우 최악의 경우 6^10으로 너무 느림.
    //int m = sum_of_diceA.size();
    //for (int i = 0; i < m; i++) {
    //    for (int j = 0; j < m; j++) {
    //        if (sum_of_diceA[i] > sum_of_diceB[j]) {
    //            score[0]++;                
    //        }
    //        else if (sum_of_diceA[i] == sum_of_diceB[j]) {
    //            score[1]++;                
    //        }
    //        else {
    //            score[2]++;                
    //        }
    //    }
    //}
 

    return score;
}

int main() {
    vector<int> answer;
    
    
    vector<vector<int>> dice1 = {
        {1, 2, 3, 4, 5, 6},
        {3, 3, 3, 3, 4, 4},
        {1, 3, 3, 4, 4, 4},
        {1, 1, 4, 4, 5, 5}
    };        
    answer = solution(dice1);
    cout << "예상 답 : [1,4], 실제 답 : " << answer[0] << " , " << answer[1] << '\n' << '\n';
    // 예상 답 [1, 4]
    
    vector<vector<int>> dice2 = {
        {1, 2, 3, 4, 5, 6},
        {2, 2, 4, 4, 6, 6}
    };
    answer = solution(dice2);
    cout << "예상 답 : [2], 실제 답 : " << answer[0] << '\n' << '\n';
    // 예상 답 	[2]

    vector<vector<int>> dice3 = {
        {40, 41, 42, 43, 44, 45}, 
        {43, 43, 42, 42, 41, 41}, 
        {1, 1, 80, 80, 80, 80}, 
        {70, 70, 1, 1, 70, 70}
    };
    answer = solution(dice3);
    cout << "예상 답 : [1,3], 실제 답 : " << answer[0] << " , " << answer[1] << '\n' << '\n';
    // 예상 답 [1, 3]

    //vector<vector<int>> dice4 = {
    //   {40, 41, 42, 43, 44, 45},
    //   {43, 43, 42, 42, 41, 41},
    //   {1, 1, 80, 80, 80, 80},
    //   {40, 41, 42, 43, 44, 45},
    //   {43, 43, 42, 42, 41, 41},
    //   {1, 1, 80, 80, 80, 80},
    //   {40, 41, 42, 43, 44, 45},
    //   {43, 43, 42, 42, 41, 41},
    //   {1, 1, 80, 80, 80, 80},
    //   {70, 70, 1, 1, 70, 70}
    //};
    //answer = solution(dice4);
    //cout << "예상 답 : [없음], 실제 답 : " << answer[0] << " , " << answer[1] << '\n' << '\n';
    //// 시간 테스트 용

    return 0;
}