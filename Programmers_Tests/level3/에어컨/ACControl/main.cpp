#include <string>
#include <vector>
#include <iostream>

using namespace std;
void Search(vector<int>& onboard, int idx, int consumption, int cur_temp, vector<vector<int>>& Consumption, vector<int>& setting, int& answer) {
    
    if (idx == onboard.size()) {
        answer = min(consumption, answer);
        return;
    }
    if (onboard[idx] && (cur_temp<setting[1] || cur_temp >setting[2])) return;
    if (Consumption[idx][cur_temp] <= consumption) return;
    Consumption[idx][cur_temp] = consumption;
   
    
    // 끄기
    Search(onboard, idx + 1, consumption, min(setting[0], cur_temp + 1), Consumption, setting, answer);
    // 유지 운전
    if(setting[4]<=setting[3])
    Search(onboard, idx + 1, consumption + setting[4], cur_temp, Consumption, setting, answer);
    // 운전
    Search(onboard, idx + 1, consumption + setting[3], max(setting[1], cur_temp - 1), Consumption, setting, answer);
    
}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
 
    int answer = 10000000;
    vector<vector<int>> Consumption(1001, vector<int>(51, 10000000));
    
    int OA_temp = temperature;
    if (OA_temp < t1) OA_temp = t2 + (t1 - temperature);
    vector<int> setting = { OA_temp, t1, t2, a, b };

    Search(onboard, 0, 0, OA_temp, Consumption, setting, answer);
    
    return answer;
}


int main() {

    int temperature; // 실외 온도 (-10~40)
    int t1, t2; // 실내 온도 범위 (-10~40, temperature는 t1, t2 범위 밖)
    int a, b; // 에어컨 소비 전력
    vector<int> onboard; // 승객이 탑승 중인 시간을 나타내는 배열 (2<= 배열 길이 <= 1000)

    temperature = 28;
    t1 = 18;
    t2 = 26;
    a = 10;
    b = 8;
    onboard = { 0,0,1,1,1,1,1, 0, 0, 0 };
    cout << "기대 값 40, 계산 값 : " << solution(temperature, t1, t2, a, b, onboard) << '\n';
    

    temperature = -10;
    t1 = -5;
    t2 = 5;
    a = 5;
    b = 1;
    onboard = { 0, 0, 0, 0, 0, 1, 0 };
    cout << "기대 값 25, 계산 값 : " << solution(temperature, t1, t2, a, b, onboard) << '\n';
    

    temperature = 11;
    t1 = 8;
    t2 = 10;
    a = 10;
    b = 1;
    onboard = { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1 };
    cout << "기대 값 20, 계산 값 : " << solution(temperature, t1, t2, a, b, onboard) << '\n';

    temperature = 11;
    t1 = 8;
    t2 = 10;
    a = 10;
    b = 100;
    onboard = { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0};
    cout << "기대 값 60, 계산 값 : " << solution(temperature, t1, t2, a, b, onboard) << '\n';

    temperature = 13;
    t1 = 8;
    t2 = 10;
    a = 10;
    b = 6;
    onboard = { 0,0,0,0, 1, 1, 1, 1, 0, 1, 0 };
    cout << "기대 값 56, 계산 값 : " << solution(temperature, t1, t2, a, b, onboard) << '\n';

    temperature = 11;
    t1 = 8;
    t2 = 10;
    a = 10;
    b = 100;
    onboard.clear();
    onboard.push_back(0);
    for (int i = 0; i < 1000; i++) {
        int random_no = rand() % 2;
        onboard.push_back(random_no);
    }   
    
    cout << "이 케이스는 연산 속도를 확인하기 위함이다. 닶 : " << solution(temperature, t1, t2, a, b, onboard) << '\n';
    

    return 0;
}

