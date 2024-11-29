#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long get_time(const vector<int>& diffs, const vector<int>& times, int lv) {
    long long time_tot = times[0];

    for (int i = 1; i < diffs.size(); i++) {
        if (lv >= diffs[i]) 
        {            
            time_tot += times[i];
        }
        else 
        {            
            time_tot += (diffs[i] - lv) * (times[i - 1] + times[i]) + times[i];
        }
    }
    cout << time_tot << '\n';
    return time_tot;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {   
    if (diffs.size() == 1) return 1; // 길이가 1인 경우 그대로 리턴.

    int max = *max_element(diffs.begin(), diffs.end()); // 최대 난이도
        
    /*
    // 1부터 최대난이도까지 레벨을 올려가며 시간 측정. limit 안으로 들어오는순간 해당 index=레벨을 리턴.
        for (int i = 1; i <= max; i++)
        {
            if (get_time(diffs, times, i) <= limit)
            {
                // cout << i << '\n';
                return i;
            }
        }
     */ //이 방법으로 했더니 시간이 좀 많이 걸림. 절반씩 UP/DOWN하는 식으로 하자.
    
    int largest_lv = max, smallest_lv = 1;    
    int mid_lv;
    while (largest_lv - smallest_lv > 1) {
        mid_lv = (largest_lv + smallest_lv) / 2;
        long long time_temp = get_time(diffs, times, mid_lv);
        if (time_temp == limit) 
            return mid_lv;
        else if (time_temp > limit)
        {
            smallest_lv = mid_lv;
        }
        else
        {            
            largest_lv = mid_lv;
        }
    }
    return (get_time(diffs, times, smallest_lv) > limit)? largest_lv : smallest_lv;
}

int main() {
    vector<int> diffs;
    vector<int> times;
    long long limit;
    int expected;
    int calculated;

    //1번 테케
    diffs = {1, 5, 3};
    times = {2, 4, 7};
    limit = 30;
    expected = 3;
    calculated = solution(diffs, times, limit);
    if (calculated == expected) cout << "정답" << '\n';
    else cout << "오답" << '\n';

    //2번 테케
    diffs = {1, 4, 4, 2};
    times = {6, 3, 8, 2};
    limit = 59;
    expected = 2;
    calculated = solution(diffs, times, limit);
    if (calculated == expected) cout << "정답" << '\n';
    else cout << "오답" << '\n';

    //3번 테케
    diffs = {1, 328, 467, 209, 54};
    times = {2, 7, 1, 4, 3};
    limit = 1723;
    expected = 294;
    calculated = solution(diffs, times, limit);
    if (calculated == expected) cout << "정답" << '\n';
    else cout << "오답" << '\n';

    //4번 테케
    diffs = {1, 99999, 100000, 99995};
    times = {9999, 9001, 9999, 9001};
    limit = 3456789012;
    expected = 39354;
    calculated = solution(diffs, times, limit);    
    if (calculated == expected) cout << "정답" << '\n';
    else cout << "오답" << '\n';    

    //시간 테스트
    vector<int> diffs_big(300000, 100000);
    diffs_big[0] = 1;
    vector<int> times_big(300000, 10);
    
    long long limit_big = 1000000;
    
    
    solution(diffs, times, limit);
    cout << "계산 끝" << '\n';


    return 0;
}