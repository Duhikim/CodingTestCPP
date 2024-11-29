#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, double> failRate;

double getFailRate(int num, vector<int>& stages) {
    double a = 0, b = 0; // a는 n의 개수, b는 n이상인 수의 개수
    for (int stage : stages) {
        if (stage == num) a++;
        if (stage >= num) b++;
    }
    return (b != 0) ? a / b : 0;
}

vector<int> solution(int N, vector<int> stages) {
    

    for (int i = 1; i <= N; i++) {
        failRate.insert({ i, getFailRate(i, stages) });        
    }
    vector<int> answer(N);
    for (int i = 0; i < N; i++) {
        answer[i] = i + 1;
    }
    
    sort(answer.begin(), answer.end(), [](int a, int b) -> bool {
        if (failRate[a] > failRate[b]) return true;
        else if (failRate[a] == failRate[b]) return a < b;
        else return false;
        });  
    
    return answer;
}