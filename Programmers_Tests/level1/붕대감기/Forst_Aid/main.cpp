#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;

    int last_attack_time = attacks[attacks.size() - 1][0];
    
    int* HOT = new int[last_attack_time + 1]; //health over time    
    HOT[0] = health;
    int continous_heal = 0;
    bool attacked = false;
    int attack_damage = 0;
    int attack_point = 0;


    for (int i = 1; i < last_attack_time + 1; i++) {
        HOT[i] = HOT[i - 1];

        if (i == attacks[attack_point][0]) {
                attacked = true;
                attack_damage = attacks[attack_point][1];
                attack_point++;
            }
        

        if (!attacked) {//공격을 안받으면 붕대 힐, 연속성공 +1
            HOT[i] += bandage[1];
            if (++continous_heal == bandage[0]) {//풀타임 연속성공이면 추가힐
                HOT[i] += bandage[2];
                continous_heal = 0;
            }
        }
        if (attacked) {    //공격을 받으면 연속성공 초기화, 힐X, 데미지
            HOT[i] -= attack_damage;
            continous_heal = 0;
        }

        attacked = false;

        if (HOT[i] > health) 
            HOT[i] = health;   //체력이 max 이상이면 max로 고정
        if (HOT[i] <= 0) return -1;             //체력이 0 이하면 -1 리턴
    }

    answer = HOT[last_attack_time];

    delete[] HOT;
    return answer;
}


int main() {
    vector<int> bandage1 = { 5,1,5 }; // 시전시간, 초당 회복량, 추가 회복량
    int health1 = 30; // 최대 체력
    vector<vector<int>> attacks1 = { {2, 10},{9, 15},{10, 5}, {11, 5} }; // 몬스터 공격 시간 및 피해량

    int answer1 = solution(bandage1, health1, attacks1);

    cout << answer1 << '\n'; // 기대값 5


    vector<int> bandage2 = { 3, 2, 7 };
    int health2 = 20;
    vector<vector<int>> attacks2 = { {1,15},{5,16},{8,6} };

    int answer2 = solution(bandage2, health2, attacks2);

    cout << answer2 << '\n'; // 기대값 -1


    vector<int> bandage3 = { 4,2,7 };
    int health3 = 20;
    vector<vector<int>> attacks3 = { {1,15},{5,16},{8,6} };

    int answer3 = solution(bandage3, health3, attacks3);

    cout << answer3 << '\n'; // 기대값 -1


    vector<int> bandage4 = { 1,1,1 };
    int health4 = 5;
    vector<vector<int>> attacks4 = { {1,2},{3,2} };

    int answer4 = solution(bandage4, health4, attacks4);

    cout << answer4 << '\n'; // 기대값 3


    return 0;
}
