#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 0;
    if (scores.size() == 1) return 1;
    sort(scores.begin() + 1, scores.end()); // 원호 제외 오름차순 정렬


    int myscore = scores[0][0] + scores[0][1];
    //원호보다 낮거나 같은 점수는 다 삭제 시키면 된다. (원호 및 상위권 과락과 등수에 영향 안줌)    
    for (auto iter = scores.begin() + 1; iter != scores.end(); ) {        
        if ((*iter)[0] + (*iter)[1] <= myscore)        
            iter = scores.erase(iter);   
        else 
            iter++;
    }

    //원호가 인센 못받는 경우    
    for (int i = 1; i < scores.size(); i++) {                
        if (scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1]) return -1;
    }    

    //인센 못받는 사람들 제외시키기
    for (int i = scores.size() - 1; i >= 1; i--) {        
        for (auto iter = scores.begin()+1; iter != scores.end(); ) {           
            if ((*iter)[0] == scores[i][0]) {
                i = iter - scores.begin();
                break;
            }
            else if ((*iter)[0] > scores[i][0]) cout << "Error Occur! \n";
            else if ((*iter)[1] < scores[i][1]) {
                iter = scores.erase(iter);               
                i--;
            }
            else {
                iter++;
            }
        }
        if (i<=2) break;
    }
   
    vector<int> scores_sum;
    for (vector<int> score : scores) {
        scores_sum.push_back(score[0] + score[1]);
    }
    sort(scores_sum.begin(), scores_sum.end(), greater<>());
    answer = find(scores_sum.begin(), scores_sum.end(), myscore) - scores_sum.begin() + 1;

    return answer;
}

int main() {
    vector<vector<int>> scores;
    //1 ≤ scores의 길이 ≤ 100,000 

    scores = {{2, 7}, {1, 4}, {3, 2}, {3, 1}, {2, 1},
                {2, 2}, {5, 1}, {3, 4}, {1, 9}, {7, 2} };
    cout << "예상 등수 : 2, 계산 값 : " << solution(scores) << '\n';

    scores = { {4, 2}, {1, 8}, {7, 2}, {3, 2}, {2, 1},
                {2, 2}, {1, 4}, {3, 2}, {6, 1}, {2, 1} };
    cout << "예상 등수 : 3, 계산 값 : " << solution(scores) << '\n';

    scores = { {2, 2}};
    cout << "사이즈가 1인 경우 : " << solution(scores) << '\n';

    scores = { {2, 2}, {1, 4}, {3, 2}, {3, 2}, {2, 1}, 
                {2, 2}, {1, 4}, {3, 2}, {3, 3}, {2, 1} };
    cout << "인센 못받는 경우 : " << solution(scores) << '\n';


    scores.clear();
    scores.push_back({ 80000,80000 });
    for (int i = 1; i < 1000; i++) {
        vector<int> score(2);
        score[0] = rand() % 100000;
        score[1] = rand() % 100000;
        scores.push_back(score);
    }
    cout << "시간 테스트 : " << solution(scores) << '\n';

    return 0;

}