#include <string>
#include <vector>
#include <set>
#include <iostream>

bool debug = true;
             //false;

using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 0;
    int n = cards.size();
    int target = n + 1;
    int life = 0;
    int round = 0;

    set<int> mycards;
    set<int> keep;

    for (int i = 0; i < n / 3; i++) {
        mycards.insert(cards[0]);
        cards.erase(cards.begin());
    }    
    for (auto iter = mycards.begin(); iter != mycards.end();iter++) {        
        if (mycards.find(target - *iter) != mycards.end()) {
            mycards.erase(mycards.find(target - *iter));
            iter = mycards.erase(iter);
            if (iter != mycards.begin())iter--;            
            life++;
            if (!mycards.size()) break;
        }
    }
    if (debug) {
        cout << "시작 카드 : ";
        for (int num : mycards) cout  << num << "  ";
        cout << '\n' << "life : " << life << "\n\n";
    }

    do{
        if(round) life--;
        round++;

        if (debug) {
            cout << "라운드 " << round << " 시작" << '\n';
            cout << "남은 목숨 : " << life << "  남은 코인 : " << coin << "  남은 카드 수 : " << cards.size() << '\n';
            cout << "손 덱 : ";
            for (int num : mycards) cout << num << " ";
            cout << '\n';
            cout << "Keep : ";
            for (int num : keep) cout << num << " ";
            cout << '\n';
            if(cards.size()>1) cout << "다음 카드 : " << cards[0] << " , " << cards[1] << "\n\n";
        }

        if (!cards.size()) break;
        
        if (coin) {
            if (mycards.find(target - cards[0]) != mycards.end()) {
                mycards.erase(mycards.find(target - cards[0]));
                coin--;
                life++;
            }
            else { keep.insert(cards[0]); }
        }

        if (coin) {
            if (mycards.find(target - cards[1]) != mycards.end()) {
                mycards.erase(mycards.find(target - cards[1]));
                coin--;
                life++;
            }
            else { keep.insert(cards[1]); }
        }

        if (cards.size() && !life && coin>1) {            
            for (auto iter = keep.begin(); iter != keep.end(); iter++) {
                if (keep.find(target - *iter) != keep.end()) {
                    keep.erase(keep.find(target - *iter));
                    iter = keep.erase(iter);
                    if (iter != keep.begin())iter--;
                    life++;
                    coin -= 2;  
                    break;
                }                
                if (coin<2) break;
            }
        }
        cards.erase(cards.begin(), cards.begin() + 2);
        
    } while (life);
        
    if (debug) {
        cout << "----최종 결과----\n라운드 " << round << '\n';
        cout << "남은 목숨 : " << life << "  남은 코인 : " << coin << "  남은 카드 수 : " << cards.size() << '\n';
        cout << "손 덱 : ";
        for (int num : mycards) cout << num << " ";
        cout << '\n';
    }

    answer = round;
    return answer;
}




int main() {
   /* int coin1 = 4;
    vector<int> cards1 = { 3, 6, 7, 2, 1, 10, 5, 9, 8, 12, 11, 4 };
    cout << "예상 답 : 5, 실제 닶 : "<<solution(coin1, cards1) << '\n';

    int coin2 = 3;
    vector<int> cards2 = { 1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11, 12 };
    cout << "예상 답 : 2, 실제 닶 : " << solution(coin2, cards2) << '\n';

    int coin3 = 2;
    vector<int> cards3 = { 5, 8, 1, 2, 9, 4, 12, 11, 3, 10, 6, 7 };
    cout << "예상 답 : 4, 실제 닶 : " << solution(coin3, cards3) << '\n';

    int coin4 = 10;
    vector<int> cards4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    cout << "예상 답 : 1, 실제 닶 : " << solution(coin4, cards4) << '\n';*/

   /* int coin5 = 996;
    vector<int> cards5(996);
    for (int i = 0; i < 996; i++) {
        cards5[i] = i;
    }
    cout << "이 문제는 시간 체크 용으로 만들어 졌습니다. 답 : " << solution(coin5, cards5) << '\n';*/
    
    int coin6 = 60;
    vector<int> cards6(60);
    for (int i = 0; i < 59; i += 2) {
        cards6[i] = i+1;
        cards6[i+1] = 60-i;
    }
    cout << "예상 답 : 21, 실제 답 : " << solution(coin6, cards6) << '\n';

    return 0;
}